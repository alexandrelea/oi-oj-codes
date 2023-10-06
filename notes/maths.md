标题：部分数学笔记

# 数论

模算数是数论的基础。

譬如 $10\equiv 2\pmod 4$，也可以写成 $10\bmod 4=2$。类似于小学的余数。

这里需要整除的定义，当 $b\bmod a=0$ 时，我们就记 $a\mid b$，否则就记 $a\nmid b$。

## 最大公约数

最大公约数就是两个数最大的公约数（废话）。形式地讲，$\gcd(n,m)=\max\{k,k\mid n\text{ and }k\mid m\}$。这挺简单。我们可以直接写欧拉筛法，即

$$\gcd(n,m)=\begin{cases}
\gcd(m,n\bmod m)&m\neq0
\\n&m=0
\end{cases}$$

通常用递归写，即

```cpp
int gcd(int n,int m){
    return m==0?n:gcd(m,n%m);
}
```

好好好，这个东西虽然只有一行，但是常数有点大。

最小公倍数同样可以使用上式定义，不过需要简单的改改符号：$\mathrm{lcm}(n,m)=\min\{k,n\mid k\text{ and }m\mid k\}$，这也挺简单。需要附加说明的是，$\dfrac{nm}{\gcd(n,m)}=\mathrm{lcm}(n,m)$。

另外需要补上一个定义：如果两个整数 $n,m$ 满足 $\gcd(n,m)=1$，那么我们就记 $n\perp m$，叫作 $n,m$ 互素。

### 解线性不定方程

首先需要澄明的是 Bezout 定理：设 $a,b$ 是两个整数，并且不都是 $0$，那么就存在整数 $x,y$ 满足 $ax+by=\gcd(a,b)$。

好，假定我们要解方程 $ax+by=c$，那么——

第一步求出 $g=\gcd(a,b)$，如果 $g\nmid c$，那么方程无解。不需要解释。

好的下面我们知道，

$$ax+by=\gcd(a,b)$$

众所周知，

$$\gcd(a,b)=\gcd(b,a\bmod b)$$

因此，我们可以做一个代换：$(a,b)\rightarrow(b,a\bmod b)$，那么

$$ax+by=bx+(a\bmod b)y$$

好，根据 $\bmod$ 的一种定义，我们就有

$$ax+by=bx+\left(a-\left\lfloor\frac{a}{b}\right\rfloor b\right)y$$

$$ax+by=bx+ay-\left\lfloor\frac{a}{b}\right\rfloor by$$

于是，下一步，我们选 $a,b$ 为主元，随后搞一搞他，把 $a,b$ 的变换改成 $x,y$ 的变换就有

$$ax+by=ay+b\left(x-\left\lfloor\frac{a}{b}\right\rfloor y\right)$$

因而我们可以总结出下面的代换：

$$(x,y)\to\left(y,x-\left\lfloor\frac{a}{b}\right\rfloor y\right)$$

而后递归解。设 $x=1,y=0$，而后我们就可以搞出所有的解：

```cpp
void exgcd(int a,int b,int &x,int &y,int &g){
    if(b==0) x=1,y=0,g=a;
    else exgcd(b,a%b,y,x,g),y-=a/b*x;
}
```

别忘了加上 $c\bmod\gcd(a,b)=0$ 的特判！

## 素数

素数，形式化的讲，即因子只有 $1$ 和其本身的数。判断素数也挺简单，我们有三种办法，先假定要判断的 $n$：

1. 按照定义，我们可以判断 $2\sim n-1$ 的所有数，不过我们可以改作 $2\sim\sqrt{n}$，毕竟最大只有 $\sqrt{n}\cdot\sqrt{n}$ 才能搞成 $n$。它的时间复杂度是 $\mathrm O(\sqrt{n})$，因此我们可以这样写：

