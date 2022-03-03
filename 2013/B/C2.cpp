#include <bits/stdc++.h>

#define ll long long
#define ld double
#define ull unsigned long long

#define ff first
#define ss second

// For Loops ----------------------------

#define lp(i, n) for (ll i = 0; i < n; i++)
#define lp1(i, n) for (ll i = 1; i < n; i++)

// Vectors / pairs / maps  ---------------

#define pairll pair<ll, ll> pll
#define pairll pair<ll, ll> pll

#define mapn map<ll, ll> mll
#define mapll map<ll, ll> mll

#define vect vector<ll> v
#define vectl vector<long long> vl
#define vectodd vector<ll> vodd
#define vecteven vector<ll> veven
#define vects vector<string> vs

#define eb emplace_back
#define pb push_back

#define mp make_pair

#define vectin(v, n)            \
    for (ll i = 0; i < n; i++) \
    {                           \
        ll ele;                \
        cin >> ele;             \
        v.eb(ele);              \
    }

#define vectprll(v)      \
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

// Yes/ No for CodeForces ---------------
// # define 	yes 			cout << "YES" << endl
// # define 	no 				cout << "NO" << endl

using namespace std;

ll r, c, gx, gy;
ll visited[105][105];

vector<vector<ll>> maze;

bool issafe(ll x, ll y)
{
    if (x < 0 or x >= c or y < 0 or y >= r or maze[y][x] == -1 or visited[y][x])
        return 0;

    return 1;
}

ll total = 0, min_step = INT_MAX, max_power = 0;

void minsteps(ll x, ll y, ll cur_step, ll power)
{
    cout << x << ' ' << y << endl;

    if (x == gx and y == gy)
    {
        if (cur_step <= min_step)
        {
            min_step = cur_step;
            max_power = max(max_power, power);
        }

        return;
    }

    visited[y][x] = 1;

    if (!(x + 1 < 0 or x + 1 >= c or y < 0 or y >= r or maze[y][x + 1] == -1 or visited[y][x + 1]))
    {
        power += maze[y][x+1];
        minsteps(x + 1, y, cur_step + 1, power);
        power -= maze[y][x+1];
    }

    if (!(x < 0 or x >= c or y + 1 < 0 or y + 1 >= r or maze[y + 1][x] == -1 or visited[y + 1][x]))
    {
        power += maze[y+1][x];
        minsteps(x, y + 1, cur_step + 1, power);
        power -= maze[y + 1][x];
    }

    if (!(x - 1 < 0 or x - 1 >= c or y < 0 or y >= r or maze[y][x-1] == -1 or visited[y][x-1]))
    {
        power += maze[y][x-1];
        minsteps(x - 1, y, cur_step + 1, power);
        power--;
        power -= maze[y][x-1];
    }

    if (!(x < 0 or x >= c or y - 1 < 0 or y - 1 >= r or maze[y - 1][x] == -1 or visited[y - 1][x]))
    {
        power += maze[y - 1][x];
        minsteps(x, y - 1, cur_step + 1, power);
        power -= maze[y - 1][x];
    }

    visited[y][x] = 0;
}

void solve()
{
    cin >> r >> c;
    ll sx, sy;
    cin >> sy >> sx >> gy >> gx;

    lp(i, r)
    {
        vect;
        lp(j, c)
        {
            ll ele;
            cin >> ele;
            v.eb(ele);
        }
        maze.eb(v);
    }

    minsteps(sx, sy, 0, maze[sy][sx]);

    // cout << min_step << endl;
    if (min_step == INT_MAX)
    {
        cout << "Mission Impossible." << endl;
        return;
    }
    cout << max_power << endl;

    // for (auto i : mm)
    // {
    //     cout << i.first << ' ' << i.second << endl;
    // }

    // auto it = mm.begin();
    // ll ans = it->second + maze[sy][sx];

    // cout << ans << endl;
}

int main()
{
    // for t test cases
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t = 1, T;
    cin >> T;
    while (t <= T)
    {
        cout << "Case #" << t << ": ";
        memset(visited, 0, sizeof(visited));
        solve();
        cerr << "CASE : " << t << " Solved !" << endl;
        maze.clear();
        total = 0;
        min_step = INT_MAX;
        max_power = 0;
        t++;
    }
}