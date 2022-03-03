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
#define dlp(i, j, r, c)         \
    for (int i = 0; i < r; i++) \
        for (int j = 0; j < c; j++)

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
#define vectch vector<char> vch

#define mp make_pair
#define eb emplace_back
#define pb push_back

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

#define prime 1000000007

// Yes/ No for CodeForces ---------------
// # define 	yes 			cout << "YES" << endl
// # define 	no 				cout << "NO" << endl

using namespace std;

int ways = 0;

bool safe(int start, int node, bool visited[], int l, int r, int points)
{
    if (node == start)
        return true;
    
    if(visited[node])
        return false;
    
    if (points >= l and points <= r)
        return true;

    else 
        return false;
}

void dfs(int node, int start, int k, int points, int (&a)[], vector <int> adj[], bool (&visited)[], int l[], int r[])
{
    cout << start << ' ';

    visited [start] = 1;
    a[start] = 0;

    if(points > k)
        return;
    
    if (points == k)
    {
        ways ++;
        cout << "ways : " << ways << endl;
        return;
    }

    for (auto i : adj[start])
    {
        if (safe(node, i, visited, l[i], r[i], points))
            dfs(node, i, k, points + a[i], a, adj, visited, l, r);
    }
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    int l[n], r[n], a[n];

    lp(i, n)
        cin >> l[i] >> r[i] >> a[i];

    vector <int> adj[n];

    lp(i, m)
    {
        int s, d;
        cin >> s >> d;

        adj[s].eb(d);
        adj[d].eb(s);
    }



    lp(i, n)
    {
        bool visited[n] {};
        visited[i] = 1;
        int tempa[n];
        memcpy(tempa, a, n);
        dfs(i, i, k, a[i], tempa, adj, visited, l, r);
        cout << endl;
    }

    cout << ways << endl;
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
    // fclose(stdout);
}