```cpp
bool isprime(int n){
    if(n==0||n==1) return false;
    for(int i=2;i*i<=n;i++) if(n%i==0) return false;
    return true;
}
```
2. 为了在 $\mathrm O(1)$ 的时间内判断素数，我们需要一点点初始化。有两种方法：
+ Eratosthenes 筛法。这可以手算：写下 $1\sim n$ 的所有整数，对于 $2\sim\sqrt{n}$ 的所有数，如果我们没有将这个数叉掉，我们就在它上面画圈，而后叉掉它的所有倍数，例如我们寻找 $2-10$ 之间的所有素数，并将其写成代码，其时间复杂度大约为 $\mathrm O(n\ln\ln n)$：

$$\sout{1}\ 2\ 3\ 4\ 5\ 6\ 7\ 8\ 9\ 10$$
$$\sout1\ 2\ 3\ \sout{4}\ 5\ \sout{6}\ 7\ \sout{8}\ 9\ \sout{10}$$
$$\sout1\ 2\ 3\ \sout4\ 5\ \sout 6\ 7\ \sout 8\ \sout 9\ \sout{10}$$
$$2,3,5,7$$

```cpp
const int range=1e6;
bool isprime[range+10];
void eratosthenes(){
    memset(isprime,1,sizeof(isprime));
    isprime[0]=isprime[1]=false;
    for(int i=2;i*i<=range;i++){
        if(isprime[i]) for(int j=2;j*i<=range;j++) isprime[i*j]=false;
    }
    return;
}
```

+ Euler 筛法。我们发现，一个数可能会被某些素数多次筛除，因此我们可以想出法子使所有合数只删除一遍。因此我们给出时间约等于 $\mathrm O(n)$ 的算法：

```cpp
const int range=1e6;
bool isprime[range+10];
int prime[range+10],tot;
void euler(){
    memset(isprime,1,sizeof(isprime));
    isprime[0]=isprime[1]=false;
    for(int i=2;i<=range;i++){
        if(isprime[i]) prime[++tot]=i;
        for(int j=1;j<=tot&&i*prime[j]<=range;j++){
            isprime[i*prime[j]]=false;
            if(i%prime[j]==0) break;
        }
    }
}
```

+ 费马小定理的进阶版本，这个后面再说。

### 算数基本定理

这个定理很简单，即每个整数 $n$ 都能表述为唯一的数个素数相乘的形式，即

$$n=\prod_{p\mid n}p^{e_p}$$

因此如果题目要求乘法或更恐怖式子的素因数分解，那么我们只将素数的指数加起来即可。

素因数分解的算法可以通过修改 Euler 筛得到。由于 Euler 筛对于每个数只会筛除一次，因此我们可以记录每个数的最小素因子，除以它直到数变成 $1$。

```cpp
const int range=1e6;
bool isprime[range+10];
int prime[range+10],tot,minp[range+10];
void euler(){
    memset(isprime,1,sizeof(isprime));
    isprime[0]=isprime[1]=false;
    for(int i=2;i<=range;i++){
        if(isprime[i]) prime[++tot]=i,minp[i]=i;
        for(int j=1;j<=tot&&i*prime[j]<=range;j++){
            isprime[i*prime[j]]=false,minp[i*prime[j]]=j;
            if(i%prime[j]==0) break;
        }
    }
}
void factor(int n,int *cnt){
    while(n!=1) cnt[minp[n]]++,n/=minp[n];
}
```


### 素数个数

这也很简单，统计学表明，$n$ 以下的素数个数 $\pi(n)$ 满足下面式子：

$$\pi(n)\sim\frac{n}{\ln n}$$

这是个好东西，让我们可以估计素数个数。

## 欧拉函数

记 $\varphi(n)$ 代表 $1\sim n-1$ 中与 $n$ 互质的数的个数。按照定义，$\varphi(p)=p-1$。（请注意，$p$ 是质数。）另外按照定义，$\varphi(p^k)=p^k-p^{k-1}$。

欧拉函数可以通过筛法获得，也可以通过下面的东西获得：记满足下面条件的函数作为积性函数：

