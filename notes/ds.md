标题：部分数据结构

# 线性数据结构


以下是 Stasis 原文：

这种 lj 数据结构能将原本的前缀和 $\mathrm O(1)$ 查询和 $\mathrm O(n)$ 修改的缺陷平衡至 $\mathrm O(\log n\cdot\log\log n)$ 修改与查询。而且，如果您嫌麻烦的话，也可以实现一个 $\mathrm O(\log^2 n)$ 查询，$\mathrm O(\log n)$ 修改前缀和的数据结构。缺点是空间复杂度会变大。

~~本文是我家养的宠物猪jc我本人后乱发的，求各位大佬轻喷。~~

以下是数据结构的具体内容：

如果我们要维护一个序列 $A$ 的前缀和，我们可以直接用一个 $\text{sum}$ 数组保存。但是这种方法简陋且不具有美感。

我们可以以整个序列上的元素建造一棵二叉树。请注意，它不同于线段树和树状数组，它仅仅是将 $A_1\cdots A_1$ 作为根节点，$A_2\cdots A_3$ 从左到右作为第一层，$A_4\cdots A_7$ 从左到右作为第二层，以此类推。它是一棵完全二叉树。

二叉树上的点有点权，边有边权。边权不会改动。一个点 $A_x$ 到根节点路径上所有边的边权和和点权和就是 $A_x$ 的初始前缀和。

先不讨论点权，它初始是 $0$。

边权具体是多少？ 还是以 $x$ 为例子，$A_x$ 到它的父亲 $A_f$ 的边权就是区间 $[f+1,x]$ 的和。边权均可以用 $\mathrm O(n)$ 的预处理求。

很显然，“一个点 $A_x$ 到根节点路径上所有边的边权和就是 $A_x$ 的初始前缀和” 这句话是正确的。我们仅仅是将一个前缀和分成了 $\log n$ 段。

假如我们要修改一个值（例如加减 $k$），那么此时将会有一些与其相对应的边权需要改动。但是由于这些边都连向同一或同二层，我们显然有一种更加巧妙的方法修改：

我们将两层上需要修改的入边分别考虑。每一层上的点都是连续的。于是将这些点分为 $\log n$ 段，每段长度都可以用 $2^p$ 表示，$p$ 为自然数。可以 $\mathrm O(1)$ 求出每一段的 LCA ，我们将这些 LCA 的结果增加深度数组上的点权。

例如，我们修改一个点 $A_7$ 时，分出来两层 $[7,7]$ 与 $[8,13]$、假设我们要处理 $[8,13]$ 的，我们又可以分为两段 $[8,11]$ 与 $[12,13]$。此时只需要修改 $A_2$ 和 $A_6$ 的点权就行了。

但是这样有一个问题：我们要查询 $[1,4]$ 的前缀和，仍然会遍历到 $A_2$。而 $[7,13]$ 是不包括 $[1,4]$ 的！

所以对于每一个点，开辟一个深度数组的空间，用树状数组维护~~或者暴力维护~~。我们修改点权时，记录使它修改的那一层的深度，并在深度数组上记录点权的修改情况。当我们遍历到修改过的点时，只需要看起始深度是否比修改深度大就行了。

可能这并没有什么用。但其实 $\mathrm O(\log\log n)$ 的时间复杂度是极小的。且它可以用同样的方法维护带修改的前缀max，前缀异或，以及一些奇奇怪怪的前缀。

如果还有可以优化的地方，欢迎苣佬们给蒟蒻提一些意见哇QAQ

代码：

修改

```cpp
void update(int p,int zz){
	int lx=p,rx=rblock[deep[p]+1],ly=lblock[deep[willam_tree[p-1].rson]+1]==0 ? mxn2/2-1 : lblock[deep[willam_tree[p-1].rson]+1],ry=min(n-1,willam_tree[p-1].rson);
	if(deep[p]+1==deep[willam_tree[p-1].rson]+1){
		willam_tree[0].pointnum[deep[p]+1]+=zz;
		return;
	}
	if(deep[p]+1==maxdeep){
		ly=ry+1;
	}
	for(int z=mxn2,r=cntn2;z>=1 && lx<=rx;z/=2,r--){
		if(rx-z>=lx-1){
			if(r==0){
				willam_tree[rx-z+1].pointnum[deep[p]+1]+=zz;
			}else{
				willam_tree[fa[rx-z+1][r-1]].pointnum[deep[p]+1]+=zz;
			}
			rx-=z;
		}
	}
	for(int z=mxn2,r=cntn2;z>=1 && ly<=ry;z/=2,r--){
		if(ly+z<=ry+1){
			if(r==0){
				willam_tree[ly].pointnum[deep[willam_tree[p-1].rson]+1]+=zz;
			}else{
				willam_tree[fa[ly][r-1]].pointnum[deep[willam_tree[p-1].rson]+1]+=zz;
			}
			ly+=z;
		}
	}
}
```

查询

```cpp
int ask(int x,int firsts){
	if(x==-1){
		return -a[0];
	}
	int anss=0;
	for(int i=1;i<=firsts;i++){
		if(willam_tree[x].pointnum[i]!=0){
			anss+=willam_tree[x].pointnum[i];
		}
	}
	if(x==0){
		return anss;
	}
	return ask(fa[x][0],firsts)+anss+willam_tree[x].fanum;
}
```

---

这是一点点分析。