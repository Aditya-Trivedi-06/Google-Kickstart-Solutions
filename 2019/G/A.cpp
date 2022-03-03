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

using namespace std;

int table[100005];

void solve()
{
    int n, m, q, ele;
    cin >> n >> m >> q;

    for (int i = 0; i < m ; i ++)
    {
        int ele;
        cin >> ele;

        for (int j = 1; j <= sqrt(ele); j++)
        {
            // cout << ele << " : ";
            if (!(ele %  j))
            {
                // cout << ele / j << ' ';
                table[j]++;
                if (ele / j != j)
                    table[ele / j]++;
            }
            // cout << endl;
        }
    }

    // cout << endl;
    
    vector <int> read;

    for (int i = 0; i < q; i++)
    {
        int ele;
        cin >> ele;
        read.eb(ele);
    }

    ll ans = 0;

    // for (int i = 0; i <= n; i++)
    // {
    //     cout << table[i] << ' ';
    // }
    // cout << endl;

    for (int i = 0; i < q; i++)
    {
        int num = read[i], temp;
        temp = n / num;

        int cnt = table[num];

        temp -= cnt;
        ans += temp;
    }

    cout << ans << endl;
}

int main()
{
    // for t test cases
    // freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        cout << "Case #" << t << ": ";
        memset(table, 0, sizeof(table));
        solve();
        t++;
    }
}