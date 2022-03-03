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

int R, C, n;
int dir[4][2]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool safe(int x, int y, vector<vector<bool>> vis, vector<vector<char>> mat)
{
    return (x >= 0 and y >= 0 and x < C and y < R and mat[y][x] == '1' and !vis[y][x]);
}

int bfs(vector <vector<char>> mat)
{
    int count = 0;
    vector<vector<bool>> vis (R, vector <bool> (C, 0));

    lp(i, R)
    {
        lp(j, C)
        {
            if (mat[i][j] == '0' or vis[i][j])
                continue;
            
            count++;

            queue < pair <int, int>> q;
            q.push(mp(j, i));

            while(!q.empty())
            {
                int x = q.front().first, y = q.front().second;
                q.pop();

                for (auto i : dir)
                {
                    int dx = x + i[0], dy = y + i[1];
                    if (dx >= 0 and dy >= 0 and dx < C and dy < R and mat[dy][dx] == '1' and !vis[dy][dx])
                        vis[dy][dx] = 1, q.push(mp(dx, dy));
                }
            }
        }
    }

    return count;
}

void solve()
{
    cin >> R >> C;

    vector<vector<char>> mat;

    lp(i, R)
    {
        vector<char> temp;
        lp(j, C)
        {
            char ele;
            cin >> ele;
            temp.eb(ele);
        }
        mat.eb(temp);
    }
    cin >> n;

    char test, z;
    int x, y;

    lp(i, n)
    {
        cin >> test;
        if (test == 'M')
        {
            cin >> x >> y >> z;
            mat[x][y] = z;
        }
        else
        {
            cout << bfs(mat) << endl;
        }
    }
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
        cout << "Case #" << t << ": " << endl;
        solve();
        t++;
    }
}