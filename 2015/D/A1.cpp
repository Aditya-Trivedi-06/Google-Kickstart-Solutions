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

void dfs(int x, int y, vector<vector<bool>> &vis, vector<vector<char>> mat)
{
    vis[y][x] = 1;
    lp(i, 4)
    {
        int newx = x + dir[i][0], newy = y + dir[i][1];
        if (safe(newx, newy, vis, mat))
        {
            dfs(newx, newy, vis, mat);
        }
    }
}

int dfs_util(vector<vector<char>> mat)
{
    vector<vector<bool>> vis(R, vector<bool>(C, 0));
    int count = 0;

    lp(i, R)
    {
        lp(j, C)
        {
            if (mat[i][j] == '0' or vis[i][j])
                continue;

            count++;
            dfs(j, i, vis, mat);
        }
    }

    return count;
}

void solve()
{
    cin >> R >> C;

    vector < vector <char>> mat;

    lp(i, R)
    {
        vector <char> temp;
        lp(j, C)
        {
            char ele;
            cin >> ele;
            temp.eb(ele);
        }
        mat.eb(temp);
    }
    cin >> n;

    vector <int> ans;

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
            // ans.push_back(dfs_util(mat));
        }
    }
    for (auto i : ans)
        cout << i << endl;
}

int main()
{
    // for t test cases
    // freopen("input.txt", "r", stdin);
    
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