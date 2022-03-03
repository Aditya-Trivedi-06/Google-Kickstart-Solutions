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

ll arr[2005][3], n, t, sf;
map <pair <ll, ll>, ll> dp;

ll max_city(ll index, ll time)
{
    if (dp.find(mp(index, time)) != dp.end())
        return dp[mp(index, time)];

    if (time > sf)
    {
        return dp[mp(index, time)] = INT16_MIN;
    }

    if (index >= n)
    {
        return dp[mp(index, time)] = 0;
    }

    ll si = arr[index][0], fi = arr[index][1], di = arr[index][2];
    ll incl, excl;

    // Time taken for including the city
    ll diff_incl = time + t - si, next_f;

    if (diff_incl == 0)
        incl = 0;

    else if (diff_incl > 0)
    {
        next_f = ceil((float)diff_incl / fi) * fi;
        incl = next_f - diff_incl;
    }
    else
        incl = abs(diff_incl);
    incl += di;
    incl += t;

    // Time taken for excluding the city
    ll diff_excl = time - si;

    if (diff_excl == 0)
        excl = 0;

    else if (diff_excl > 0)
    {   
        next_f = ceil((double)diff_excl / fi) * fi;
        excl = next_f - diff_excl;
    }
    else
        excl = abs(diff_excl);
    excl += di;

    return dp[mp(index, time)] = max(1 + max_city(index + 1, time + incl), max_city(index + 1, time + excl));
}

void solve()
{
    cin >> n >> t >> sf;

    lp1(i, n)
            cin >> arr[i][0] >> arr[i][1] >> arr[i][2];


    ll ans = max_city(1, 0);
    // for (int i = 1; i <= n; i++)
    //     cout << dp[i] << ' ';
    // cout << endl;

    if (ans == INT16_MAX or ans < 0)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    cout << ans << endl;

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
        memset(arr, 0, sizeof(arr));
        solve();
        dp.clear();
        t++;
    }
}