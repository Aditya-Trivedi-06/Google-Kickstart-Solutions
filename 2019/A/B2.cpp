#include <bits/stdc++.h>
#include <chrono>

#define ll long long
#define ld double
#define uint unsigned int
#define ull unsigned long long

#define ff first
#define ss second

// For Loops ----------------------------

#define lp(i, n) for (int i = 0; i < n; i++)
#define lp1(i, n) for (int i = 1; i < n; i++)

// Vectors / pairs / maps  ---------------

#define pairint pair<int, int> pint
#define pairll pair<ll, ll> pll

#define mapn map<int, int> mint
#define mapll map<ll, ll> mll

#define vect(v) vector<int> v
#define vectl(vl) vector<long long> vl
#define vectodd(vodd) vector<int> vodd
#define vecteven(veven) vector<int> veven
#define vects(vs) vector<string> vs

#define eb emplace_back
#define pb push_back

#define mp make_pair

#define vectin(v, n)            \
    for (int i = 0; i < n; i++) \
    {                           \
        int ele;                \
        cin >> ele;             \
        v.eb(ele);              \
    }

#define vectprint(v)      \
    for (auto i : v)      \
    {                     \
        cout << i << ' '; \
    }

#define mploop(mpn) for (auto i = (mpn).begin(); i != (mpn).end(); i++)
#define vectloop(v) for (auto i = (v).begin(); i != (v).end(); i++)

// Usefull functions --------------------

// # define 	bn 				begin
// # define 	rs 				resize
#define ALL(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))
#define REV(v) reverse(ALL(v))

#define lb lower_bound
#define ub upper_bound

#define bs binary_search

#define gcd __gcd

// Max nd Mins -------------------------

#define min3(a, b, c) min(min(a, b), c)
#define min4(a, b, c, d) min(min(a, b), min(c, d))
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))

#define mod 1000000007

// Yes/ No for CodeForces ---------------
// # define 	yes 			cout << "YES" << endl
// # define 	no 				cout << "NO" << endl

using namespace std;
using namespace std::chrono;

int r, c;
vector<string> mat;
int dis[255][255];

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool isvalid(int x, int y, set<pair<int, int>> vis)
{
    if (vis.find(mp(y, x)) != vis.end())
        return false;

    if (x < 0 or y < 0 or x >= c or y >= r)
        return false;

    return true;
}

bool inrange(int x, int y)
{
    if (x < 0 or y < 0 or x >= c or y >= r)
        return false;

    return true;
}

void dfs(int x, int y, set<pair<int, int>> vis)
{
    // cout << x << ' ' << y << endl;
    vis.insert(mp(y, x));
    int min_poss = dis[y][x];
    for (int i = 0; i < 4; i++)
    {
        int dx = x + dir[i][0], dy = y + dir[i][1];
        if (inrange(dx, dy))
        {
            // cout << dx << ' ' << dy << endl;
            min_poss = min(min_poss, 1 + dis[dy][dx]);
        }
    }
    dis[y][x] = min_poss;
    // cout << min_poss << endl;
    // else
    // {
    //     int min_poss = dis[y][x];

    //     if (x == 0 and y == 0)
    //     {
    //         min_poss = min3(min_poss, dis[y+1][x], dis[y][x+1]);
    //     }
    //     if (x == r-1 and y == c-1)
    //     {
    //         min_poss = min3(min_poss, dis[y-1][x], dis[y][x-1])
    //     }
    //     else if (x == 0)
    //     {
    //         min_poss = min4(min_poss, dis[y][x])
    //     }
    // }

    for (int i = 0; i < 4; i++)
    {
        int dx = x + dir[i][0], dy = y + dir[i][1];
        if (isvalid(dx, dy, vis))
        {
            dfs(dx, dy, vis);
        }
    }
}

void solve()
{
    cin >> r >> c;

    lp(i, r)
    {
        string s;
        cin >> s;
        mat.eb(s);
    }

    // for (auto i : mat)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << ' ';
    //     }
    //     cout << endl;
    // }

    lp(i, r)
    {
        lp(j, c)
        {
            if (mat[i][j] == '1')
            {
                dis[i][j] = 0;
                set<pair<int, int>> vis;
                dfs(j, i, vis);
            }
        }
    }

    int max_dis = 0, max_y, max_x;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            // cout << dis[i][j] << ' ';
            if (dis[i][j] > max_dis)
            {
                max_dis = dis[i][j];
                max_y = i;
                max_x = j;
            }
        }
        // cout << endl;
    }
    if (max_dis)
    {
        dis[max_y][max_x] = 0;
        set<pair<int, int>> vis;
        dfs(max_x, max_y, vis);
    }
    else
    {
        cout << 0 << endl;
        return;
    }

    int ans = 0;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            ans = max(ans, dis[i][j]);

    cout << ans << endl;
}

int main()
{
    // for t test cases
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // auto start = high_resolution_clock::now();
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        cout << "Case #" << t << ": ";
        // cout << endl;
        fill(&dis[0][0], &dis[0][0] + 254 * 254, INT16_MAX);
        solve();
        mat.clear();
        t++;
    }
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cerr << duration.count() / 1000000 << " S " << endl;
}