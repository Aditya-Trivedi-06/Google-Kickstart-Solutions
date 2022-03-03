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
    int d, n, k;
    cin >> d >> n >> k;

    multimap < pair <int, int>, int> m;

    lp(i, n)
    {
        int h, s, e;
        cin >> h >> s >> e;

        m.insert(mp(mp(s, e), h));
    }

    ll gmax = 0;

    for (auto i : m)
    {
        cout << i.first.first << ' ' << i.first.second << ' ' << i.second << endl;
    }

    for (auto it = m.begin(); it != m.end(); it++)
    {
        multiset <int, greater <int>> ms;
        ms.insert(it->second);
        int e1 = it->first.second;

        for (auto it2 = next(it); it2 != m.end(); it2++)
        {
            int s2 = it2->first.first;
            if(s2 > e1)
                break;

            ms.insert(it2->second);
        }
        ll temph = 0, cnt = 0;
        for (auto i : ms)
        {
            temph += i;
            cnt ++;
            if (cnt >= k)
                break;
        }
        gmax = max(gmax, temph);
    }

    cout << gmax << endl;
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
    // fclose(stdout);
}