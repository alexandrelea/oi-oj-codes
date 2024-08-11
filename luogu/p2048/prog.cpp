#include <iostream>
#include <cmath>
#include <queue>
#define int long long
using namespace std;
const int size = 5e5 + 10;
int n, k, l, r, sum[size] = {}, mx[size][22] = {}, rx[size][22] = {}, ans = 0;

int query(int l, int r) {
    int k = log2(r - l + 1);

    if (mx[l][k] > mx[r - (1 << k) + 1][k])
        return rx[l][k];
    else
        return rx[r - (1 << k) + 1][k];
}
struct qelem {
    int l, r, fr, wh, val;
    bool operator<(const qelem oth)const {
        return val < oth.val;
    }
    qelem(int l, int r, int x): l(l), r(r), fr(x) {
        wh = query(l, r);
        val = sum[wh] - sum[fr - 1];
    }
};
void initst() {
    for (int j = 1; j <= 21; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            mx[i][j] = mx[i][j - 1], rx[i][j] = rx[i][j - 1];

            if (mx[i + (1 << (j - 1))][j - 1] > mx[i][j])
                mx[i][j] = mx[i + (1 << (j - 1))][j - 1], rx[i][j] = rx[i + (1 << (j - 1))][j - 1];
        }
    }
}
priority_queue<qelem> pq;
signed main() {
    cin >> n >> k >> l >> r;

    for (int i = 1; i <= n; i++)
        cin >> sum[i], sum[i] += sum[i - 1], rx[i][0] = i, mx[i][0] = sum[i];

    initst();

    for (int i = 1; i <= n; i++) {
        int ll = i + l - 1, rr = min(i + r - 1, n);

        if (ll <= n)
            pq.push(qelem(ll, rr, i));
    }

    for (int i = 1; i <= k; i++) {
        if (pq.empty())
            break;

        qelem x = pq.top();
        pq.pop();
        ans += x.val;

        if (x.wh != x.l)
            pq.push(qelem(x.l, x.wh - 1, x.fr));

        if (x.wh != x.r)
            pq.push(qelem(x.wh + 1, x.r, x.fr));
    }

    cout << ans << endl;
    return 0;
}