$$f(nm)=f(n)f(m),n\perp m.$$

欧拉函数自然是一个积性函数。

因此，依据唯一分解定理和积性函数的定义，我们就可以搞出 $\varphi(n)$ 的表达式：

设
$$n=\prod_{p\mid n}p^{e_p}$$
那么我们便可以改一改：
$$\varphi(n)=\prod_{p|n}(p^{e_p}-p^{e_p-1})=n\prod_{p|n}\left(1-\frac{1}{p}\right)$$

这样我们就可以使用筛数法来解这东西。当然，使用欧拉筛法也不是不可能。因此可以使用上文介绍的素因数分解的方式来解出 $\varphi(n)$。

$f(n)=n$ 是积性函数。

## 欧拉定理

欧拉定理的内容是：若 $\gcd(a,m)=1$，则 $a^{\varphi(m)}\equiv1\pmod m$。这里证明就略掉了。

这里放上一个欧拉定理的升级版：费马小定理，即如果 $a\neq p$，则 $a^{p-1}\equiv 1\pmod p$，这是个好东西。

当然，在两端乘上点什么也不是不可以。

### Pollard $\rho$ 质数判定

这个东西依赖于费马小定理的逆定理——如果 $a^{m-1}\equiv 1\pmod m$，那么 $m$ 是质数。

不幸的是这个定理不对。

因而我们需要加上一点东西。

以下内容（包括代码）均引用 Programming Challenges（作者：寂静山林）。

> 可以证明，如果 $p$ 是一个”老素数“且 $e\ge 1$，则同余方程 $x^2\equiv 1\pmod {p^e}$ 仅有解 $x=\pm 1$。当给定一个”老素数“$p$，则 $p-1$ 为偶数，而且 $p-1$ 可以表示为 $p-1=2^s\cdot d$ 其中 $s$ 和 $d$ 均为正整数，$d$ 为奇数。根据上面两个结论，可以证明，对于 $1<a<p$，有 $a^d\equiv 1\pmod p$ 或者 $a^{2^r\cdot d}\equiv -1\pmod p,0\le r\le s-1$ 根据此条结论的逆否命题，只要我们找到一个基数 $a$ 使得 $a^d\not\equiv 1\pmod p$ 并且 $a^{2^r\cdot d}\not\equiv-1\pmod p,0\le r\le s-1$ 那么 $p$ 不是素数。米勒-拉宾素性测试即基于此推论。给定奇数 $n>2$，每当随机选取 $1<a<n$ 之间的一个数作为基数进行素性测试，如果均满足上面结论的要求，则 $n$ 有可能是一个素数，而且测试通过的次数越多，$n$ 为素数的可能性就越大，但若有一次测试不满足上述等式，那么可以确定 $n$ 为合数。给定数 $n$，若 $n$ 通过了一次测试，则 $n$ 不是素数的概率为 $\frac{1}{4}$，若数 $n$ 通过了 $k$ 次测试，则 n 是素数的概率为 $1-\frac{1}{4^k}$。
>
> 以下是米勒-拉宾素性测试的参考实现。

```cpp
//------------------------------7.1.2.cpp------------------------------//
// 进行素性测试时的最大迭代次数。
const int K = 20；
// 以加法和乘法结合的方式进行模运算，以便最大限度地避免溢出。
long long multiplyMod(long long a, long long b, long long mod)
{
 long long x = 0, y = a % mod;
 while (b) {
 if (b & 1) x = (x + y) % mod;
 y = (y * 2) % mod;
 b >>= 1;
 }
 return x;
}
// 快速幂取模。
long long modulo(long long base, long long exponent, long long mod)
{
 long long x = 1, y = base;
 while (exponent) {
 if (exponent & 1) x = multiplyMod(x, y, mod);
 y = multiplyMod(y, y, mod);
 exponent >>= 1;
 }
 return x;
}
// 米勒-拉宾素性测试。
bool isPrime(long long p)
{
 // 初步筛除。
 if (p < 2) return false;
 if (p == 2) return true;
 if (!(p & 1)) return false;
 // 准备。
 long long q = p - 1;
 while (!(q & 1)) q >>= 1;
 // 执行测试。
 for (int i = 0; i < K; i++) {
 long long a = rand() % (p - 1) + 1;
 long long t = q;
 long long mod = modulo(a, t, p);
 while (t != p - 1 && mod != 1 && mod != p - 1) {
 mod = multiplyMod(mod, mod, p);
 t <<= 1;
 }
 if (mod != p - 1 && !(t & 1)) return false;
 }
 return true;
}
//------------------------------7.1.2.cpp------------------------------//
```

