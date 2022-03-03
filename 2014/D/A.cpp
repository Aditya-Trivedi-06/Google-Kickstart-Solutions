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

int maze[1005][1005];

bool isValid(int curx, int cury, int x, int y, int n)
{
    return (x >= 0 and y >= 0 and x < n and y < n and maze[x][y] == maze[curx][cury] + 1);
}

int dfs(int x, int y, int n)
{
    if (isValid(x, y, x+1, y, n))
        return 1 + dfs(x+1, y, n);

    else if (isValid(x, y, x-1, y, n))
        return 1 + dfs(x-1, y, n);

    else if (isValid(x, y, x, y+1, n))
        return 1 + dfs(x, y+1, n);

    else if (isValid(x, y, x, y-1, n))
        return 1 + dfs(x, y-1, n);

    else return 0;
}

void solve()
{
    int n;
    cin >> n;

    lp(i, n)
        lp(j, n)
            cin >> maze[i][j];
    
    int max_ans = 0, max_num;

    lp(i, n)
    {
        lp(j, n)
        {
            int cur = dfs(i, j, n);
            if (cur + 1 > max_ans)
            {
                max_ans = cur + 1;
                max_num = maze[i][j];
            }
            else if (cur + 1 == max_ans)
            {
                max_num = min(max_num, maze[i][j]);
            }
        }
    }

    cout << max_num << ' ' << max_ans << endl;
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
        t++;
    }
}