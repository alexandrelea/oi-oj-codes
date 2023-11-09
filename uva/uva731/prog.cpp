#include <stdio.h>
double phi(int x)
{
    double ret = 0.0;
    for (int i = 1; i <= x; i++)
    {
        ret += 1.0 / i;
    }
    return ret / (double)x;
}
void Series_Sum(double sum[])
{
    int n = 1000;
    sum[0] = 1.644934066848;
    for (int i = 0; i < 300; i++)
    {
        double phii = phi(i + 1);
        double phii1 = phi(i + 2);
        double phii2 = phi(i + 3);
        for (int j = 1; j <= 10; j++)
        {
            int x = 10 * i + j;
            double dx = x * 0.1;
            sum[x] = 0; // ((double)i + 3.0 - dx) / (4.0 * (double)n * (double)n * (double)n * (double)n);
            for (int k = 1; k < n; k++)
            {
                sum[x] += 1.0 / ((double)k * ((double)k + dx) * ((double)k + (double)i + 1.0) * ((double)k + (double)i + 2.0) * ((double)k + (double)i + 3.0));
            }
            sum[x] = phii + ((double)i + 1.0 - dx) * (((double)i + 2.0 - dx) * (((double)i + 3.0 - dx) * sum[x] + 0.5 * phii - phii1 + 0.5 * phii2) + phii - phii1);
        }
    }
}
int main()
{
    int i;
    double x, sum[3001];

    Series_Sum(sum);

    x = 0.0;
    for (i = 0; i < 3001; i++)
        printf("%6.2f %16.12f\n", x + (double)i * 0.10, sum[i]);

    return 0;
}
