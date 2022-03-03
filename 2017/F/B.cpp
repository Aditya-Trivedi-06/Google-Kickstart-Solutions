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

int n;
vect;

bool even()
{
    int mid = (n - 1) / 2;
    int l = mid;
    int r = mid + 1;
    int max_num = n, min_num = 1;

    for (int i = 0; i < n / 2; i++)
    {
        int num = v[l];

        // cout << l << ' ' << r << endl;

        if (num == max_num)
            max_num--;
        else if (num == min_num)
            min_num++;
        else
            return false;

        num = v[r];

        if (num == max_num)
            max_num--;
        else if (num == min_num)
            min_num++;
        else
            return false;

        l--;
        r++;
    }
}

bool odd()
{
    int mid = (n - 1) / 2;
    int max_num = n, min_num = 1;

    if (n % 2)
    {
        if (v[mid] == max_num)
            max_num--;
        else if (v[mid] == min_num)
            min_num++;
        else
            return false;
    }

    for (int i = 1; i < n / 2; i++)
    {
        int num = v[mid - i];

        if (num == max_num)
            max_num--;
        else if (num == min_num)
            min_num++;
        else
            return false;

        num = v[mid + i];

        if (num == max_num)
            max_num--;
        else if (num == min_num)
            min_num++;
        else
            return false;
    }

    return true;
}

void solve()
{
    cin >> n;
    vectin(v, n);

    if (n % 2)
    {
        if (odd())
        {
            cout << "YES" << endl;
            return;
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }
    else
    {
        if (even())
        {
            cout << "YES" << endl;
            return;
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }
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
        v.clear();

        t++;
    }
}