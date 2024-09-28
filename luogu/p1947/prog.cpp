extern "C" int Seniorious(int);
extern "C" int Chtholly(int n,int c){
    int L=1,R=n;
    while(1){
        int M=L+((R-L)>>1),A=Seniorious(M);
        if(A==1) R=M-1;
        else if(A==-1) L=M+1;
        else return M;
    }
    return L;
}