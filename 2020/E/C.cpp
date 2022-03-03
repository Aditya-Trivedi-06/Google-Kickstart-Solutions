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

int n;
int p[100005], f[100005];
bool indef = false;
ll max_num = 0;
int min_count = INT_MAX;

ll check(vector <bool> &v)
{
    auto it = find(v.begin(), v.end(), 1);

    if (it == v.end())
        return INT_MIN;

    ll total_max_time = 0, max_time = 0;
    int excl_count = 0;
    lp(i, n)
    {
        if (v[i])
            max_time += p[i];
        else
            excl_count++;
    }
    
    total_max_time = max_time;
    int i = 0;
    for (i; i < n; i++)
    {
        if (v[i])
        {
            ll min_time = f[i];
            if (min_time > max_time - p[i])
            {
                if (total_max_time > max_num)   
                {
                    max_num = total_max_time;
                    min_count = excl_count;
                }
                else if (total_max_time == max_num)
                {
                    if (excl_count < min_count)
                        min_count = excl_count;
                }
                return total_max_time;
            }
            else
            {
                total_max_time += p[i];
            }
        }
    }
    indef = true;
    if (max_num != INT64_MAX)
    {
        min_count = excl_count;
    }
    else
    {
        min_count = min(min_count, excl_count);
    }
    max_num = INT64_MAX;
    return INT64_MAX;
}

ll rec(int index, vector <bool> v)
{
    if (index == n)
    {
        return check(v);
    }
    
    v.eb(1);
    ll incl = rec(index + 1, v);
    v.pop_back();
    v.eb(0);
    ll excl = rec(index + 1, v);

    return max(incl, excl);
}

void solve()
{
    cin >> n;

    memset(p, 0, sizeof(p));
    memset(f, 0, sizeof(f));

    lp(i, n)
        cin >> p[i] >> f[i];
    
    // for (int i = 0; i < n; i++)
    // {
    //     cout << p[i] << ' ' << f[i] << endl;
    // }

    vector <bool> v;
    ll num = rec(0, v);
    if (indef or num == INT64_MAX)
    {
        cout << "INDEFINITELY" << ' ' << min_count << endl;
        return;
    }
    cout << max_num << ' ' << min_count << endl;
}

int main()
{
    // for t test cases
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // auto start = high_resolution_clock::now();
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        cout << "Case #" << t << ": ";
        // cout << endl;
        solve();
        indef = false;
        max_num = 0;
        min_count = INT_MAX;
        t++;
    }
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cerr << duration.count() / 1000000 << " S " << endl;
}