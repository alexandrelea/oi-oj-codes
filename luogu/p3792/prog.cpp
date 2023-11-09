#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef struct node
{
    ll min, max, sum, sum2, sum3;
} node;
const ll mod = 1000007, INF = 100000000000000000;
node t[2000010];
ll n, m, a[500010], opt, k1, k2, kmin, kmax, ks, ks2, ks3;
inline ll read()
{
    ll num = 0, k = 1;
    char c = getchar();
    while (c > '9' || c < '0')
        k = (c == '-') ? 0 : k, c = getchar();
    while (c >= '0' && c <= '9')
        num = num * 10 + c - '0', c = getchar();
    return k ? num : -num;
}
void pushup(ll o)
{
    t[o].sum = t[(o << 1)].sum + t[((o << 1) | 1)].sum;
    t[o].sum2 = (t[(o << 1)].sum2 + t[((o << 1) | 1)].sum2) % mod;
    t[o].sum3 = (t[(o << 1)].sum3 + t[((o << 1) | 1)].sum3) % mod;
    t[o].min = min(t[(o << 1)].min, t[((o << 1) | 1)].min);
    t[o].max = max(t[(o << 1)].max, t[((o << 1) | 1)].max);
}
void build(ll o, ll l, ll r)
{
    if (l == r)
    {
        t[o].min = t[o].max = t[o].sum = a[l];
        t[o].sum2 = a[l] * a[l] % mod;
        t[o].sum3 = t[o].sum2 * a[l] % mod;
        return;
    }
    ll mid = (l + r) >> 1;
    build((o << 1), l, mid);
    build(((o << 1) | 1), mid + 1, r);
    pushup(o);
}
void update(ll o, ll l, ll r, ll q, ll x)
{
    if (l == r)
    {
        t[o].min = t[o].max = t[o].sum = x;
        t[o].sum2 = x * x % mod;
        t[o].sum3 = t[o].sum2 * x % mod;
        return;
    }
    ll mid = (l + r) >> 1;
    if (q <= mid)
        update((o << 1), l, mid, q, x);
    else
        update(((o << 1) | 1), mid + 1, r, q, x);
    pushup(o);
}
void query(ll o, ll l, ll r, ll ql, ll qr)
{
    if (r < ql || l > qr)
        return;
    if (ql <= l && qr >= r)
    {
        kmin = min(kmin, t[o].min);
        kmax = max(kmax, t[o].max);
        ks += t[o].sum;
        ks2 = (ks2 + t[o].sum2) % mod;
        ks3 = (ks3 + t[o].sum3) % mod;
        return;
    }
    ll mid = (l + r) >> 1;
    if (l <= mid)
        query((o << 1), l, mid, ql, qr);
    if (r >= mid + 1)
        query(((o << 1) | 1), mid + 1, r, ql, qr);
}
ll qs2(ll x) { return x * (x + 1) % mod * (2 * x + 1) % mod; }
ll qs3(ll x) { return x * (x + 1) % mod * x % mod * (x + 1) % mod; }
int main()
{
    n = read();
    m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    build(1, 1, n);
    while (m--)
    {
        opt = read();
        k1 = read();
        k2 = read();
        if (opt == 1)
            update(1, 1, n, k1, k2);
        if (opt == 2)
        {
            kmin = INF;
            kmax = -INF;
            ks = ks2 = ks3 = 0;
            query(1, 1, n, k1, k2);
            if (kmax - kmin != k2 - k1)
                printf("yuanxing\n");
            else if (ks != (kmax + kmin) * (kmax - kmin + 1) / 2)
                printf("yuanxing\n");
            else if (ks2 * 6 % mod != ((qs2(kmax) - qs2(kmin - 1)) % mod + mod) % mod)
                printf("yuanxing\n");
            else if (ks3 * 4 % mod != ((qs3(kmax) - qs3(kmin - 1)) % mod + mod) % mod)
                printf("yuanxing\n");
            else
                printf("damushen\n");
        }
    }
    return 0;
}
