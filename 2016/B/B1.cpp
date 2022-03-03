// https://codeforces.com/blog/entry/46881

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

#define mod 1000000007

// Yes/ No for CodeForces ---------------
// # define 	yes 			cout << "YES" << endl
// # define 	no 				cout << "NO" << endl

using namespace std;

ll exp_pow(ll num, ll n, ll k)
{
    if (n == 0)
        return 1;

    if (n == 1)
        return num % k;

    if (n % 2)
        return num * exp_pow((num * num) % k, (n - 1) / 2, k) % k;

    return exp_pow((num * num) % k, n / 2, k) % k;
}

void fill_arr(ll n,ll expo, ll k, vector <ll> &dp)
{
    lp1(i, k)
        dp.eb(0);

    lp1(i, k)
    {
        ll r = exp_pow(i, expo, k) % k;
        ll x = (n - i) / k;
        dp[r] += (x + 1);
    }
}

void solve()
{
    ll a, b, n, k;
    cin >> a >> b >> n >> k;
    ll count = 0;
    vector <ll> dp1, dp2;

    fill_arr(n, a, k, dp1);
    fill_arr(n, b, k, dp2);

    lp1(i, k)
    {
        cout << dp1[i] << ' ';
    }
    cout << endl;
    lp1(i, k)
    {
        cout << dp2[i] << ' ';
    }
    cout << endl;
    cout << count << endl;
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
        solve();
        t++;
    }
}