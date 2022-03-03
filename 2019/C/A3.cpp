#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

#define fi first
#define se second

const int N = 100100;
const int MAGIC = 130;

using namespace std;

int n;
map<pair<int, int>, bool> used;
map<pair<int, int>, pair<int, int>> d[4];

pair<int, int> get(pair<int, int> x, int g)
{
    if (d[g].find(x) == d[g].end())
    {
        d[g][x] = x;
        if (g == 0)
        {
            d[g][x].se -= 1;
        }
        else if (g == 1)
        {
            d[g][x].fi += 1;
        }
        else if (g == 2)
        {
            d[g][x].se += 1;
        }
        else
        {
            d[g][x].fi -= 1;
        }
    }
    if (used.find(d[g][x]) == used.end())
    {
        return d[g][x];
    }
    return d[g][x] = get(d[g][x], g);
}

void solve()
{
    used.clear();
    for (int i = 0; i < 4; i++)
        d[i].clear();
    int x, y;
    cin >> n >> x >> y >> x >> y;
    pair<int, int> res = {x, y};
    used[res] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int i = 0; i < 4; i++)
        {
            cout << i << endl;
            for (auto i : d[i])
            {
                cout << "Start : " << i.first.first << ' ' << i.first.second << endl;
                cout << "        " << i.second.first << ' ' << i.second.second << endl;
            }
        }
        cout << endl;

        char c;
        cin >> c;
        int g = 0;
        if (c == 'S')
        {
            g = 1;
        }
        else if (c == 'E')
        {
            g = 2;
        }
        else if (c == 'N')
        {
            g = 3;
        }
        res = get(res, g);
        used[res] = 1;
    }
    cout << res.fi << " " << res.se << "\n";
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
}
