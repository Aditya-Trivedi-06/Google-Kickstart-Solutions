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

// long double exp_pow(long double num, int exp)
// {
//     if (num > mod)
//         num -= mod;

//     if (exp == 0)
//         return 1;
    
//     if (exp == 1)
//         return num;

//     if (exp % 2)
//         return ((num * exp_pow(num*num, (exp - 1)/2)));
    
//     return exp_pow(num*num, exp / 2);
// }   

long double nth(ll num, int d)
{
    long double low = 1, high = (long double)num;
    long double mid;
    for (int i = 0; i < 100; i++)
    {
        mid = low + (high - low) / (float)2;
        // cout << mid << endl;
        long double mid_to_n = pow(mid, d);
        // cout << mid_to_n << endl;

        if (mid_to_n > mod)
            mid_to_n -= mod;

        if (mid_to_n > num)
            high = mid;

        else
            low = mid + 1;
        
        // cout << high << endl;
    }
    return high;
}

void solve()
{
    cout << fixed;
    cout << setprecision(9);

    int n, m;
    cin >> n >> m;

    vectl;

    lp(i, n)
    {
        ll ele;
        cin >> ele;
        vl.eb(ele);
    }

    lp(i, m)
    {
        int l, r;
        cin >> l >> r;

        ll m_vol = 1;
        for (int j = l; j <= r; j++)
        {
            m_vol *= vl[j];
            if (m_vol > mod)
                m_vol -= mod;
        }
        
        // cout << "VOLUME : " << m_vol << endl;

        long double length = exp(log(m_vol));

        // long double length = nth(m_vol, (r-l+1));
        // long double length = pow(m_vol, 1.0 / (r-l+1));
        cout << length<< endl;
    }
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
        cout << "Case #" << t << ": " << endl;
        solve();
        t++;
    }
}