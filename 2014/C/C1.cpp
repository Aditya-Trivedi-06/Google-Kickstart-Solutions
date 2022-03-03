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

int arr[10], n;

ll factors[1000005];

int min_press(int num)
{
    string s = to_string(num);
    bool direct_poss = true;
    for (auto i : s)
    {
        if (!arr[i - '0'])
        {
            direct_poss = false;
            break;
        }
    }
    if (direct_poss)
    {
        return s.size() + 1;
    }

    ll min_num = INT32_MAX;
    bool isprime = true;
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (!(num % i))
        {
            isprime = false;
            ll press = factors[i] + factors[num / i];
            // cout << n << ' ' << press << endl;
            min_num = min(min_num, press);
        }
    }
    
    if (isprime)
        return INT32_MAX;
    
    return min_num;
}

int answer()
{
    string sn = to_string(n);
    bool direct_poss = true;
    for (auto i : sn)
    {
        if (!arr[i - '0'])
        {
            direct_poss = false;
            break;
        }
    }

    if (direct_poss)
    {
        return sn.size() + 1;
    }
    
    vector <int> temp;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (!(n % i))
        {
            temp.eb(i);
            temp.eb(n / i);
        }
    }
    SORT(temp);
    // vectprint(temp);
    // cout << endl;
    for (auto i : temp)
    {
        factors[i] = min_press(i);
    }

    ll ans = INT32_MAX;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (!(n % i))   
        {
            ll press = factors[i] + factors[n / i];
            ans = min(press, ans);
        }
    }

    return ans;
}

void solve()
{
    lp(i, 10)
        cin >> arr[i];
    
    cin >> n;

    ll res = answer();
    if (res == INT32_MAX)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    cout << res << endl;
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
        lp(i, 1000004)
            factors[i] = INT16_MAX;
        solve();
        t++;
    }
}