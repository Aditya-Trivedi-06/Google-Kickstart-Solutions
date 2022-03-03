#include <bits/stdc++.h>
#include <chrono>

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

#define vect(v) vector<int> v
#define vectl(vl) vector<long long> vl
#define vectodd(vodd) vector<int> vodd
#define vecteven(veven) vector<int> veven
#define vects(vs) vector<string> vs

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
using namespace std::chrono;

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll p[n], h[n], x[k], y[k];
    ll A1, B1, C1, M1;
    ll A2, B2, C2, M2;
    ll A3, B3, C3, M3;
    ll A4, B4, C4, M4;

    cin >> p[0] >> p[1] >> A1 >> B1 >> C1 >> M1;
    cin >> h[0] >> h[1] >> A2 >> B2 >> C2 >> M2;
    cin >> x[0] >> x[1] >> A3 >> B3 >> C3 >> M3;
    cin >> y[0] >> y[1] >> A4 >> B4 >> C4 >> M4;

    for (int i = 2; i < n; i++)
    {   
        p[i] = (A1 * p[i-1] + B1 * p[i-2]+ C1) % M1 + 1;
        h[i] = (A2 * h[i-1] + B2 * h[i-2]+ C2) % M2 + 1;
    }
    for (int i = 2; i < k; i++)
    {
        x[i] = (A3 * x[i - 1] + B3 * x[i - 2] + C3) % M3 + 1;
        y[i] = (A4 * y[i - 1] + B4 * y[i - 2] + C4) % M4 + 1;
    }

    int count = 0;
    for (int i = 0; i < k; i++)
    {
        int cur_x = x[i], cur_y = y[i];
        for (int j = 0; j < n; j++)
        {
            int pos = p[j], height = h[j];
            int diff = abs(pos - cur_x);
            if (diff + cur_y <= height)
            {
                count++;
                break;
            }
        }
    }
    cout << count << endl;
}

int main()
{
    // for t test cases
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // auto start = high_resolution_clock::now();
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        cout << "Case #" << t << ": ";
        // cout << endl;
        solve();
        t++;
    }
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << duration.count() / 1000000 << " S " << endl;
}