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

#define mod 1000000007

// Yes/ No for CodeForces ---------------
// # define 	yes 			cout << "YES" << endl
// # define 	no 				cout << "NO" << endl

using namespace std;

unordered_map<string, unordered_set<string>> adj;
unordered_set<string> vis, all_e;
unordered_map<string, bool> um;

int is_poss = 1;

void dfs(string cur, bool grp)
{
    // cout << cur << endl;
    vis.insert(cur);
    um.insert(mp(cur, grp));

    for (auto i : adj[cur])
    {
        if(vis.find(i) != vis.end())
        {
            if(um[i] == grp)
            {
                is_poss = 0;
                return;
                // return false;
            }
        }
        if (vis.find(i) == vis.end())
            dfs(i, !grp);
    }

    // return true;
}

void util()
{
    for (auto i : all_e)
    {
        if (vis.find(i) == vis.end())
        {
            dfs(i, 0);
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    lp(i, n)
    {
        string s1, s2;
        cin >> s1 >> s2;

        adj[s1].insert(s2);
        adj[s2].insert(s1);

        all_e.insert(s1);
        all_e.insert(s2);
    }

    util();

    // cout << um.size() << endl;
    // for (auto i : um)
    // {
    //     cout << i.first << " : " << i.ss << endl;
    // }
    
    if (is_poss)
    {
        cout << "Yes" << endl;
        return ;
    }
    else {
        cout << "No" << endl;
        return;
    }
}

int main()
{
    // for t test cases
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        cout << "Case #" << t << ": ";
        // cout << endl;
        solve();
        is_poss = 1;
        adj.clear();
        um.clear();
        vis.clear();
        all_e.clear();
        // cout << endl;
        t++;
    }
}