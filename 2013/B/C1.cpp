#include <bits/stdc++.h>

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

#define vect vector<int> v
#define vectl vector<long long> vl
#define vectodd vector<int> vodd
#define vecteven vector<int> veven
#define vects vector<string> vs

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

// Yes/ No for CodeForces ---------------
// # define 	yes 			cout << "YES" << endl
// # define 	no 				cout << "NO" << endl

using namespace std;

ll r, c, gx, gy, mindist = INT_MAX, max_power = 0, total = 0;
bool vis[101][101]{{}};
int dir[4][2] {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<vector<ll>> maze;

template <typename P> struct Cmp
{
    bool operator()(const P &p1, const P &p2)
    {
        if (p1.ff > p2.ff)
            return true;

        if (p1.ff == p2.ff)
            return p1.ss < p2.ss;

        return false;
    }
};

void minsteps(int x, int y)
{
    queue <pair <pair <ll, ll>, pair <ll, ll>>> q;
    q.push(mp(mp(x, y), mp(0, maze[y][x])));
    vis[y][x] = 1;

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        ll cur_x = it.ff.ff, cur_y = it.ff.ss, cur_dis = it.ss.ff, cur_pow = it.ss.ss;

        if (cur_x == gx and cur_y == gy)
        {
            // if (cur_dis <= mindist)
            // {
            //     mindist = cur_dis;
                max_power = max(max_power, cur_pow);
                total++;
                vis[cur_y][cur_x] = 0;
            // }
        }

        for (int i = 0; i < 4; i++)
        {
            ll new_x = cur_x + dir[i][0], new_y = cur_y + dir[i][1];

            if (new_x < 0 or new_x >= c or new_y < 0 or new_y >= r or maze[new_y][new_x] == -1 or vis[new_y][new_x])
                continue;
            
            q.push(mp(mp(new_x, new_y), mp(cur_dis + 1, cur_pow + maze[new_y][new_x])));
            vis[new_y][new_x] = 1;
        }
    }
}

void solve()
{
    cin >> r >> c;
    int sx, sy;
    cin >> sy >> sx >> gy >> gx;

    lp(i, r)
    {
        vectl;
        lp(j, c)
        {
            ll ele;
            cin >> ele;
            vl.eb(ele);
        }
        maze.eb(vl);
    }

    minsteps(sx, sy);

    cout << total << ' ' << max_power << endl;
}

int main()
{
    // for t test cases
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        cout << "Case #" << t << ": ";
        memset(vis, 0, sizeof(vis));
        solve();
        mindist = INT_MAX;
        max_power = 0;
        maze.clear();
        t++;
    }
}