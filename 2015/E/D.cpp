#include <bits/stdc++.h>

#define ll long long
#define ld double
#define ull unsigned long long

#define ff first
#define ss second

// For Loops ----------------------------

#define lp(i, n) for (ll i = 0; i < n; i++)
#define lp1(i, n) for (ll i = 1; i <= n; i++)

// Vectors / pairs / maps  ---------------

#define pairll pair<ll, ll> pll
#define pairll pair<ll, ll> pll

#define mapn map<ll, ll> mll
#define mapll map<ll, ll> mll

#define vect vector<ll> v
#define vectl vector<long long> vl
#define vectodd vector<ll> vodd
#define vecteven vector<ll> veven
#define vects vector<string> vs

#define eb emplace_back
#define pb push_back

#define mp make_pair

#define vectin(v, n)           \
    for (ll i = 0; i < n; i++) \
    {                          \
        ll ele;                \
        cin >> ele;            \
        v.eb(ele);             \
    }

#define vectprll(v)       \
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
#define INF INT_MAX

// Yes / No for CodeForces ---------------
// # define 	yes 			cout << "YES" << endl
// # define 	no 				cout << "NO" << endl

using namespace std;

ll n, m, q;
vector<pair<ll, vector<ll>>> adj[505];

void addedge()
{
    ll s, d;
    cin >> s >> d;
    vector<ll> temp;
    vectin(temp, 24);

    adj[s].eb(mp(d, temp));
    adj[d].eb(mp(s, temp));
}

ll shortestpath(ll time, ll dest)
{
    set<pair<ll, ll>> s;
    ll dis[n + 1];
    fill(dis, dis + n + 1, INF);
    dis[1] = 0;
    s.insert(mp(time, 1));

    while (!s.empty())
    {
        pair<ll, ll> p = *s.begin();
        s.erase(s.begin());
        ll cur = p.second, cur_time = p.first;

        for (auto i : adj[cur])
        {
            ll dst = i.first;
            ll wt = i.second[cur_time % 24];
            if (dis[dst] > dis[cur] + wt)
            {
                if (dis[dst] != INF)
                    s.erase(s.find(mp(dis[dst], dst)));

                dis[dst] = dis[cur] + wt;
                s.insert(mp(dis[dst], dst));
            }
        }
    }

    return dis[dest];
}

void solve()
{
    cin >> n >> m >> q;
    lp(i, m)
        addedge();

    vector<pair<ll, ll>> queries;
    lp(i, q)
    {
        ll d, s;
        cin >> d >> s;
        queries.eb(mp(d, s));
    }

    for (auto i : queries)
    {
        ll ans = shortestpath(i.ss, i.ff);
        if (ans == INF)
            cout << -1 << ' ';
        else
            cout << ans << ' ';
    }
    cout << endl;
}

int main()
{
    // for t test cases
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t = 1, T;
    cin >> T;
    while (t <= T)
    {
        cout << "Case #" << t << ": ";
        // cout << endl;
        solve();
        lp(i, 505)
            adj[i]
                .clear();
        t++;
    }
}
#include <bits/stdc++.h>
#include <chrono>

#define ll long long
#define ld double
#define ull unsigned long long

#define ff first
#define ss second

// For Loops ----------------------------

#define lp(i, n) for (ll i = 0; i < n; i++)
#define lp1(i, n) for (ll i = 1; i < n; i++)

// Vectors / pairs / maps  ---------------

#define pairll pair<ll, ll> pll
#define pairll pair<ll, ll> pll

#define mapn map<ll, ll> mll
#define mapll map<ll, ll> mll

#define vect(v) vector<ll> v
#define vectl(vl) vector<long long> vl
#define vectodd(vodd) vector<ll> vodd
#define vecteven(veven) vector<ll> veven
#define vects(vs) vector<string> vs

#define eb emplace_back
#define pb push_back

#define mp make_pair

#define vectin(v, n)           \
    for (ll i = 0; i < n; i++) \
    {                          \
        ll ele;                \
        cin >> ele;            \
        v.eb(ele);             \
    }

#define vectprll(v)       \
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

ll seg_sum(ll n, ll l, ll r, vector<ll> &tree)
{
    ll res = 0;

    // loop to find the sum in the range
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res += tree[l++];

        if (r & 1)
            res += tree[--r];
    }

    return res;
}

void solve()
{
    ll n, q;
    cin >> n >> q;
    ll tempn = n;
    vect(v);
    vectin(v, n);
    
    vector <int> arr[200005];

    vect(tree);

    // cerr << q << ' ' << n << endl;

    vector<pair<ll, ll>> query;
    lp(i, q)
    {
        ll l, r;
        cin >> l >> r;
        query.eb(mp(l, r));
    }

    while (__builtin_popcount(n) != 1)
    {
        n++;
        v.eb(0);
    }
    cerr << "F : " << 2 * n << endl;

    tree.resize(2 * n);

    for (ll i = 0; i < n; i++)
        tree[n + i] = v[i];

    for (ll i = n - 1; i >= 1; i--)
        tree[i] = tree[2 * i] + tree[2 * i + 1];

    // for (auto i : tree)
    //     cout << i << ' ';
    // cout << endl;

    for (ll len = 0; len <= tempn; len++)
    {
        for (ll l = 1; l <= tempn - len; l++)
        {
            ll templ = l - 1;
            ll r = templ + len;
            ll sum = seg_sum(n, templ, r, tree);
            arr[len].eb(sum);
        }
    }

    cerr << "S : " << 2 * n << endl;

    // cout << "SV" << endl;
    // for (auto i : sv)
    //     cout << i << ' ';
    // cout << endl;

    // while (__builtin_popcount(n) != 1)
    // {
    //     n++;
    //     sv.eb(0);
    // }
    // tree.clear();
    // tree.resize(2 * n);

    // for (auto i : sv)
    //     cout << i << ' ';
    // cout << endl;

    // for (ll i = 0; i < n; i++)
    //     tree[n + i] = sv[i];

    // for (ll i = n - 1; i > 0; i--)
    //     tree[i] = tree[2 * i] + tree[2 * i + 1];

    // for (auto i : tree)
    //     cout << i << ' ';
    // cout << endl;

    // lp(i, q)
    // {
    //     ll ql = query[i].ff - 1, qr = query[i].ss - 1;
    //     cout << seg_sum(n, ql, qr, tree) << endl;
    // }
}

int main()
{
    // for t test cases
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = high_resolution_clock::now();
    ll t = 1, T;
    cin >> T;
    while (t <= T)
    {
        cout << "Case #" << t << ':' << endl;
        solve();
        cerr << "CASE  : " << t << " solved." << endl;
        t++;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << duration.count() / 1000000 << " S " << endl;
}