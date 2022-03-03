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

map<ll, ll> m;
ll n;

void solve()
{
    ll k, p;
    cin >> n >> k >> p;

    lp(i, k)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        m[a] = c;
    }

    ll arr[n] {};

    for (ll i = 0; i < n; i++)
    {
        if (m.find(i+1) == m.end())
            continue;
        
        ll count = m[i+1];
        if (count)
            arr[i] = 1;
    }  

    p--;

    string binary = bitset<128>(p).to_string();

    // cout << binary << endl; 

    ll binary_index = binary.size() - 1;

    for (ll i = n - 1; i >= 0; i--)
    {
        if (m.find(i + 1) != m.end())
            continue;

        else
        {
            ll temp = binary[binary_index] - '0';
            arr[i] = temp;
            binary_index--;
        }
    }

    for (auto i : arr)
        cout << i;
    cout << endl;
}

int main()
{
    // for t test cases
    // freopen("input.txt", "r", stdin);
    // freopen("wrong_output.txt", "w", stdout);
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        cout << "Case #" << t << ": ";
        solve();
        m.clear();
        t++;
    }
}