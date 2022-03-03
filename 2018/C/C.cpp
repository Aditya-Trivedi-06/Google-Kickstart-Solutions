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

ll table[1000005], arr[1000005], sum[1000005];
ll n, k;

// ll exponent(ll num, int exp)
// {
//     if (exp == 0)
//         return 1;

//     if (exp == 1)
//         return (num % mod);

//     num %= mod;
    
//     if (exp % 2)
//         return (num * exponent((num*num) % mod, (exp-1) / 2)) % mod;
    
//     return exponent((num*num) % mod, exp / 2);
// }

void fill()
{
    memset(table, 0, sizeof(table));
    memset(sum, 0, sizeof(sum));

    table[1] = 1;
    arr[0] = 0;
    sum[1] = 1;
    lp1(i, n)
        arr[i] = arr[i-1] + i;

    for (int j = 1; j <= k; j++)
    {
        for (int i = 2; i <= n; i++)
        {
            table[i] = (table[i - 1] + arr[i]) % mod;
            sum[i] += table[i];
            sum[i] %= mod;
            arr[i] *= i;
            arr[i] %= mod;
        }
    }
}

void solve()
{
    int x1, y1, c, d, e1, e2, f;
    cin >> n >> k >> x1 >> y1 >> c >> d >> e1 >> e2 >> f;

    ll x[n+1], y[n+1], a[n+1];
    x[1] = x1;
    y[1] = y1;
    a[1] = (x1 + y1) % f;
    
    for (int i = 2; i <= n; i++)
    {
        x[i] = (c * x[i-1] + d * y[i-1] + e1) % f;
        y[i] = (d * x[i-1] + c * y[i-1] + e2) % f;
        a[i] = (x[i] + y[i]) % f;
    }

    ll total_sum = 0;

    // lp1(i, n)
    //     cout << a[i] << ' ';
    // cout << endl;

    // 2 3 1 2 1 2 1 1 9

    fill();

    lp1(g, n)
            cout << sum[g] << ' '; 
    cout << endl;

    // for (int i = 1; i <= k; i++)
    // {

        

    //     for (int j = 1; j <= n; j++)
    //     {
    //         ll num = a[j] % mod;
    //         ll multiply = table[j] % mod;
    //         // cout << num << ' ' << multiply << endl;
    //         ll prod = ((num * multiply) % mod);
    //         // cout << "Before : " << prod; 
    //         prod *= (n-j+1);
    //         prod %= mod;
    //         // cout << "  After : " << prod << ' ';
    //         sum += prod;
    //         sum %= mod;
    //         // cout << endl;
        // }

        // cout << "Sum : " << sum << endl;
    // }

    // cout << sum % mod << endl;
}

int main()
{
    // for t test cases
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // fill();
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        cout << "Case #" << t << ": ";
        solve();
        t++;
    }
}