#include <bits/stdc++.h>
using namespace std;
int d[111], n, m, z, i, j, k, l;
int cnt = 0;
string s;
int main()
{
    cin >> n >> m;
    for (k = 0; k < n; k++)
    {
        cin >> s;
        if (s == "alloc")
        {
            cin >> z;
            for (i = 0, j = -1; i < m; i++)
            {
                if (i - j == z && !d[i])
                    break;
                else if (d[i])
                    j = i;
            }
            if (i - j == z && i < m)
            {
                cnt++;
                cout << cnt << endl;
                for (l = j + 1; l <= i; l++)
                    d[l] = cnt;
            }
            else
                cout << "NULL" << endl;
        }
        if (s == "erase")
        {
            cin >> z;
            int p = 0;
            for (int i = 0; i < m; i++)
            {
                if (d[i] == z && z != 0)
                {
                    d[i] = 0;
                    p = 1;
                }
            }
            if (p == 0)
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
        }
        if (s == "defragment")
        {
            for (int i = 0, j = 0; i < m; i++)
            {
                if (d[i])
                {
                    l = d[j];
                    d[j] = d[i];
                    d[i] = l;
                    j++;
                }
            }
        }
    }
    return 0;
}