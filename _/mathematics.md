# 数论

在这个大篇的内容中，数都是整数，不论其为正数，负数或 $0$。如有不同，另会说明。

## 整除

若 $a=kb$，则 $b\backslash a$，即 $b$ **整除** $a$。它的性质显而易见，故不言明。这个符号是高德纳的，因为用竖线会把它和集合混一起。

## 同余

若 $a=mk+r,r\in(-m,m)\cup\Z$，我们可以得出两个式子：

+ 取余：$a\bmod m=r$。
+ 同余：$a\equiv r\pmod m$。

它们都很重要。

## 素数筛法

定义**素数**，即只能被 $1$ 或自身整除的自然数（且不是 $0$ 或者 $1$！），且所有不是素数的自然数我们都叫做合数。

我们有一个朴素的筛质数的方式：首先将 $2\sim n$ 的所有整数按顺序排列在纸上，首先划掉 $2$ 的所有倍数，随后划掉所有 $3$ 的所有倍数，如果某个数已经被划掉，那么我们不再管它，随后划掉 $5$ 的所有倍数……

这个东西其实叫做**埃拉托斯克尼筛法**，代码如下：

```cpp
memset(vis,0,sizeof vis);
for(int i=2;i<=n;++i)
    for(int j=i*2;j<=n;j+=i) vis[j]=1;
```

但是，这个算法有点慢，因为它是 $O(n\log n)$ 的（证明详见调和级数）。所以，我们改进一下就得到

```cpp
memset(vis,0,sizeof vis);
pc=0;
for(int i=2;i<=n;++i){
    if(vis[i]==0) pr[++pc]=i;
    for(int j=1;j<=pc&&i*pr[j]<=n;++j){
        vis[i*pr[j]]=0;
        if(i%pr[j]==0) break;
    }
}
```

这个算法是**欧拉的线性筛法**，复杂度是 $O(n)$，足够使用。

**唯一分解定理** 是指对于某数 $n$，其可以分解成唯一的质因数分解式 $n=\prod_{p\in\mathbb P}p^{e_p}$。

## 最大公约数&最小公倍数

定义两数的 **最大公约数** $a,b$ 为可以同时整除两数的最大数 $c$，形式化是 $\gcd(a,b)=(a,b)=\max\{c|(c\backslash a)\land(c\backslash b)\}$。

定义两数的 **最小公倍数** $a,b$ 为两数可以整除该数 $c$ 的最大值，形式化式 $\mathrm{lcm}(a,b)=[a,b]=\min\{c|(a\backslash c)\land(b\backslash c)\}$。

不难通过唯一分解定理证明，$(a,b)[a,b]=ab$。

这里需介绍最大公约数的求法：$(a,b)=(b,a\bmod b)$。

*证明*。令 $a\bmod b=r$, 所以 $a=kb+r$, 所以 $r=a-kb$。假设 $g$ 为 $a,b$ 的一个公约数，那么 $g\backslash a,g\backslash b$，所以 $g\backslash (a-kb)$，即 $g\backslash r$，也就是 $g\backslash(a\bmod b)$。所以 $g$ 是 $a,b,a\bmod b$ 的公约数。*证毕*（本法被称为**欧几里得**算法）。

当 $b$ 到 $0$ 时，这个操作无法进行，得到的 $a$ 即最大公约数。这个方法我们可以把它压到一行里：

```cpp
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
```

## 二元一次不定方程

众所周知，在实数范围内，$ax+by=c$ 一定有解。可是这是数论。故我们需要一些更实在的东西。

**裴蜀定理**是指：对于非零整数 $a,b$，满足对于任意整数 $x,y$，$(a,b)\backslash ax+by$，同时存在 $(x,y)$ 满足方程 $ax+by=(a,b)$。证明略。

我们可以导出一些重要结论。

众所周知，$(a,b)=(b,a\bmod b)$。所以，我们可以进行换元，把 $(a,b)\to(b,a\bmod b)$，这样我们得出两条方程：

$$ax+by=(a,b)$$
$$bx+(a\bmod b)y=(a,b)$$

