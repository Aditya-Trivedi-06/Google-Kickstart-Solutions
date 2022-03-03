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

ll table[1000010];
ll n, k;

ll exponent(ll num, int exp)
{
    ll res = 1;
    while (exp != 0)
    {
        if (exp % 2)
            res *= num, res %= mod;
        num *= num;
        num %= mod;
        exp /= 2;
    }
    return res;
}

void solve()
{
    ll x1, y1, c, d, e1, e2, f;
    cin >> n >> k >> x1 >> y1 >> c >> d >> e1 >> e2 >> f;

    ll a[n + 1], x, y;
    a[1] = (x1 + y1) % f;

    for (int i = 2; i <= n; i++)
    {
        x = (c * x1 + d * y1 + e1) % f;
        y = (d * x1 + c * y1 + e2) % f;
        a[i] = (x + y) % f;
        x1 = x;
        y1 = y;
    }

    ll ans = 0;
    ll prev = k;
    ans += (k%mod*n%mod*a[1]%mod) % mod;
    ans %= mod;

    for (int i = 2; i <= n; i++)
    {
        // ll exp = exponent(i, k);
        // cout << exp << endl;
        // exp *= i;
        // exp %= mod;
        prev = prev + (((i % mod * ((exponent(i, k) % mod - 1 % mod) % mod) % mod)) % mod * exponent((i - 1), mod - 2) % mod) % mod;
        prev %= mod;
        ans += (a[i] % mod * (n - i + 1) % mod * prev % mod) % mod;
        ans %= mod;
    }
    // lp(i, n+1)
    //     cout << table[i] << ' ';
    // cout << endl;
    cout << ans << endl;
}

int main()
{
    // for t test cases
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // auto start = high_resolution_clock::now();
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        cout << "Case #" << t << ": ";
        solve();
        t++;
    }
    memset(table, 0, sizeof(table));
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << duration.count() / 1000000 << " S " << endl;
}