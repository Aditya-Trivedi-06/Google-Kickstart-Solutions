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

// #define pairint pair<int, int> pint
// #define pairll pair<ll, ll> pll

#define mapn map<int, int> mint
#define mapll map<ll, ll> mll

#define vect vector<int> v
#define vectl vector<long long> vl
#define vectodd vector<int> vodd
#define vecteven vector<int> veven
// #define vects vector<qring> vs

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

#define INF INT16_MAX;

int r, c, sx, sy, fx, fy;
int mat[105][105];
int val[105][105];
int dis[105][105];
bool vis[105][105], found = 0;
int dir[4][2] {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void minqeps(int x, int y)
{
    queue <pair<int, int>> q;
    q.push(mp(x, y));
    val[y][x] = mat[y][x]; 

    int max_size = 0;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int cur_x = cur.ff, cur_y = cur.ss;
        vis[cur_y][cur_x] = 1;
        // int qsize = q.size();
        // max_size = max(max_size, qsize);

        if (cur_x == fx and cur_y == fy)
        {
            found = 1;
            break;
        }

        lp(i, 4)
        {
            int new_x = cur_x + dir[i][0], new_y = cur_y + dir[i][1];

            if (new_x < 0 or new_y < 0 or new_x >= c or new_y >= r or mat[new_y][new_x] == -1 or vis[new_y][new_x])
                continue;
            
            if (dis[new_y][new_x] == 0 or dis[new_y][new_x] >= dis[cur_y][cur_x] + 1)
            {
                if (dis[new_y][new_x] == 0)
                {
                    q.push(mp(new_x, new_y));
                    dis[new_y][new_x] = dis[cur_y][cur_x] + 1;
                }
                val[new_y][new_x] = max(mat[new_y][new_x] + val[cur_y][cur_x], val[new_y][new_x]);
            }
        }
    }

    // cerr << max_size << endl;
}

void solve()
{
    cin >> r >> c;
    cin >> sy >> sx >> fy >> fx;

    lp(i, r)
        lp(j, c)
            cin >> mat[i][j];

    minqeps(sx, sy);

    if (found)
    {
        cout << val[fy][fx] << endl;
    }
    else
    {
        cout << "Misson Impossible." << endl;
    }
}

int main()
{
    // for t teq cases
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        cout << "Case #" << t << ": ";
        found = 0;
        memset(vis, 0, sizeof(vis));
        memset(dis, 0, sizeof(dis));
        memset(val, 0, sizeof(val));
        memset(mat, 0, sizeof(mat));
        solve();
        t++;
    }
}
