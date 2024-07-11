#include <cstdio>

bool solve(int& w) {
    bool b1 = true, b2 = true;
    int w1, d1, w2, d2;
    scanf("%d%d%d%d", &w1, &d1, &w2, &d2);
    if (!w1) b1 = solve(w1);
    if (!w2) b2 = solve(w2);
    w = w1 + w2;
    return b1 && b2 && (w1 * d1 == w2 * d2);
}

int main() {
    int w, T;
    scanf("%d", &T);
    while (T--) {
        printf("%s\n", solve(w) ? "YES" : "NO");
        if (T) printf("\n");
    }
    return 0;
}
