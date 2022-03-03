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

int arr[101][101];

void fill()
{
    memset(arr, 0, sizeof(arr));

    arr[0][2] = -1;
    arr[1][1] = -1;
    arr[2][0] = -1;

    lp(i, 100)
    {
        lp(j, 100)
        {
            if (i >= 3)
                if (arr[i-3][j] == -1)
                    arr[i][j] = -1;

            if (j >= 3)
                if (arr[i][j-3] == -1)
                    arr[i][j] = -1;
        }
    }
}

void solve()
{
    int r, c;
    cin >> r >> c;

    if (r == 2 and c == 2)
    {
        cout << 4 << endl;
        return;
    }
    if (r == 2)
    {
        int num = c / 3;
        int rem = c % 3;
        cout << num * 4 + rem * 2 << endl;
        return;
    }
    if (c == 2)
    {
        int num = r / 3;
        int rem = r % 3;
        cout << num * 4 + rem * 2 << endl;
        return;
    }
   
    int count = 0;
    lp(i, r)
    {
        lp(j, c)
        {
            if (arr[i][j] == 0)
                count++;
            // cout << arr[i][j] << ' ';
        }
        // cout << endl;
    }

    cout << count << endl;
}

int main()
{
    // for t test cases
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t = 1, T;
    cin >> T;
    fill();
    while (t <= T)
    {
        cout << "Case #" << t << ": ";
        // cout << endl;
        solve();
        t++;
    }
}