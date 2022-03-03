#include <bits/stdc++.h>

using namespace std;

const int NMAX = 10000;
double X[NMAX], Y[NMAX], W[NMAX];
int N;

double go(double x, double y)
{
    cout << x << ' ' << y << endl;
    double ret = 0;
    for (int i = 0; i < N; i++)
        ret += max(abs(X[i] - x), abs(Y[i] - y)) * W[i];
    return ret;
}

double ternary_search(double x)
{
    double lo = -1000, hi = 1000;
    for (int i = 0; i < 100; i++)
    {
        double m1 = (2 * lo + hi) / 3;
        double m2 = (lo + 2 * hi) / 3;
        double L = go(x, m1), R = go(x, m2);
        if (L <= R)
            hi = m2;
        else
            lo = m1;
    }
    return go(x, lo);
}

double process()
{
    double lo = -1000, hi = 1000;
    for (int i = 0; i < 100; i++)
    {
        double m1 = (2 * lo + hi) / 3;
        double m2 = (lo + 2 * hi) / 3;
        // cout << m1 << ' ' << m2 << endl;
        double L = ternary_search(m1), R = ternary_search(m2);
        // cout << L << ' ' << R << endl;
        if (L <= R)
            hi = m2;
        else
            lo = m1;
    }
    return ternary_search(lo);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("small.out", "w", stdout);

    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++)
    {
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
            scanf("%lf%lf%lf", X + i, Y + i, W + i);
        printf("Case #%d: %.10f\n", tc, process());
    }
}