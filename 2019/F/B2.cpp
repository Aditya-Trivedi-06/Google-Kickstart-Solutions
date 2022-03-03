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
    int n, s;
    cin >> n >> s;
    set <int> s_vect [1001];
    vector <int> arr[n+1];
    // set <int> ss;

    lp(i, n)
    {
        int c;
        cin >> c;
        lp(j, c)
        {
            int ele;
            cin >> ele;
            arr[i+1].eb(ele);
            s_vect[ele].insert(i+1);
        }
    }

    /*

  skills  1 2 3 4 5
          1 2 4 1 1
          2 3 2 2 2
          3


    */

    ll count = 0;
    for (int i = 1; i <= n; i++)
    {
        count += (n);
        // cerr << i << endl;
        if (arr[i].size() == 1)
        {
            int s_temp = arr[i][0];
            int set_size = s_vect[s_temp].size() - 1;
            count -= set_size;
        }
        else if (arr[i].size() == 2)
        {
            int s1_num = arr[i][0], s2_num = arr[i][1];
            set <int> merge;
            set_intersection(s_vect[s1_num].begin(), s_vect[s1_num].end(), s_vect[s2_num].begin(), s_vect[s2_num].end(), std::inserter(merge, merge.begin()));
            // int set_size = merge.size() - 1;
            // count -= set_size;
        }
        else
        {
            int s1_num = arr[i][0], s2_num = arr[i][1];
            // set<int> s1(s_vect[s1_num].begin(), s_vect[s1_num].begin()), s2(s_vect[s2_num].begin(), s_vect[s2_num].begin()), merge;

            for (int j = 2; j < arr[i].size(); j++)
            {
                int s_num = arr[i][j];
                // set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(merge, merge.begin()));
                // s1.clear();
                // copy(s_vect[s_num].begin(), s_vect[s_num].end(), std::inserter(s1, s1.end()));
            }

            // int set_size = merge.size() - 1;
            // count -= set_size;
        }
    }
    cout << count << endl;
}   

int main()
{
    // for t test cases
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = high_resolution_clock::now();
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        cout << "Case #" << t << ": ";
        solve();
        t++;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << duration.count() / 1000000 << " S " << endl;
}