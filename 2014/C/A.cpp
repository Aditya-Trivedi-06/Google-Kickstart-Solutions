#include <bits/stdc++.h>

#define ll long long
#define ld double
#define uint unsigned int
#define ull unsigned long long

#define ff first
#define ss second

// For Loops ----------------------------

#define lp(i, n) for (int i = 0; i < n; i++)
#define lp1(i, n) for (int i = 1; i <= n; i++)

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

char mine[305][305];
int arr[305][305];
bool vis[305][305] {};

int dir[8][2] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

bool iszero(int i, int j, int n)
{
    lp(k, 8)
    {
        int y = i + dir[k][1], x = j + dir[k][0];
        if (mine[y][x] == '*')
            return false;
    }

    return true;
}

bool isvalid(int i, int j, int n)
{
    return (i >= 1 and j >= 1 and i <= n and j <= n);
}

void dfs(int i, int j, int n)
{
    vis[i][j] = 1;

    lp(k, 8)
    {
        int x = j + dir[k][0], y = i + dir[k][1];
        if (isvalid(y, x, n) and !vis[y][x] and arr[y][x] == 0)
            dfs(y, x, n);
        else 
            vis[y][x] = 1;
    }
}

void solve()
{
    int n;
    cin >> n;

    lp(i, n+2)
        lp(j, n+2)
            mine[i][j] = '.';

    lp1(i, n)
        lp1(j, n)
            cin >> mine[i][j];

    lp1(i, n)
    {
        lp1(j, n)
        {
            if (mine[i][j] == '*')
                arr[i][j] = -1, vis[i][j] = 1;

            else if(iszero(i, j, n))
                arr[i][j] = 0;

            else    
                arr[i][j] = 1;
        }
    }

    int count = 0;

    lp1(i, n)
    {
        lp1(j, n)
        {
            if (arr[i][j] == 0 and !vis[i][j])
            {    
                dfs(i, j, n);
                count ++;
            }
        }
    }

    lp1(i, n)
        lp1(j, n)
            if (!vis[i][j])
                count++;


    // lp1(i, n)
    // {
    //     lp1(j, n)
    //     {
    //         cout << vis[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    cout << count << endl;
}

int main()
{
    // for t test cases
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        cout << "Case #" << t << ": ";
        solve();
        memset(arr, -1, sizeof(arr));
        memset(vis, 0, sizeof(vis));
        memset(mine, ' ', sizeof(mine));
        t++;
    }
}