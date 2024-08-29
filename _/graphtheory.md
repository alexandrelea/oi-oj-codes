基础定义：图由节点集合 $V$ 和边的集合 $E$ 组成，即 $G=(V,E)$。其中边或者点可以携带附加信息，它们的名字将在具体的算法中有所不同。

图分为有向图和无向图，其实后者就是双向建边的前者。

存储图的方法：

1. Floyd 算法的邻接矩阵：`g[u][v]` 代表图是否联通，或者边权。
2. 通用的 `vector` 存边：
```cpp
struct edg{
    int u,v,...; // More additional information can be written here
    edg(int u=0,int v=0,...):u(u),v(v),...{}
};
vector<edg> edgs;
vector<int> gr[N]; // the gr here only save the num of the edge
void nwedg(int u,int v,...){
    edgs.push_back(edg(u,v,...));
    gr[u].push_back(edgs.end()-edgs.begin()-1);
    // the follow 2 lines saves the inverse edge
    edgs.push_back(edg(v,u,...));
    gr[v].push_back(edgs.end()-edgs.begin()-1);
}
```
这个存储方法适合所有的图算法，除了最小生成树，如果边不能复制一份副本的话。

# 单源最短路

这里我们给图添加上一个叫做边权 $w$ 的附加信息，它是走过边需要的代价。

现在我们的问题是，给定起点 $s$，求起点到所有点的最小代价 $d_{1\cdots n}$。

## Dijkstra 算法

现在，我们肯定有一个想法：在所有边的权 $w>0$ 时，我们知道，最短路只有增大的可能。

那么，假若我们求出了某个点的最短路，它不可能更小，这样我们就有一个贪心的想法：

1. 找到从 $s$ 到某个未访问的点，满足 $s$ 到该点的边权和最小。
2. 访问这个点，更新这个点到与其相连的所有点的边权值。

这个算法，如果未经过优化，复杂度是 $O(n^2+nm)$ 的，如果优化的话，寻找最小点就从 $O(n)$ 变为 $O(\log n)$，这样算法的时间复杂度就变成了 $O(n\log n+nm)$。于是，代码如下。

```cpp

int n,m,s,t,dis[N];
bool vis[N];
struct edg{
    int u,v,w;
    edg(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
};
vector<edg> edge;
vector<int> gr[N];
void nwedg(int u,int v,int w){
    edge.push_back(edg(u,v,w));
    gr[u].push_back(edge.end()-edge.begin()-1);
    edge.push_back(edg(v,u,w));
    gr[v].push_back(edge.end()-edge.begin()-1);
}
void dijkstra(int s){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s]=0,pq.push({0,s});
    while(!pq.empty()){
        int u=pq.top().second;pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int ie:gr[u]){
            int v=edge[ie].v,w=edge[ie].w;
            if(dis[v]>dis[u]+w) dis[v]=dis[u]+w,pq.push({dis[v],v});
        }
    }
}
```

这份代码符合 C++11 的编译标准。

## SPFA

略。

# 最小生成树

给定一个无向图，选取边使得图连通，且选取的边的边权和最小。显然我们要建一棵树。

## Kruskal 算法

既然要求最小生成树，我们可以贪心，只需要把所有的边排序，一条边一条边建树，如果已经相连则不考虑（这里用并查集）。

