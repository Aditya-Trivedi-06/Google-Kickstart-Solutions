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

void solve()
{
    int n, a, b, c;

    cin >> n >> a >> b >> c;

    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }

    if (a + b - c > n)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    if (n < 3)
    {
        if (c == 1)
        {
            if (a == 1 and b == 1)
            {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
            if (a == 1)
            {
                cout << 2 << ' ' << 1 << endl;
                return;
            }
            if (b == 1)
            {
                cout << 1 << ' ' << 2 << endl;
                return;
            }
        }
        else
        {
            cout << "1  1" << endl;
            return;
        }
    }

    if (c == 1)
    {
        if (a == 1 and b == 1)
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        if (b == 1)
        {
            vect;
            lp(i, a - c) v.eb(2);
            lp(i, n - a) v.eb(1);
            v.eb(3);
            vectprint(v);
            cout << endl;
            return;
        }
    }

    vect;
    lp(i, a - c) v.eb(2);
    lp(i, c) v.eb(3);
    lp(i, b - c) v.eb(2);
    lp(i, n - a - b + c) v.insert(v.begin() + a - c + 1, 1);

    vectprint(v);
    cout << endl;
    return;
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
        t++;
    }
}