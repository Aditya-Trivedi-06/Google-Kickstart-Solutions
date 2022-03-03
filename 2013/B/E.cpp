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

int t = 1;

char arr[105][105];

void solve()
{
    int n;
    cin >> n;

    int rcount = 0, bcount = 0;

    lp(i, n)
    {
        lp(j, n)
        {
            cin >> arr[i][j];
            
            if (arr[i][j] == 'B')
                bcount++;

            else if (arr[i][j] == 'R')
                rcount++;
        }
    }

    if (t == 18)
    {
        lp(i, n)
        {
            lp(j, n)
            {
                cout << arr[i][j];
            }
            cout << endl;
        }
    }

    if (abs(bcount - rcount) > 1)
    {
        cout << "Impossible" << endl;
        return;
    }

    int row_red_count = 0, row_blue_count = 0;

    for (int i = 0; i < n; i++)
    {
        char temp = arr[i][0];

        if (temp == '.')
            continue;

        int j = 1;
        for (j; j < n; j++)
        {
            if (arr[i][j] != temp)
                break;
        }
        if (j == n)
        {
            if (temp == 'R')
                row_red_count++;
            else
                row_blue_count++;
        }
    }

    if (row_blue_count > 1 and row_blue_count > 1)
    {
        cout << "Impossible" << endl;
        return;
    }
    if (row_red_count == 1)
    {
        cout << "Red wins" << endl;
        return;
    }
    if (row_blue_count == 1)
    {
        cout << "Blue wins" << endl;
        return;
    }

    int col_red_count = 0, col_blue_count = 0;

    for (int i = 0; i < n; i++)
    {
        char temp = arr[0][i];

        if (temp == '.')
            continue;

        int j = 1;
        for (j; j < n; j++)
        {
            if (arr[j][i] != temp)
                break;
        }
        if (i == n)
        {
            if (temp == 'R')
                col_red_count++;
            else
                col_blue_count++;
        }
    }

    if (col_blue_count > 1 and col_blue_count > 1)
    {
        cout << "Impossible" << endl;
        return;
    }
    if (col_red_count == 1)
    {
        cout << "Red wins" << endl;
        return;
    }
    if (col_blue_count == 1)
    {
        cout << "Blue wins" << endl;
        return;
    }

    cout << "Nobody wins" << endl;
}

int main()
{
    // for t test cases
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // auto start = high_resolution_clock::now();
    int T;
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