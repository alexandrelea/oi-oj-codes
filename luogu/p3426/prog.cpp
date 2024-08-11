#include <bits/stdc++.h>
using namespace std;
string a;
int nxt[500005];
int n;
int f[500005];
vector<int> e[500005];
set<int> s;
set<int>::iterator it;
int gap = 1;
void del(int x)
{
    it = s.find(x);
    if (it == s.begin())
    {
        s.erase(x);
        return;
    }
    ++it;
    if (it == s.end())
    {
        s.erase(x);
        return;
    }
    int r = *it;
    --it;
    --it;
    gap = max(gap, r - *it);
    s.erase(x);
    return;
}
void dfs(int u)
{
    if (f[u] && u >= gap)
    {
        cout << u << endl;
        return;
    }
    del(u);
    int v;
    for (int k = 0; k < e[u].size(); k++)
    {
        v = e[u][k];
        if (!f[v])
            dfs(v);
    }
    for (int k = 0; k < e[u].size(); k++)
    {
        v = e[u][k];
        if (f[v])
            dfs(v);
    }
    return;
}
int main()
{
    cin >> a;
    n = a.length();
    a = "*" + a;
    int j = 0;
    e[0].push_back(1);
    for (int i = 2; i <= n; i++)
    {
        while (j && a[j + 1] != a[i])
            j = nxt[j];
        if (a[j + 1] == a[i])
            ++j;
        nxt[i] = j;
        e[nxt[i]].push_back(i);
    }
    int p = n;
    while (p)
    {
        f[p] = 1;
        p = nxt[p];
    }
    for (int i = 0; i <= n; i++)
    {
        s.insert(i);
    }
    dfs(0);
    return 0;
}
