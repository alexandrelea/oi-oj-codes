/* Ktx-65 Assembly Language Interpreter */
/* Ktx-65 汇编语言解释器 */
/* Copyright (c) Kawasiro Nitori & Moriya Suwano of Kappa Heavy Industries Co.,Ltd. */
/* 版权所有 河童重工业会社 河城荷取 洩矢诹访子 */

/* 版本：审议稿 */
/* 平成三十年 八月 十一日 */


#include <cstdlib>
#include <iostream>
#include <stack>
#include <functional>
#include <map>
#include <vector>
#include <initializer_list>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;


bool compileErrorLevel = false;
void compileError(int line, string message) {
    // TODO Compile Error
    cout << "[ERROR] Interpreter encountered a Compile Error on line " << line << endl;
    cout << "    Message: " << message << endl;
    compileErrorLevel = true;
}

#define compileAssert(line, statement, message) \
(!!(statement) || [](int l, string state, string m)->bool {compileError(l, "Compile Assertation Failed: " + m + ", Statement: " + state); return false; }(line, #statement, message))

void toupper(string& str) { for (char& c : str)c = toupper(c); }
string touppers(const string& str) { string a = str; toupper(a); return a; }

class AssemblyProgram {
public:

    enum Command {
        Undefined = 0,  // Undefined
        Halt = 1,       // Stops the program
        NoOp,           // Does nothing
        // Memory Access
        Set,            // Read value from <0> into <1>
        // Streamline control
        Jump,           // Jump to <0>(absolute line number, begins from 1)
        JumpIf,         // Jump to <0> if <1> is not zero (takes rFlag if <1> doesn't exist)
        Call,           // push current linenum+1 to sAddr and jump to <0>(begins from 1)
        Return,         // jump to sAddr.top() and sAddr.pop()
        // Arithmetic operations
        // rVal if not exist↓
        Inverse,        // <1> = -<0>
        Add,            // <2> = <0> + <1>
        Minus,          // <2> = <0> - <1>
        Multiply,       // <2> = <0> * <1>
        IntDivide,      // <2> = <0> / <1>
        Modulo,         // <2> = <0> % <1>
        LeftShift,      // <2> = <0> << <1>
        RightShift,     // <2> = <0> >> <1>
        BitAnd,         // <2> = <0> & <1>
        BitOr,          // <2> = <0> | <1>
        BitXor,         // <2> = <0> ^ <1>
        // Logical Operations
        // rFlag if not exist↓
        Greater,        //  <2> = <0> > <1>
        Less,           //  <2> = <0> < <1>
        GreaterEqual,   //  <2> = <0> >= <1>
        LessEqual,      //  <2> = <0> <= <1>
        Equal,          //  <2> = <0> == <1>
        LogicalAnd,     //  <2> = <0> && <1>
        LogicalOr,      //  <2> = <0> || <1>
        // Console I/O
        //        rVal if not exist ¡ý
        ReadInt,        //  cin >> <0>
        ReadChar,       // getchar(<0>)
        WriteInt,       // cout << <0>
        WriteChar,      // putchar(<0>)
        // Keep at last - command count
        CommandCount
    };

    enum VariableType {
        Constant,
        Pointer,
        Memory
    };

    struct DataSource {
        int* valptr;
        int valconst;
        int* valmemidptr;
        AssemblyProgram* prog;
        VariableType type;
        int& operator ()() {
            if (type == Constant)
                return valconst;
            else if (type == Pointer)
                return *valptr;
            else {
                int id = *valmemidptr;
                if (id >= memsize || id < 0) {
                    prog->runtimeError("Memory acess out of range");
                    valconst = 0;
                    return valconst;
                }
                return prog->mem[id];
            }
        }
    };

    void halt() {
        // TODO Halt
        running = false;
    }

    void runtimeError(string message) {
        // TODO Runtime Error
        cout << "[ERROR] Interpreter encountered a Runtime Error on instruction " << nextptr + 1 << ", clock cycle " << clockCounter << endl;
        cout << "    Message: " << message << endl;
        running = false;
    }

private:
    // Exception-Safe Wrappers
    void pushAddr(int val) { if (sAddr.size() >= stackSize)runtimeError("sAddr Stack Overflow"); sAddr.push(val); }
    int topAddr() { if (sAddr.size() <= 0) { runtimeError("sAddr Access Error(size = 0)"); return 0; } else return sAddr.top(); }
    void popAddr() { if (sAddr.size() <= 0)runtimeError("sAddr Stack Underflow"); else sAddr.pop(); }
    int popAddrRet() { if (sAddr.size() <= 0) { runtimeError("sAddr Stack Underflow"); return 0; } else { int val = sAddr.top(); sAddr.pop(); return val; } }
    int readMem(int id) { if (id >= memsize || id < 0) { runtimeError("Memory Access Error(Read)"); return 0; } else return mem[id]; }
    void writeMem(int id, int val) { if (id >= memsize || id < 0)runtimeError("Memory Access Error(Write)"); else mem[id] = val; }
    int lineProgramId(int line) { auto i = commandLines.find(line); if (i == commandLines.end()) { runtimeError("Jump Line Number Invalid"); return 0; } else return i->second; }

private:
    // Command Handlers
    void funcSet(vector<DataSource>& l) { l[1]() = l[0](); nextptr++; }
    void funcJmp(vector<DataSource>& l) { nextptr = lineProgramId(l[0]() + rLine); }
    void funcJIf(vector<DataSource>& l) { if (l.size() <= 1) { if (rFlag)nextptr = l[0]() + lineProgramId(rLine); else nextptr++; } else { if (l[1]())nextptr = l[0]() + lineProgramId(rLine); else nextptr++; } }
    void funcCall(vector<DataSource>& l) { pushAddr(rLine); pushAddr(nextptr + 1); nextptr = lineProgramId(l[0]()); }
    void funcRet(vector<DataSource>& l) { if (l.size() > 0)rRet = l[0](); nextptr = popAddrRet(); rLine = popAddrRet(); }
    void funcInv(vector<DataSource>& l) { int* p;  if (l.size() <= 1)p = &rVal; else p = &l[1](); (*p) = -l[0](); nextptr++; }
    void funcAdd(vector<DataSource>& l) { int* p;  if (l.size() <= 2)p = &rVal; else p = &l[2](); (*p) = l[0]() + l[1](); nextptr++; }
    void funcSub(vector<DataSource>& l) { int* p;  if (l.size() <= 2)p = &rVal; else p = &l[2](); (*p) = l[0]() - l[1](); nextptr++; }
    void funcMult(vector<DataSource>& l) { int* p; if (l.size() <= 2)p = &rVal; else p = &l[2](); (*p) = l[0]() * l[1](); nextptr++; }
    void funcIDiv(vector<DataSource>& l) { int* p; if (l.size() <= 2)p = &rVal; else p = &l[2](); (*p) = l[0]() / l[1](); nextptr++; }
    void funcMod(vector<DataSource>& l) { int* p;  if (l.size() <= 2)p = &rVal; else p = &l[2](); (*p) = l[0]() % l[1](); nextptr++; }
    void funcLSft(vector<DataSource>& l) { int* p; if (l.size() <= 2)p = &rVal; else p = &l[2](); (*p) = l[0]() << l[1](); nextptr++; }
    void funcRSft(vector<DataSource>& l) { int* p; if (l.size() <= 2)p = &rVal; else p = &l[2](); (*p) = l[0]() >> l[1](); nextptr++; }
    void funcBAnd(vector<DataSource>& l) { int* p; if (l.size() <= 2)p = &rVal; else p = &l[2](); (*p) = l[0]() & l[1](); nextptr++; }
    void funcBOr(vector<DataSource>& l) { int* p;  if (l.size() <= 2)p = &rVal; else p = &l[2](); (*p) = l[0]() | l[1](); nextptr++; }
    void funcBXor(vector<DataSource>& l) { int* p; if (l.size() <= 2)p = &rVal; else p = &l[2](); (*p) = l[0]() ^ l[1](); nextptr++; }
    void funcLGr(vector<DataSource>& l) { int* p;  if (l.size() <= 2)p = &rFlag; else p = &l[2](); (*p) = l[0]() > l[1](); nextptr++; }
    void funcLLs(vector<DataSource>& l) { int* p;  if (l.size() <= 2)p = &rFlag; else p = &l[2](); (*p) = l[0]() < l[1](); nextptr++; }
    void funcLGE(vector<DataSource>& l) { int* p;  if (l.size() <= 2)p = &rFlag; else p = &l[2](); (*p) = l[0]() >= l[1](); nextptr++; }
    void funcLLE(vector<DataSource>& l) { int* p;  if (l.size() <= 2)p = &rFlag; else p = &l[2](); (*p) = l[0]() <= l[1](); nextptr++; }
    void funcLEql(vector<DataSource>& l) { int* p; if (l.size() <= 2)p = &rFlag; else p = &l[2](); (*p) = l[0]() == l[1](); nextptr++; }
    void funcLAnd(vector<DataSource>& l) { int* p; if (l.size() <= 2)p = &rFlag; else p = &l[2](); (*p) = l[0]() && l[1](); nextptr++; }
    void funcLOr(vector<DataSource>& l) { int* p;  if (l.size() <= 2)p = &rFlag; else p = &l[2](); (*p) = l[0]() || l[1](); nextptr++; }
    void funcRInt(vector<DataSource>& l) { if (l.size() <= 0)cin >> rVal; else cin >> l[0](); nextptr++; }
    void funcRCh(vector<DataSource>& l) { if (l.size() <= 0)rVal = getchar(); else l[0]() = getchar(); nextptr++; }
    void funcWInt(vector<DataSource>& l) { if (l.size() <= 0)cout << rVal; else cout << l[0](); nextptr++; }
    void funcWCh(vector<DataSource>& l) { if (l.size() <= 0)putchar(rVal); else putchar(l[0]()); nextptr++; }

public:
    void initalaize() {
#define REGISTER_RAW(command, name) \
commands[name] = command; names[command] = name
#define REGISTER_HANDLER(command, handler, minParamCount, name)    \
handlers[command] = [this](vector<DataSource>& l) {if (l.size() < minParamCount)runtimeError("Paramater Count Mismatch"); else handler(l); }; \
/*handlers[command] = bind(&AssemblyProgram::handler, this, placeholders::_1);*/ \
commands[name] = command; names[command] = name
        REGISTER_RAW(Undefined, "UDEF");
        handlers[Undefined] = [this](vector<DataSource>&) { runtimeError("Undefined Command Called"); };
        REGISTER_RAW(Halt, "HLT");
        handlers[Halt] = [this](vector<DataSource>&) { halt(); };
        REGISTER_RAW(NoOp, "NOP");
        handlers[NoOp] = [this](vector<DataSource>&) {};
        REGISTER_HANDLER(Set, funcSet, 2, "SET");
        REGISTER_HANDLER(Jump, funcJmp, 1, "JMP");
        REGISTER_HANDLER(JumpIf, funcJIf, 1, "JIF");
        REGISTER_HANDLER(Call, funcCall, 1, "CALL");
        REGISTER_HANDLER(Return, funcRet, 0, "RET");
        REGISTER_HANDLER(Inverse, funcInv, 1, "INV");
        REGISTER_HANDLER(Add, funcAdd, 2, "ADD");
        REGISTER_HANDLER(Minus, funcSub, 2, "SUB");
        REGISTER_HANDLER(Multiply, funcMult, 2, "MULT");
        REGISTER_HANDLER(IntDivide, funcIDiv, 2, "IDIV");
        REGISTER_HANDLER(Modulo, funcMod, 2, "MOD");
        REGISTER_HANDLER(LeftShift, funcLSft, 2, "LSFT");
        REGISTER_HANDLER(RightShift, funcRSft, 2, "RSFT");
        REGISTER_HANDLER(BitAnd, funcBAnd, 2, "BAND");
        REGISTER_HANDLER(BitOr, funcBOr, 2, "BOR");
        REGISTER_HANDLER(BitXor, funcBXor, 2, "BXOR");
        REGISTER_HANDLER(Greater, funcLGr, 2, "LGR");
        REGISTER_HANDLER(Less, funcLLs, 2, "LLS");
        REGISTER_HANDLER(GreaterEqual, funcLGE, 2, "LGE");
        REGISTER_HANDLER(LessEqual, funcLLE, 2, "LLE");
        REGISTER_HANDLER(Equal, funcLEql, 2, "LEQL");
        REGISTER_HANDLER(LogicalAnd, funcLAnd, 2, "LAND");
        REGISTER_HANDLER(LogicalOr, funcLOr, 2, "LOR");
        REGISTER_HANDLER(ReadInt, funcRInt, 0, "RINT");
        REGISTER_HANDLER(ReadChar, funcRCh, 0, "RCH");
        REGISTER_HANDLER(WriteInt, funcWInt, 0, "WINT");
        REGISTER_HANDLER(WriteChar, funcWCh, 0, "WCH");
#undef REGISTER_RAW
#undef REGISTER_HANDLER
        program.clear();
        nextptr = 0;
    }

    bool pushCommand(int fileline, string name, vector<DataSource> param) {
        toupper(name);
        auto i = commands.find(name);
        if (i == commands.end()) {
            compileError(fileline, "Invaild command \"" + name + "\"");
            return false;
        }
        else {
            program.push_back(make_pair(i->second, param));
            if (commandLines.find(fileline) == commandLines.end())
                commandLines[fileline] = program.size() - 1;
            return true;
        }
    }

    int* getRegister(int fileline, string name) {
        toupper(name);
        if (name == "R1")
            return &rR1;
        else if (name == "R2")
            return &rR2;
        else if (name == "R3")
            return &rR3;
        else if (name == "R4")
            return &rR4;
        else if (name == "E1")
            return &rE1;
        else if (name == "E2")
            return &rE2;
        else if (name == "E3")
            return &rE3;
        else if (name == "E4")
            return &rE4;
        else if (name == "FLAG")
            return &rFlag;
        else if (name == "VAL")
            return &rVal;
        else if (name == "RET")
            return &rRet;
        else if (name == "LINE")
            return &rLine;
        else {
            compileError(fileline, "Invaild register name \"" + name + '\"');
            return nullptr;
        }
    }

    int* getMemory(int fileline, int id) {
        if (id >= memsize || id < 0) {
            compileError(fileline, "Memory access statically out of range");
            return 0;
        }
        else return mem + id;
    }

    void run() {
        rR1 = rR2 = rR3 = rR4 = rE1 = rE2 = rE3 = rE4 = rFlag = rVal = rRet = rLine = 0;
        memset(mem, 0, sizeof(mem));
        while (!sAddr.empty())
            sAddr.pop();

        clockCounter = 0;
        nextptr = 0;
        running = true;
        while (running) {
            if (nextptr >= program.size() || nextptr < 0)
                runtimeError("Program Pointer Invaild");
            else
                handlers[program[nextptr].first](program[nextptr].second);
            clockCounter++;
        }
    }

    int getClock() { return clockCounter; }

    bool valid;
private:

    friend class Compiler;

    int rR1, rR2, rR3, rR4;
    int rE1, rE2, rE3, rE4;
    int rFlag, rVal, rRet, rLine;
    static constexpr int stackSize = 512 * 1024;
    stack<int> /*sVal,*/ sAddr;

    vector<pair<Command, vector<DataSource>>> program;
    int nextptr;
    static constexpr int memsize = 16 * 1024 * 1024;
    int mem[memsize];

    int clockCounter;
    bool running;

    function<void(vector<DataSource>&)> handlers[CommandCount];
    map<int, int> commandLines;
    map<string, Command> commands;
    string names[CommandCount];
};


class Tokenizer {
public:
    enum Type {
        Unknown,
        Identifier,
        Number,
        Symbol
    };

    struct Token {
        Type type;
        string word;
        int line;
    };

    static vector<Token> parse(const string& str) {
        vector<Token> tokens;
        Token buffer{ Unknown, "", 1 };
        int commentLayers = 0;
        int curline = 1;
        for (char c : str) {
            if (c == '[')
                commentLayers++;
            else if (c == ']') {
                if (commentLayers > 0)
                    commentLayers--;
            }
            else if (commentLayers <= 0) {
                if (!(isblank(c) || iscntrl(c) || c == ',')) {
                    if ((buffer.type == Number && !isdigit(c)) ||
                        (buffer.type == Identifier && (!isalnum(c) && c != '_')) ||
                        (buffer.type == Symbol && (isalnum(c) || c == '_' || c == '-'))) {
                        buffer.line = curline;
                        tokens.push_back(buffer);
                        buffer = Token{ Unknown, "" };
                    }
                    if (buffer.type == Unknown) {
                        // Check new object type
                        if (isalpha(c) || c == '_')
                            buffer.type = Identifier;
                        else if (isdigit(c) || c == '-')
                            buffer.type = Number;
                        else
                            buffer.type = Symbol;
                    }
                    buffer.word.push_back(c);
                }
                else {
                    if (buffer.type != Unknown) {
                        buffer.line = curline;
                        tokens.push_back(buffer);
                        buffer = Token{ Unknown, "" };
                    }
                }
            }
            if (c == '\n')
                curline++;
        }
        if (buffer.type != Unknown) {
            buffer.line = curline;
            tokens.push_back(buffer);
            buffer = Token{ Unknown, "" };
        }
        return tokens;
    }

    void parseTotal(string total) {
        tokens = parse(total);
        nextid = 0;
    }

    void parse(istream& in) {
        int c;
        string str;
        while (c = in.get()) {
            if (in.eof())
                break;
            str.push_back(c);
        }
        parseTotal(str);
    }

    Token next() {
        if (nextid >= tokens.size())
            return Token{ Unknown, "" };
        else
            return tokens[nextid++];
    }

    Token offset(int offset) {
        int id = nextid - 1 + offset;
        if (id >= tokens.size() || id < 1)
            return Token{ Unknown };
        else
            return tokens[id];
    }

private:
    vector<Token> tokens;
    int nextid;
};

/*
Basic Syntax
COMMAND %Register @Address Value @%AddrAtRegister;
*/
class Compiler {
public:

    struct Command {
        int line;
        string command;
        vector<Tokenizer::Token> sources;
    };


    void compile(Tokenizer& tokens) {
        valid = false;
        bool ok = true;
        while (ok) {
            Tokenizer::Token commt;
            while (ok && (commt = tokens.next()).type != Tokenizer::Identifier)
                if (commt.type == Tokenizer::Unknown)
                    ok = false;
            string command = commt.word;
            vector<Tokenizer::Token> sources;
            Tokenizer::Token cur;
            bool pushCommand = true;
            while (ok && (cur = tokens.next()).word != ";") {
                if (cur.type == Tokenizer::Unknown)
                    ok = false;
                //if (cur.type == Tokenizer::Identifier&&tokens.offset(-1).type != Tokenizer::Symbol)
                //    compileError(cur.line, "\";\" expected before a new identifier");
                else if (cur.type == Tokenizer::Symbol&&cur.word == "$"&&touppers(command) == "FUNCTION") {
                    Tokenizer::Token func = tokens.next();
                    compileAssert(func.line, func.type == Tokenizer::Identifier, "\"function $\" not followed by a identifier as function name");
                    compileAssert(func.line, funcStartLines.find(func.word) == funcStartLines.end(), "Redefinition of function \"" + func.word + "\"");
                    funcStartLines.insert(make_pair(func.word, commt.line));

                    auto vec = Tokenizer::parse("#LINE %LINE");
                    for (auto& i : vec) { i.line = commt.line; }
                    commands.push_back(Command{ commt.line, "SET", vec });
                    pushCommand = false;
                }
                sources.push_back(cur);
            }
            if (compileErrorLevel)
                break;
            if (ok&&pushCommand)
                commands.push_back(Command{ commt.line, command, sources });
        }
        if (compileErrorLevel) {
            compileErrorLevel = false;
            valid = false;
        }
        else
            valid = true;
    }

    void generateCode(AssemblyProgram& prog) {
        if (!valid)
            return;
        prog.initalaize();
        prog.valid = false;

        bool ok = true;

        for (auto i = commands.begin(); ok&&i != commands.end(); i++) {
            string& command = i->command;
            vector<AssemblyProgram::DataSource> sources;
            bool pushCommand = true;

            auto j = i->sources.begin();
            auto nextToken = [&]()->Tokenizer::Token {
                j++;
                if (j == i->sources.end())
                    return Tokenizer::Token{ Tokenizer::Unknown };
                else
                    return *j;
            };
            for (; ok&&j != i->sources.end(); nextToken()) {
                auto& cur = *j;
                if (cur.type == Tokenizer::Number)
                    sources.push_back(AssemblyProgram::DataSource{ nullptr, atoi(cur.word.c_str()), nullptr, nullptr, AssemblyProgram::Constant });
                else if (cur.type == Tokenizer::Symbol) {
                    if (cur.word == "%") {
                        Tokenizer::Token reg = nextToken();
                        compileAssert(reg.line, reg.type == Tokenizer::Identifier, "% not followed by identifier");
                        sources.push_back(AssemblyProgram::DataSource{ prog.getRegister(reg.line, reg.word), 0, nullptr, nullptr, AssemblyProgram::Pointer });
                    }
                    else if (cur.word == "@") {
                        Tokenizer::Token val = nextToken();
                        compileAssert(val.line, val.type == Tokenizer::Number, "@ not followed by a number");
                        sources.push_back(AssemblyProgram::DataSource{ prog.getMemory(val.line, atoi(val.word.c_str())), 0, nullptr, nullptr, AssemblyProgram::Pointer });
                    }
                    else if (cur.word == "@%") {
                        Tokenizer::Token reg = nextToken();
                        compileAssert(reg.line, reg.type == Tokenizer::Identifier, "@% not followed by identifier");
                        sources.push_back(AssemblyProgram::DataSource{ nullptr, 0, prog.getRegister(reg.line, reg.word), &prog, AssemblyProgram::Memory });
                    }
                    else if (cur.word == "#") {
                        Tokenizer::Token def = nextToken();
                        compileAssert(def.line, def.type == Tokenizer::Identifier, "# not followed by identifier");
                        toupper(def.word);
                        if (def.word == "LINE")
                            sources.push_back(AssemblyProgram::DataSource{ nullptr, def.line, nullptr, nullptr, AssemblyProgram::Constant });
                        else
                            compileError(def.line, "Compile-time constant identifier \"" + def.word + "\" undefined");
                    }
                    else if (cur.word == "$") {
                        if (command == "callfunc") {
                            Tokenizer::Token func = nextToken();
                            compileAssert(func.line, func.type == Tokenizer::Identifier, "\"callfunc $\" not followed by a identifier as function name");
                            auto it = funcStartLines.find(func.word);
                            if (it == funcStartLines.end())
                                compileError(func.line, "Function \"" + func.word + "\" undefined");
                            else {
                                prog.pushCommand(i->line, "CALL", {
                                    AssemblyProgram::DataSource{ nullptr, it->second, nullptr, nullptr, AssemblyProgram::Constant }
                                                 });
                            }
                            pushCommand = false;
                        }
                        else
                            compileError(cur.line, "$ not preceeded by keyword \"function\" or \"callfunc\"");

                    }
                }
                if (compileErrorLevel)
                    ok = false;
            }
            if (ok&&pushCommand)
                prog.pushCommand(i->line, i->command, sources);
        }

        if (compileErrorLevel) {
            compileErrorLevel = false;
            prog.valid = false;
        }
        else
            prog.valid = true;
    }

private:

    vector<Command> commands;
    map<string, int> funcStartLines;
    bool valid;


};


AssemblyProgram prog;
Tokenizer tokens;
Compiler compiler;


int main(int argc, char* argv[]) {

    int n;
    cin >> n;

    string str;
    string total;
    while (n > 0 && getline(cin, str)) {
        if (str == "")
            continue;
        n--;
        total += str + '\n';
    }

    tokens.parseTotal(total);
    compiler.compile(tokens);
    compiler.generateCode(prog);
    prog.run();

    return 0;
}