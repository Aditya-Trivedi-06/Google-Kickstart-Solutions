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

// ABCDEFGHIJKLMNOPQRSTUVWXYZ

void solve()
{
    string s;
    cin >> s;
    int len = s.size();

    if (len % 2)
    {
        cout << "AMBIGUOUS" << endl;
        return;
    }

    if (len == 2)
    {
        cout << s[1] << s[0] << endl;
        return;
    }

    char ans[len];
    int num[len], ans_num[len];

    for (int i = 0; i < len; i++)
        num[i] = s[i] - 'A';
    
    // lp(i, len)
    //     cout << num[i] << ' ';
    // cout << endl;
    
    ans_num[1] = num[0];
    ans_num[len-2] = num[len-1];

    int l = 3, r = len - 4;
    lp(i, (len-2)/2)
    {
        int lx, rx;

        lx = num[l-1] - ans_num[l-2];
        if (lx < 0)
            lx += 26;

        rx = num[r+1] - ans_num[r+2];
        if (rx < 0)
            rx += 26;

        ans_num[l] = lx;
        ans_num[r] = rx;

        l+=2;
        r-=2;
    }

    lp(i, len)
        cout << (char)(ans_num[i] + 65);
    cout << endl;

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
}