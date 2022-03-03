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
#define dlp(i, j, r, c)         \
    for (int i = 0; i < r; i++) \
        for (int j = 0; j < c; j++)

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
#define vectch vector<char> vch

#define mp make_pair
#define eb emplace_back
#define pb push_back

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

#define prime 1000000007

// Yes/ No for CodeForces ---------------
// # define 	yes 			cout << "YES" << endl
// # define 	no 				cout << "NO" << endl

using namespace std;

void solve()
{

    int n;
    cin >> n;

    string s;
    cin >> s;

    int dp[n] {};

    lp(i, n)
    {
        if (s[i] == '1')
            dp[i] = 1;
    }

    int left[n], right[n];

    fill(left, left + n, INT16_MAX);
    fill(right, right + n, INT16_MAX);

    int rcnt = 1000001, lcnt = 1000001;

    int ans[n];

    lp(i, n)
    {
        if (dp[i] == 1)
            rcnt = 0;

        if(dp[n-1-i] == 1)
            lcnt = 0;

        left[i] = rcnt;
        right[n-i-1] = lcnt;
        rcnt++;
        lcnt++;
    }

    lp(i, n)
        ans[i] = min(left[i], right[i]);

    // for (auto i : left)
    //     cout << i << ' ';
    // cout << endl;

    // for (auto i : right)
    //     cout << i << ' ';
    // cout << endl;

    ll sum = 0;

    for (auto i : ans)
        sum += i;
    
    cout << sum << endl;
}

int main()
{
    // for t test cases

    // freopen("output.txt", "r", stdin);
    // freopen("test.txt", "w", stdout);

    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        cout << "Case #" << t << ": ";
        solve();
        t++;
    }
    // fclose(stdout);
}