## 模算数

这个东西很简单，我们可以轻易地丢出下面式子：

$$ab\bmod c=(a\bmod c)(b\bmod c)\bmod c$$
$$(a\pm b)\bmod c=(a\bmod c)\pm(b\bmod c)\bmod c$$

然而除法却不行。

这可怎么办？在模数 $p$ 为质数的时候费马小定理说：$a^{p-1}\equiv 1\pmod p$，因此，我们就有

$$a^{p-2}\equiv\frac{1}{a}\pmod p$$
$$a^{p-2}\bmod p=a^{-1}\bmod p$$

这不就完了吗？但不幸的是模数 $k$ 有可能不是质数。这时我们就要抛出 $\bmod$ 的定义了：

$$a\bmod b=c \Leftrightarrow a=bk+c$$

因而，如果设 $a$ 的在模 $b$ 意义下的模数为 $\alpha$，那么我们就可以大胆的说：

$$a\alpha\bmod b=1\Leftrightarrow a\alpha+bk=1$$

因此我们的问题转化成了求模线性不定方程，解法往上找。

具体地，我们可以解出满足方程 $a\alpha+bk=1$ 的解 $\alpha,k$ 并注意判断 $\gcd(a,b)=1$ 来找出同余。

## 模线性方程组

我们需要解模线性方程组：

$$
\begin{cases}
x\equiv a_1 \pmod {b_1}\\
x\equiv a_2 \pmod {b_2}\\
\cdots\\
x\equiv a_n \pmod {b_n}\\
\end{cases}
$$

下面，我们来试一试：

设 $x_1,x_2,\cdots,x_n$ 满足下面好多个方程组：

$$
\begin{cases}
x_1\equiv a_1\pmod {b_1}\\
x_1\equiv 0\pmod {b_2}\\
\cdots\\
x_1\equiv 0\pmod {b_n}\\
\end{cases}\\
\begin{cases}
x_2\equiv 0\pmod {b_1}\\
x_2\equiv a_2\pmod {b_2}\\
\cdots\\
x_2\equiv 0\pmod {b_n}\\
\end{cases}\\
\cdots\\
\begin{cases}
x_n\equiv 0\pmod {b_1}\\
x_n\equiv 0\pmod {b_2}\\
\cdots\\
x_n\equiv a_n\pmod {b_n}\\
\end{cases}
$$

容易证明，$\sum x$ 满足整条同余方程组。

那么，我们再次构造 $\chi_1,\chi_2,\cdots,\chi_n$ 满足下面的方程：

$$
\begin{cases}
\chi_1\equiv 1\pmod {b_1}\\
\chi_1\equiv 0\pmod {b_2}\\
\cdots\\
\chi_1\equiv 0\pmod {b_n}\\
\end{cases}\\
\begin{cases}
\chi_2\equiv 0\pmod {b_1}\\
\chi_2\equiv 1\pmod {b_2}\\
\cdots\\
\chi_2\equiv 0\pmod {b_n}\\
\end{cases}\\
\cdots\\
\begin{cases}
\chi_n\equiv 0\pmod {b_1}\\
\chi_n\equiv 0\pmod {b_2}\\
\cdots\\
\chi_n\equiv 1\pmod {b_n}\\
\end{cases}
$$