消掉右边，得到 $ax+by=bx+(a\bmod b)y$。

众所周知，我们可以通过下取整除法得到余数，即

$$\mathrm{RHS}=bx+\left(a-b\left\lfloor\frac ab\right\rfloor\right)y$$

简单代换，得到 

$$\mathrm{RHS}=ay+b\left(x-\left\lfloor\frac ab\right\rfloor y\right)$$

这样，我们就可以通过变量代换 $(x,y)\to(y,x-\lfloor a/b\rfloor y)$ 得到解。解的最下一层是 $(a,0)$，它的解是 $x=1,y=0$，然后递归即可。

代码如下。

```cpp
void exgcd(int a,int b,int &x,int &y){
    if(b==0) x=1,y=0;
    else exgcd(b,a%b,y,x),y-=a/b*x;
}
```
如果解 $ax+by=c$ 时带入即可，当然，如果 $\lnot (a,b)\backslash c$，则无解。

## 一元模方程组

考虑如下方程组（满足 $a$ 两两互质）

$$
\begin{cases}
x\equiv r_1\pmod{a_1}\\
x\equiv r_2\pmod{a_2}\\
\cdots\\
x\equiv r_n\pmod{a_n}\\
\end{cases}
$$

我们要得出 $x$，就需要求助老智慧。

1. 我们令 $A=\prod a_k$，并令 $\alpha_k=A/a_k$。
2. 求出满足 $\alpha_k\alpha_k^{-1}\equiv 1\pmod{a_k}$。
3. 设 $q_k=\alpha_k\alpha_k^{-1}$。**没有取模。**

则答案即为 $$\left(\sum_{k=1}^n r_kq_k\right)\bmod A$$。容易证明，对于任意答案 $C$，$C+kA$ 同样满足解。

我们来分析一下解的过程。这里我们只考虑某一个 $k$ 的情况。

对于方程组
$$
\begin{cases}
x\equiv 1\pmod{a_k}\\
x\equiv 0\pmod{a_h}&h\neq k
\end{cases}
$$
容易证明， $x$ 的解是所有 $a_h$ 的乘积的常数倍，这是因为后一条方程。如果我们要同时满足前一条方程，我们需要在它的左端乘上 $\alpha_k=A/a_k$。即
$$\alpha_k x\equiv1\pmod{a_k}$$
这相当于找出 $\alpha_k$ 对 $a_k$ 的逆元。当然，如果我们两端乘以 $r_k$ 时，等式依然成立。

现在我们删除后面的同余记号，并把得到的解累加起来，就满足了所有的方程，这是因为各个项满足了各个方程，故这个解满足所有方程。

代码如下。

```cpp
int CRT(int n,int a[],int r[]){
    int A=1,ans=0;
    for(int i=1;i<=n;++i) A*=a[i];
    for(int i=1;i<=n;++i){
        int ah=A/a[i],ahi,tmp,g=gcd(ah,a[i]);
        exgcd(ah,a[i],ahi,tmp);
        ans+=r[i]*(ah*ahi)+A,ans%=A;
    }
    return (ans+A)%A;
}
```

当然，如果它们不互质，有两个办法（第二个办法我们暂不介绍）。

第一个方法即两两合并等式。对于两条方程

$$\begin{cases}x\equiv r_p\pmod{a_p}\\ x\equiv r_q\pmod{a_q}\end{cases}$$

我们可以用定义得到这样两条方程：

$$\begin{cases}x=r_p+h_pa_p\\ x=r_q+h_qa_q\end{cases}$$

消掉 $x$，并把未知数 $h_p,h_q$ 移到等式左边，我们得到

$$h_pa_p-h_qa_q=r_q-r_p$$

或者当我们令 $r=r_q-r_p$ 时，我们的方程可以写成

$$h_pa_p\equiv r\pmod{a_q}$$

我们可以用扩展欧几里得算法解出 $h_p$，代入就得到满足两个方程的一个 $x'=h_pa_p+r_p$，这样我们可以做变量代换 $(x',[a_p,a_q])\to(r_p,a_p)$，我们就把两个方程合并为一个。

