#include <bits/stdc++.h>

using namespace std;
const double eps = 1e-6;
int N;
double X[10000];
double Y[10000];
double W[10000];
double calweight(double x, double y)
{
    double weight = 0.0;
    for (int i = 0; i < N; i++)
    {
        weight += max(abs(x - X[i]), abs(y - Y[i])) * W[i];
    }
    return weight;
}
double process2(double x)
{
    double lo = -1000.0;
    double hi = 1000.0;
    while (hi - lo > eps)
    {
        double y1 = lo + (hi - lo) / 3.0;
        double y2 = lo + (hi - lo) / 3.0 * 2.0;
        if (calweight(x, y1) < calweight(x, y2))
        {
            hi = y2;
        }
        else
        {
            lo = y1;
        }
    }
    return calweight(x, lo);
}
double process()
{
    double lo = -1000.0;
    double hi = 1000.0;
    int i = 0;
    while (hi - lo > eps)
    {
        double x1 = lo + (hi - lo) / 3.0;
        double x2 = lo + (hi - lo) / 3.0 * 2.0;
        if (process2(x1) < process2(x2))
        {
            hi = x2;
        }
        else
        {
            lo = x1;
        }
        i++;
    }
    fprintf(stderr, "times: %d", i);
    return process2(lo);
}
int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        cin >> N; // read n and then m.
        for (int j = 0; j < N; j++)
        {
            cin >> X[j] >> Y[j] >> W[j];
        }
        double res = process();
        // cout << "Case #" << i << ": " << res << endl;
        printf("Case #%d: %lf\n", i, res);
        fprintf(stderr, "Case #%d: %lf\n", i, res);
    }
}