容易证明，$\sum a_k\chi_k$ 仍然满足全部方程。

因此，我们可以列出下面方程

$$
\begin{cases}
x\equiv a_1 \pmod {b_1}\\
x\equiv a_2 \pmod {b_2}\\
\cdots\\
x\equiv a_n \pmod {b_n}\\
\end{cases}
$$

并且保证 $b_1\perp b_2,\cdots,b_1\perp b_n,\cdots,$（或者说，$b$ 两两互质），那么，我们就可以设

$$B=\prod b$$

而后我们就可以得解（请注意，那个大大的逆元下面有一个角标 $b_i$ 代表这个大分式以 $b_i$ 为模取逆元）

$$x\equiv\sum_{i=1}^n\left(a_i\frac{B}{b_i}\left(\frac{B}{b_i}\right)^{-1}_{b_i}\right)\pmod B$$

容易证明，$x+kB$ 也是方程的解。

下面给出具体实现。

```cpp
lnt crt(int n,lnt *a,lnt *b){
    lnt B=1,x=0;
    for(int i=1;i<=n;i++) B*=b[i];
    for(int i=1;i<=n;i++){
        lnt bb=B/b[i],ivbb,q,g;
        exgcd(bb,b[i],g,ivbb,q);
        x=((x+bb*ivbb%B*a[i]%B)%B+B)%B;
    }
    return (x+B)%B;
}
```

# 二项式系数

二项式系数（据我所知）有三种写法：

1. 熟知的 $C^n_m$ ~~艹nm~~ 写法。
2. 苏联的 $\ _mC_n$ ~~m艹n~~ 写法。
3. 美国人常用的 $\binom nm$ 写法。

这里将会采用第三种写法。

二项式系数的定义是：

$$\binom nm=\frac{n!}{m!(n-m)!}$$

这个东西很恐怖。恐怖的要命。

## 卢卡斯定理

它的表述恒简单。

$$\binom nm\equiv\binom{n\bmod p}{m\bmod p}\binom{\lfloor n/p\rfloor}{\lfloor m/p\rfloor}\pmod p$$

证明，略。

## 撸卡斯定理（或：扩展卢卡斯定理）

怎么说呢……撸卡斯定理是恐怖的。

由于 $(a\bmod b)\bmod c\neq a\bmod(bc)\bmod c$，因此我们只能采用一些暗黑的手段来解。

把结果通过 CRT 组合是一个方法。

请注意，之后要解的是：

$$\binom{n}{k}\bmod m$$

### 撸卡斯定理·1

如果质因数分解得到 $m=\prod_{p_k|m}p^{e_{p_k}}$ 中所有的 $e_p=1$，那么我们就可以这样搞一搞：

1. 求出所有的 $x_{p_k}=\binom{n}{m}\bmod p_k$，这个采用卢卡斯就可以。
2. 列下面方程组并求解：

$$
\begin{cases}
\binom{n}{m}\equiv x_{p_1}\pmod {p_1}\\
\binom{n}{m}\equiv x_{p_2}\pmod {p_2}\\
\cdots\\
\binom{n}{m}\equiv x_{p_2}\pmod {p_3}\\
\end{cases}
$$

### 撸卡斯定理·2

如果撸卡斯定理·1失败了，那么我们就有必要考虑撸卡斯定理·2.

然而，不幸的是卢卡斯定理只对于质数模数起作用。

因此我们需要考虑卢卡斯定理对于质数的幂的作用。

# 几何学（计算几何）

对于几何学，采用的一个建议是，在纸上完成一切可以由人类完成的计算任务，而后再由计算机完成余下的内容。

# 矩阵

## 计算规则

两个长宽相等的矩阵可以完成加减，例如

$$\begin{pmatrix}1&2\\3&4\end{pmatrix}+\begin{pmatrix}5&6\\7&8\end{pmatrix}=\begin{pmatrix}6&8\\10&12\end{pmatrix}$$

