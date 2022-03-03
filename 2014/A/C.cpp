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

#define INF INT_MAX

using namespace std;
using namespace std::chrono;

void solve()
{
    ll n, m;
    cin >> n >> m;

    map <int, int, greater<int>> s, avail;

    lp(i, n)
    {
        int ele;
        cin >> ele;
        s[ele]++;
    }

    avail.insert(mp(m, 1));

    while (!s.empty())
    {
        auto cur_it = *s.begin();
        ll cur_len = cur_it.ff, cur_count = cur_it.ss;
        
        if (cur_count == 0)
        {
            s.erase(s.begin());
            continue;
        }

        ll len = pow(2, cur_len);

        auto avail_it = avail.begin();
        ll avail_len = avail_it->ff, avail_count = avail_it->ss;

        if (avail_len > len)
        {
            ll diff = avail_len - len;
            ll num = avail_len / diff;
            
            avail.insert(mp(diff, ))
        }

        else if (avail_len == len)
        {
            if (avail_count > cur_count)
            {
                avail[len] -= cur_count;
                s.erase(s.begin());
            }
            else if (avail_count == cur_count)
            {
                avail.erase(avail.begin());
                s.erase(s.begin());
            }
        }
    
        else if (avail_len < len)
        {
            avail.insert(mp(m, 1));
        }
    }
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
        solve();
        // cerr << "Case : " << t << " Solved !" << endl;
        t++;
    }
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cerr << duration.count() / 1000000 << " S " << endl;
}