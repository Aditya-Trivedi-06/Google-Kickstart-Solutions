#include <bits/stdc++.h>
# include <chrono>

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

ll binomial_coeff(ll n, ll k)
{
    if (n < k or k == 0)
        return 0;

    if (n == k or k == 1)
        return 1;

    ll dp[n + 1][k + 1]{};

    dp[0][0] = 1;
    dp[1][1] = 1;

    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= min(k, i); j++)
        {
            if (j == 0 or j == i)
            {
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    return dp[n][k];
}

void solve()
{
    int n;
    cin >> n;
    unordered_map <ll, ll> m;
    vectl;
    lp(i, n)
    {
        ll ele;
        cin >> ele;
        vl.eb(ele);   
        m[ele]++;
    }
    SORT(vl);
    ll count = 0, zero_count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        unordered_map <ll, ll> temp = m;

        for (int j = i + 1; j < n; j++)
        {   
            // if (vl[i] == 0)
            //     continue;

            // ll prod = vl[i] * vl[j];
            // // cout << prod << endl;
            // if (vl[i] == 1)
            // {
            //     if (prod == 1)
            //     {
            //         if (temp[prod] > 2)
            //         {
            //             count += (temp[prod] - 2);
            //         }
            //     }
            //     else
                // {
                //     if (temp[prod] > 1)
                //     {
                //         count += (temp[prod] - 1);
                //     }
                // }
            // }

            // else 
            // {
            //     if (temp.find(prod) != temp.end())
            //         count += temp[prod];
            // }
            temp[vl[j]]--;
            // cout << "ONE" << temp[1] << " Count " << count << endl;
        }
        // cout << "ONE : " <<  m[1] << endl;
        // m[vl[i]]--;
    } 

    int i = 0;
    ll sum = 0;
    // while (vl[i] == 0)
    //     zero_count++, i++;
    
    
    // sum = binomial_coeff(zero_count, 3) + (binomial_coeff(zero_count, 2) * (n-zero_count));

    cout << count + sum << endl;
}
using namespace std::chrono;
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
    cout << duration.count() / 100 << endl;
}