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

# define INF INT_MAX

int n;
map <string, vector <int>> color;
vector <pair <int, int>> adj[80001];

int shortest_path(int src, int dst)
{
    set <pair<int, int>> s;
    vector <int> dis(n+1, INF);
    dis[src] = 0;
    s.insert(mp(0, src));

    while(!s.empty())
    {
        // cout << s.size() << endl;
        auto it = *s.begin();
        s.erase(s.begin());
        int cur = it.ss;

        for (auto i : adj[cur])
        {
            if (dis[i.ff] > dis[cur] + i.ss)
            {
                if (dis[i.ff] != INF)
                    s.erase(s.find(mp(dis[i.ff], i.ff)));
                
                dis[i.ff] = dis[cur] + i.ss;
                s.insert(mp(dis[i.ff], i.ff));
            }
        }
    }

    return dis[dst];
}

void solve()
{
    cin >> n;
    lp1(i, n+1)
    {
        string s;
        cin >> s;
        color[s].eb(i);
    }

    for (auto i : color)
    {
        auto it = i.ss;
        
        for (int j = 0; j < it.size(); j++)
        {
            for (int k = 0; k < it.size(); k++)
            {
                if (j == k)
                    continue;
                
                adj[it[j]].eb(mp(it[k], 0));
            }
        }
    }

    int m;
    cin >> m;

    lp(i, m)
    {
        int s, d, t;
        cin >> s >> d >> t;
        adj[s].eb(mp(d, t));
    }
    
    // lp1(i, n)
    // {
    //     cout << i << " : ";
    //     for (auto j : adj[i])
    //         cout << j.ff << ' ' << j.ss << ' ' << endl;
    //     cout << endl;
    // }

    // cout << shortest_path(2, 6);

    int s;
    cin >> s;

    lp(i, s)
    {
        int src, dst;
        cin >> src >> dst;

        int ans = shortest_path(src, dst);
        if (ans == INF)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }

}

int main()
{
    // for t test cases
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // auto start = high_resolution_clock::now();
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        cout << "Case #" << t << ":" << endl;
        solve();
        color.clear();
        lp(i, 80001)
            adj[i].clear();
        // cerr << "Case : " << t << " Solved !" << endl;
        t++;
    }
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cerr << duration.count() / 1000000 << " S " << endl;
}