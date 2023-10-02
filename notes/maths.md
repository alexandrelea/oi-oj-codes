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
+ Eratosthenes 筛法。这可以手算：写下 $1\sim n$ 的所有整数，对于 $2\sim\sqrt{n}$ 的所有数，如果我们没有将这个数叉掉，我们就在它上面画圈，而后叉掉它的所有倍数，例如我们寻找 $2-10$ 之间的所有素数，并将其写成代码，其时间复杂度大约为 $\mathrm O(\ln(\ln n)\sqrt{n})$：

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

### Pollard $\rho$ 质数判定

这个东西依赖于费马小定理的逆定理——如果 $a^{m-1}\equiv 1\pmod m$

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

# 几何
# 高数