对于多个方程，进行多次合并即可。

代码如下。

```cpp
int exCRT(int n,int a[],int r[]){
    int ap=a[1],rp=r[1];
    for(int i=2;i<=n;++i){
        int aq=a[i],rq=r[i],hp,hq,g=gcd(ap,aq),r=((rq-rp+aq)%aq+aq)%aq;
        if(r%g!=0) return -1;
        exgcd(ap,aq,hp,hq),hp*=(r/g);
        rp=hp*ap+rp,ap*=(aq/g);
        rp=((rp+ap)%ap+ap)%ap;
    }
    return (rp+ap)%ap;
}
```

## 欧拉函数

这里的欧拉函数 $\varphi(n)$，它的式子可以写作

$$\varphi(n)=\sum_{k=1}^{n}[(n,k)=1]$$

显然，$\varphi(p)=p-1$，且对于 $(a,b)=1$ 的数对 $(a,b),\varphi(ab)=\varphi(a)\varphi(b)$。所以……我们可以用欧拉筛法。即

```cpp
memset(vis,0,sizeof vis);
pc=0;
for(int i=2;i<=n;++i){
    if(vis[i]==0) pr[++pc]=i,phi[i]=i-1;
    for(int j=1;j<=pc&&i*pr[j]<=n;++j){
        vis[i*pr[j]]=0;
        if(i%pr[j]!=0) phi[i*pr[j]]=phi[i]*(pr[j]-1);
        else{
            phi[i*pr[j]]=phi[i]*pr[j];
            break;
        }
    }
}
```

为什么 `else` 开头的话能这样写呢？我们可以看看 $\varphi$ 函数的另一种写法

$$\varphi(n)=n\prod_{p\in\mathbb P\land p\backslash n}\left(1-\frac 1p\right)$$

当我们已经求出 $\varphi(m)$，并知道 $n=pm$，我们可以由上式推得 $\varphi(n)=p\varphi(m)$。

# 线性代数
## $n$ 元线性方程组

对于方程组
$$
\begin{cases}
a_{11}x_1+a_{12}x_2+\cdots+a_{1n}x_n=b_1\\
a_{21}x_1+a_{22}x_2+\cdots+a_{2n}x_n=b_1\\
\cdots\\
a_{n1}x_1+a_{n2}x_2+\cdots+a_{nn}x_n=b_n\\
\end{cases}
$$
我们可以写作矩阵乘法的形式，即
$$
\begin{bmatrix}
a_{11}&a_{12}&\cdots&a_{1n}\\
a_{21}&a_{22}&\cdots&a_{2n}\\
\vdots&\vdots&\ddots&\vdots\\
a_{n1}&a_{n2}&\cdots&a_{nn}
\end{bmatrix}
\begin{bmatrix}x_1\\x_2\\\vdots\\x_n\end{bmatrix}
=
\begin{bmatrix}b_1\\b_2\\\vdots\\b_n\end{bmatrix}
$$
简化一下，即
$$\mathbf A\mathbf x=\mathbf b$$
现在我们的任务是解出 $\mathbf x$ 的各个分量。

首先，我们令 $\mathbf M=\begin{bmatrix}\mathbf A|\mathbf b\end{bmatrix}$，即把 $\mathbf A$ 和 $\mathbf b$ 并成一个 $n\times (n+1)$ 的矩阵。随后，我们可以使用 Gauss-Jordan 法进行消元。

### Gauss-Jordan 法

对于 $\mathbf M$ 的第 $l$ 行方程，我们的目标是把所有行中带 $l$ 的都消掉。这样，我们只需要第 $l$ 行的数都乘以 $\mathbf M_{l,l}^{-1}$，随后把除了 $l$ 以外的行 $k$ 都减去 $\mathbf M_{k,l}$ 倍的第 $l$ 行即可。但是，没有这样简单。我们还没考虑无解或者多解的情况。

### LU 法

还没学会。。。