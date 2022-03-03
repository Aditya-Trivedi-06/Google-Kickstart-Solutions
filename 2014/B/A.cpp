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

#define mod 1000000007

using namespace std;

ll dp[105];

ll fast_expo(ll num, ll exp_n)
{
    if (exp_n == 0)
        return 1;

    if (exp_n == 1)
        return num % mod;
    
    if (exp_n % 2)
        return num * fast_expo((num * num)% mod, (exp_n - 1)/ 2) % mod;
    
    return fast_expo((num * num) % mod, exp_n / 2) % mod;

}

ll binomcoeff(int n, int k)
{
    ll C[k + 1];
    memset(C, 0, sizeof(C));

    C[0] = 1; // nC0 is 1

    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i, k); j > 0; j--)
        {
            C[j] = C[j] + C[j - 1];
            C[j] %= mod;
        }
    }
    return C[k];
}

void solve()
{
    int m, n;
    cin >> m >> n;

    dp[1] = 1;

    for (int i = 2; i <= m; i++)
    {
        ll sum = fast_expo(i, n) % mod;
        // cout << sum << endl;
        ll subs = 0;
        
        for (int j = 1; j < i; j++)
        {
            ll comb = binomcoeff(i, j) % mod;
            comb *= (dp[j] % mod);
            comb %= mod;
            sum -= comb;
        }
        cout << sum << endl;
        dp[i] = sum;
        dp[i] %= mod;
    }

    for (int i = 1; i <= m; i++)
        cout << dp[i] << ' ';
    cout << endl;

}

int main()
{
    // for t test cases
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        cout << "Case #" << t << ": ";
        solve();
        memset(dp, 0, sizeof(dp));
        t++;
    }
}