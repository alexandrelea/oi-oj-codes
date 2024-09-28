# 树据结构

## 线段树

把一个长为 $n$ 的序列进行递归地分块，对于一段序列 $n=[l,r]$，其中 $n$ 为编号，

+ 若 $l=r$，则 $s_n=a_l$；
+ 若 $l<r$，则设 $m=\lfloor(l+r)/2\rfloor$，递归 $(2n)=[l,m]$ 和 $(2n+1)[m+1,r]$，并合并这两个子段的信息。

这就是**线段树**，一种可以支持序列维护的好的数据结构。

体现在代码上，我们的线段树一般递归地编写，因为如果使用循环的话总归会有些费力。同时，线段树一般采用二分，因为好想又好写。

# 字符串

## AC 自动机

请注意，这里的 AC 自动机不包括分辨的功能！

我们看代码。

```cpp
int to[N][2],too[N][2],te[N],ro[N],vis[N],sz[N],tot,cnt;
ll f[N];
```

这两行的声明部分包括了各个 AC 自动机的树结构 `to`，建立起来的 AC 自动机 `too`，fail 指针 `te`，各个 AC 自动机的根节点 `ro`（别忘了 AC 自动机事实上是一棵树），出现次数 `vis`，自动机内字符串大小 `sz`，节点个数 `tot`，AC 自动机个数 `cnt`，以及作为累加答案需要的 `f`。

```cpp
void newstr(string s,int &r){
    if(r==0) r=++tot;
    int u=r;
    for(auto ch:s){
        if(to[u][ch-'0']==0) to[u][ch-'0']=++tot;
        u=to[u][ch-'0'];
    }
    vis[u]|=1;
}
```

插入部分，没什么好说的。

```cpp
set<string> re;
void insert(string s){
    if(re.count(s)) return;
    re.insert(s);
    sz[++cnt]=1;
    newstr(s,ro[cnt]);
    while(sz[cnt-1]==sz[cnt]) sz[cnt-1]+=sz[cnt],ro[cnt-1]=merge(ro[cnt-1],ro[cnt]),ro[cnt]=0,--cnt;
    build(ro[cnt]);
}
```

这里我们首先把一个字符串插入到某个新建的 AC 自动机里（函数内第 3 至 4 行），然后合并大小相等的 AC 自动机，就像 2048 一样（倒数第 2 行），最后对最终合并起的新自动机进行 AC 自动机建立工作，这是因为前面的我们已经建立过了。

需要注意的是，这里为了判重，加上了一个 `set`，不需要可以删掉。

```cpp
int merge(int u,int v){
    if(u==0||v==0) return u+v;
    vis[u]+=vis[v];
    for(int i=0;i<=1;++i) to[u][i]=merge(to[u][i],to[v][i]);
    return u;
}
```

这里，我们把空节点并起来，然后把重复出现的次数累加起来，最后把子节点做一下合并。

```cpp
void build(int r){
    queue<int> que;
    te[r]=r;
    for(int i=0;i<=1;++i){
        if(to[r][i]!=0) too[r][i]=to[r][i],te[too[r][i]]=r,que.push(too[r][i]);
        else too[r][i]=r;
    }
    while(!que.empty()){
        int u=que.front();que.pop();
        f[u]=vis[u]+f[te[u]];
        for(int i=0;i<=1;++i){
            if(to[u][i]) too[u][i]=to[u][i],te[too[u][i]]=too[te[u]][i],que.push(to[u][i]);
            else too[u][i]=too[te[u]][i];
        }
    }
}
```

首先，根节点的 fail 肯定指向自己 :-)。随后，我们把需要进行的根节点直接延伸出的节点压入队列。

按照拓扑排序，我们首先累加可能出现的次数（预处理，就像 dp）。对于各个子节点，如果它存在，那么就把它的 fail 指针指向该节点 fail 指针指向的位置，然后压入随后处理的队列；否则的话……我们必须创造一个节点，直接指向 fail 指针指向的对应位置。

```cpp
ll query(string s){
    ll ans=0;
    for(int i=1;i<=cnt;++i){
        int u=ro[i];
        for(auto ch:s){
            u=too[u][ch-'0'];
            ans+=f[u];
        }
    }
    return ans;
}
``` 

查询时，对于每个 AC 自动机累加一遍就好了，因为我们已经预处理完了我们的累加次数。
