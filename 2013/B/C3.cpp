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

# define INF INT16_MAX;

int n, m, sx, sy, fx, fy;
int mat[105][105];
bool vis[105][105];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

vector < vector < pair <int, int>>> total;

void minsteps(int x, int y)
{
    int count = 0;
    queue <pair <int, int>> st;
    st.push(mp(x, y));

    while (!st.empty())
    {
        auto cur = st.front();
        st.pop();
        int cur_x = cur.ff, cur_y = cur.ss;
        vis[cur_y][cur_x] = 1;

        if (cur_x == fx and cur_y == fy)
            count++;
        
        lp(i, 4)
        {
            int new_x = cur_x + dir[i][0], new_y = cur_y + dir[i][1];
            if (new_x < 0 or new_y < 0 or new_x >= n or new_y >= m or mat[new_y][new_x] == -1 or vis[new_y][new_x])
                continue;
            st.push(mp(new_x, new_y));
        }
    }

    cout << count << endl;
}

void solve()
{
    cin >> n >> m;
    cin >> sx >> sy >> fx >> fy;

    lp(i, m)
    {
        lp(j, n)
            cin >> mat[i][j];
    }

    minsteps(sx, sy);

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
        solve();
        t++;
    }
}