$$\begin{pmatrix}1&2\\3&4\end{pmatrix}-\begin{pmatrix}5&6\\7&8\end{pmatrix}=\begin{pmatrix}-4&-4\\-4&-4\end{pmatrix}$$

我们还可以通过数字乘以矩阵——矩阵数乘。例如，

$$-\frac{1}{4}\times\begin{pmatrix}-4&-4\\-4&-4\end{pmatrix}=\begin{pmatrix}1&1\\1&1\end{pmatrix}$$

而后，我们就要介绍该死的矩阵乘法了。

如果有两个矩阵，第一个矩阵如果想要乘以第二个矩阵，那么需要满足一个条件：如果第一个矩阵是 $n\times m$ 的，那么第二个矩阵必须是 $m\times p$ 的，最终乘出来的矩阵一定是 $n\times p$ 的。

矩阵乘法通常采用 $\mathrm O(n^3)$ 的算法，这可以被接受。

假设两个矩阵 $\mathbf A$ 和 $\mathbf B$ 可以相乘，那么我们可以直接使用下面的例子

$$
\mathbf A=\begin{bmatrix}
a_{1,1}&\ldots&a_{1,m}\\
\vdots&\ddots&\vdots\\
a_{n,1}&\ldots&a_{n,m}
\end{bmatrix}
$$

$$
\mathbf B=\begin{bmatrix}
b_{1,1}&\ldots&b_{1,p}\\
\vdots&\ddots&\vdots\\
a_{m,1}&\ldots&a_{m,p}
\end{bmatrix}
$$

$$
\mathbf A\times\mathbf B=\begin{bmatrix}
\sum_{k=1}^{m}{a_{1,k}b_{k,1}}&\ldots&\sum_{k=1}^{m}{a_{n,k}b_{k,1}}\\
\vdots&\ddots&\vdots\\
\sum_{k=1}^{m}{a_{1,k}b_{k,p}}&\ldots&\sum_{k=1}^{m}{a_{n,k}b_{k,p}}
\end{bmatrix}
$$

很好。这个式子令人头脑发晕，因此可以结合下面的两个例子反向记忆矩阵乘法。

## 递推式的计算

