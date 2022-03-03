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

int n, m;
vector <pair <int, int>> adj[105];
map <pair<int, int>, pair<int, int>> um;
vect(ans);

void addEdge(int s, int d, int c)
{
    adj[s].eb(mp(d, c));
    adj[d].eb(mp(s, c));
}

void shortestpath(int src, set<pair<int, int>> &us)
{
    // cout << "SRC : " << src << endl;
    set< pair< ll, ll>> s;
    vector< ll> dis(n+1, INF);
    s.insert(mp(src, 0));
    dis[src] = 0;

    while (!s.empty())
    {
        // cout << s.size() << endl;
        pair <ll, ll> it = *s.begin();
        s.erase(s.begin());

        ll cur = it.ss, cur_cost = it.ff;

        for (auto i : adj[cur])
        {
            ll dst = i.ff;
            if (dis[dst] > dis[cur] + cur_cost)
            {
                if (dis[dst] != INF)
                {
                    us.erase(us.find(mp(cur, dst)));
                    s.erase(s.find(mp(dis[dst], dst)));
                }
                
                dis[dst] = dis[cur] + cur_cost;
                us.insert(mp(cur, dst));
                s.insert(mp(dis[dst], dst));
            }
            // cout << dst << endl;
        }
    }
}

void util()
{
    lp(i, n)
    {
        // cout << i << endl;
        set <pair<int, int>> us;
        shortestpath(i, us);
        // cout << i << ' ' << " DONE" << endl;
        for (auto i : us)
        {
            auto it = um.find(i);
            if (it != um.end())
                um.erase(it);
        }
    }
}

void solve()
{
    cin >> n >> m;
    lp(i, m)
    {
        int s, d, c;
        cin >> s >> d >> c;

        auto it = um.find(mp(s, d));
        if (it != um.end())
        {
            auto p = it->second;
            if (c > p.ss)
            {
                ans.eb(i);
            }
            else
            {
                auto rem = find(ALL(adj[s]), mp(d, p.ss));
                auto rem2 = find(ALL(adj[d]), mp(s, p.ss));
                
                adj[s].erase(rem);
                adj[d].erase(rem2);
                addEdge(s, d, c);
            }
        }
        it = um.find(mp(d, s));
        if (it != um.end())
        {
            auto p = it->second;
            if (c > p.ss)
            {
                ans.eb(i);
            }
            else
            {
                auto rem = find(ALL(adj[s]), mp(d, p.ss));
                auto rem2 = find(ALL(adj[d]), mp(s, p.ss));
                
                adj[s].erase(rem);
                adj[d].erase(rem2);
                addEdge(s, d, c);
            }
        }
        um.insert(mp(mp(s, d), mp(i, c)));
    }

    util();

    // cout << "DONE" << endl;

    vect(v);
    for (auto i : um)
    {
        v.eb(i.ss);
    }

    SORT(v);
    lp(i, m)
    {
        if (find(ALL(v), i) != v.end())
            continue;
        else
            cout << i << endl;
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
        cout << "Case #" << t << ": " << endl;
        solve();
        for (int i = 0; i < 105; i++)
            adj[i].clear();
        um.clear();
        t++;
    }
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cerr << duration.count() / 1000000 << " S " << endl;
}