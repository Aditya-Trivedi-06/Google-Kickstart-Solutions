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

int mat[16][16], n;
vector < pair <int, int>> adj[16];

bool check(vector <int> subs)
{
    if (subs[0] + subs[1] > subs[2])
        return true;

    return false;
}

int sum = 0;

int recur(int cur, vector <int> subs, set <int> vis)
{
    vis.insert(cur);
    

    if (subs.size() == 3)
        if (check(subs))
        {
            sum++;
            return;
        }


    for (cur; cur < n; cur++)
    {
        if (vis.find(cur) == vis.end())
        {
            subs.eb(cur);
            recur(cur, subs, vis);
            vis.erase(cur);
            subs.pop_back();
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    lp(i, n)
        lp(j, n)
            cin >> mat[i][j];
    

    lp(i, n)
        lp(j, n)
            if (mat[i][j])
                adj[i].eb(mp(j, mat[i][j]));
    
    lp(i, n)
    {
        cout << i << " -> ";
        for (auto j : adj[i])
            cout << j.ff << " : " << j.ss << " , ";
        cout << endl;
    }

}

int main()
{
    // for t test cases
    // freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // auto start = high_resolution_clock::now();
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        cout << "Case #" << t << ": ";
        solve();
        for (int i = 0; i < 16; i++)
            adj[i].clear();
        memset(mat, 0, sizeof(mat));
        t++;
    }
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << duration.count() / 1000000 << " S " << endl;
}