直接参见[这里](https://www.luogu.com.cn/blog/322792/solution-uva10655)。

> 现在我们设 $F_n=a^n+b^n$。我们知道，
>
> $$a^3+b^3=(a+b)(a^2-ab+b^2)$$
> 
> 因此我们完全可以考虑通过递推式来求它。~~根据直觉~~，我们设
> 
> $$(a+b)(F_{n-1})-S=F_n$$
> 
> 即
> 
> $$(a+b)(a^{n-1}+b^{n-1})-S=a^n+b^n$$
> 
> 拆开括号，就有
> 
> $$a^n+b^n+a^{n-1}b+ab^{n-1}-S=a^n+b^n$$
> 
> 而后，消掉同类项并移相：
> 
> $$S=a^{n-1}b+ab^{n-1}$$
> 
> 提公因式 $ab$，就有
> 
> $$S=ab(a^{n-2}+b^{n-2})$$
> 
> 最后，将 $S$ 带入，就有
> 
> $$a^n+b^n=(a+b)(a^{n-1}+b^{n-1})-ab(a^{n-2}b^{n-2})$$
> 
> 改写成 $F_n$ 的形式，就是这样：
> 
> $$F_n=sF_{n-1}-pF_{n-2}$$
> 
> 这里
> 
> $$F_0=2$$
> 
> $$F_1=s$$
> 
> 现在，我们有了一种新的方式，即递推法求出 $F_n$，然而肯定会爆炸。
> 
> 然而，上面的式子……看上去就像下面的式子：
> 
> $$F_n=F_{n-1}+F_{n-2}$$
> 
> $$F_0=0,F_1=1$$
> 
> 斐波那契数列的推广！
> 
> 众所周知，斐波那契可以通过矩阵快速幂来解，然而在这个例子中该如何使用呢？
> 
> 现在，我们假设
> 
> $$\begin{bmatrix}F_n&F_{n-1}\end{bmatrix}=\begin{bmatrix}F_{n-1}&F_{n-2}\end{bmatrix}\times \mathbf M$$
> 
> 我们知道，$\mathbf M$ 必然是二行二列的，不然就乘不动了。设
> 
> $$\mathbf M=\begin{bmatrix}m_{11}&m_{12}\\m_{21}&m_{22}\end{bmatrix}$$
> 
> 而乘法结果会长成这样：
> 
> $$\begin{bmatrix}F_n&F_{n-1}\end{bmatrix}=\begin{bmatrix}F_{n-1}&F_{n-2}\end{bmatrix}\times\begin{bmatrix}m_{11}&m_{12}\\m_{21}&m_{22}\end{bmatrix}$$
> 
> $$=\begin{bmatrix}F_{n-1}m_{11}+F_{n-2}m_{21}&F_{n-1}m_{12}+F_{n-2}m_{22}\end{bmatrix}$$
> 
> 由于 $F_n=sF_{n-1}-pF_{n-2}$ 则 $m_{11}=s,m_{21}=-p$；而由于第二项 $F_{n-1}$ 与 $F_{n-1}$ 相同，所以 $m_{12}=1,m_{22}=0$。
> 
> 所以
> 
> $$\mathbf M=\begin{bmatrix}s&1\\-p&0\end{bmatrix}$$
> 
> 由于矩阵乘法满足结合律，所以我们可以先计算出 $\mathbf M^{n-1}$ 再乘以原来的 $\begin{bmatrix}s&2\end{bmatrix}$ 并取出第一项就是我们的答案。
> 
> 所以，
> 
> $$\begin{bmatrix}F_n&F_{n-1}\end{bmatrix}=\begin{bmatrix}F_1&F_0\end{bmatrix}\times\mathbf M^{n-1}=\begin{bmatrix}s&2\end{bmatrix}\times\begin{bmatrix}s&1\\-p&0\end{bmatrix}^{n-1}$$
> 
> 注意特判 $n$ 的初始条件。

## 高斯消元

众所周知，线性方程组

$$
\begin{cases}
k_{1,1}x_1+k_{1,2}x_2+\cdots+k_{1,n}x_n=b_1\\
k_{2,1}x_1+k_{2,2}x_2+\cdots+k_{2,n}x_n=b_2\\
\cdots\ \cdots\ \cdots\\
k_{n,1}x_1+k_{n,2}x_2+\cdots+k_{n,n}x_n=b_n\\
\end{cases}
$$

可以写成系数矩阵的形式

$$
\mathbf K\cdot\mathbf x=\mathbf B
$$

其中

$$
\mathbf K=
\begin{bmatrix}
k_{1,1}&k_{1,2}&\ldots&k_{1,n}\\
k_{2,1}&k_{2,2}&\ldots&k_{2,n}\\
\vdots&\vdots&\ddots&\vdots\\
k_{n,1}&k_{n,2}&\ldots&k_{n,n}
\end{bmatrix}
$$

$$
\mathbf x=
\begin{bmatrix}
x_1\\ x_2\\ \vdots\\ x_n
\end{bmatrix}
$$

$$
\mathbf B=
\begin{bmatrix}
b_1\\ b_2\\ \vdots\\ b_n
\end{bmatrix}
$$

这样我们就可以通过矩阵乘法来简化表达方式，这样未知数的个数可以迅猛地增加。

下一步，我们需要将 $\mathbf{K}$ 和 $\mathbf{B}$ 写成一个矩阵，再度简化表示线性方程组的方式：

$$
\mathbf E=\left[
\begin{array}{cccc|c}
k_{1,1}&k_{1,2}&\ldots&k_{1,n}&b_1\\
k_{2,1}&k_{2,2}&\ldots&k_{2,n}&b_2\\
\vdots&\vdots&\ddots&\vdots&\vdots\\
k_{n,1}&k_{n,2}&\ldots&k_{n,n}&b_n
\end{array}\right]
$$

好，下面我们就来解线性方程组。由于某些该死的原因，这里需要给出一个例子：

$$
\begin{cases}
2x_1+x_2-x_3=8\\
-3x_1-x_2+2x_3=-11\\
-2x_1+x_2+2x_3=-3
\end{cases}
$$

写成矩阵的形式，就是

$$
\left[\begin{array}{ccc|c}
2&1&-1&8\\
-3&-1&2&-11\\
-2&1&2&-3
\end{array}\right]
$$

好的下面我们对矩阵里面的元素进行消去，我们首先聚焦于第一行，此时我们的操作就是除了第一行里的所有元素乘以……算了算了还是用计算说明吧。

现在我们看第一个未知数的系数，而后请看我的操作：


$$
\left[\begin{array}{ccc|c}
2&1&-1&8\\
-3\cdot\frac{2}{-3}&-1\cdot\frac{2}{-3}&2\cdot\frac{2}{-3}&-11\cdot\frac{2}{-3}\\
-2\cdot\frac{2}{-2}&1\cdot\frac{2}{-2}&2\cdot\frac{2}{-2}&-3\cdot\frac{2}{-2}
\end{array}\right]
$$

很好，我们给所有的除了第一行意外所有的行乘以该未知数系数所在的列闭上该未知数的系数。我们继续

$$
\left[\begin{array}{ccc|c}
2&1&-1&8\\
2&\frac{2}{3}&\frac{4}{-3}&\frac{22}{3}\\
2&-1&-2&3
\end{array}\right]
$$

很好，而后我们让后两行减去第一行，而后~~为了省点事~~我们把第二行换成整数：

$$
\left[\begin{array}{ccc|c}
2&1&-1&8\\
0&\frac{1}{3}&\frac{1}{3}&\frac{2}{3}\\
0&2&1&5
\end{array}\right]
$$

$$
\left[\begin{array}{ccc|c}
2&1&-1&8\\
0&1&1&2\\
0&2&1&5
\end{array}\right]
$$

第二步，我们简简单单地用第二行做相同的事，不过使用第二个未知数：

$$
\left[\begin{array}{ccc|c}
2&0&-2&6\\
0&1&1&2\\
0&0&-1&1
\end{array}\right]
$$

而后，我们对第三行再次做相同的事情：


$$
\left[\begin{array}{ccc|c}
2&0&0&4\\
0&1&0&3\\
0&0&-1&1
\end{array}\right]
$$

很好！我们把所有的系数拿掉，我们就得到了最终算出的矩阵：

$$
\left[\begin{array}{ccc|c}
1&0&0&2\\
0&1&0&3\\
0&0&1&-1
\end{array}\right]
$$

最终我们就拿到了 $\mathbf x$：

$$
\mathbf x=\begin{bmatrix}
2\\3\\-1
\end{bmatrix}
$$

矩阵乘法的验算表明我们的做法是正确的。

不过，请注意，我们每次在第 $i$ 行消元时一定要将该系数最大的行交换到该行然后计算且不能换回去！

```cpp
for(int i=1;i<=n;i++){
    double maxn=-1.0/0.0;
    int p;
    for(int j=i+1;j<=n;j++) if(maxn<data[j][j]) maxn=data[j][p=j];
    for(int j=1;j<=n+1;j++) swap(data[p][j],data[i][j]);
    if(data[i][i]==0) return cout<<"No Solution"<<endl,0;
    for(int j=1;j<=n;j++){
        if(j==i) continue;
        double co=data[j][i]/data[i][i];
        for(int k=1;k<=n+1;k++) data[j][k]-=data[i][k]*co;
    }
}
for(int i=1;i<=n;i++) data[i][n+1]/=data[i][i];
```