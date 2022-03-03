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

void solve()
{
    int n, k;
    cin >> n >> k;
    int max_day = 0;
    map <int, int> m;
    vect;

    lp(i, n)
    {
        int ele;
        cin >> ele;
        m[ele]++;
        max_day = max(max_day, ele);
    }
    // cout << max_day << endl;

    for (auto i : m)
        v.eb(i.first);

    int sum = 0, cur_day = v[0], it = 0;
    for (int i = 0; i < max_day; ++i)
    {
        int day_count = 0;
        while(day_count < k)
        {
            if (it >= v.size())
                break;

            cur_day = v[it];

            if (cur_day > max_day)
                break;

            int diff = k - day_count;
            if (m[cur_day] <= diff)
            {
                day_count += m[cur_day];
                it++;
            }
            else 
            {
                m[cur_day] -= diff;
                day_count = k;
                break;
            }
            // cout << cur_day << endl;
            // cout << day_count << endl;
        }
        // cout << day_count << ' ';
        sum += day_count;
        cur_day = v[it];
        if (cur_day > max_day)
            break;
        
        while(i + 1 >= cur_day)
        {
            it++;
            if (it >= v.size())
            {
                cout << sum << endl;
                return;
            }
            cur_day = v[it];
        }

        // cout << "INDEX : " << cur_day << endl;
    }
    // cout << endl;


    // for (auto i : m)
    //     cout << i.first << ' ' << i.second << endl;
    // cout << endl;

    cout << sum << endl;
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