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

int ones[105], diff[105];

void generate(string s, int index, int len, int n)
{
    if (index == len)
    {
        cout << s << endl;
        return;
    }

    if (ones[index] > n / 2)
        generate(s+'1', index+1, len, n);
    else
        generate(s+'0', index+1, len, n);
    
    char ch = s[s.size() - 1];
    s.pop_back();
    index--;
    if (ch == '1')
        generate(s+'0', index+1, len, n);
    else
        generate(s+'1', index+1, len, n);
    
}

void solve()
{
    int n, m, len;
    cin >> n >> m >> len;

    char mat[n][len];
    unordered_set <string> forb;

    lp(i, n)
        lp(j, len)
        {
            cin >> mat[i][j];
            if (mat[i][j] == '1')
                ones[j]++;
        }

    lp(i, m)
    {
        string s;
        cin >> s;
        forb.insert(s);
    }

    string ans = "";

    generate(ans, 0, len, n);
}

int main()
{
    // for t test cases
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        cout << "Case #" << t << ": ";
        cout << endl;
        memset(ones, 0, sizeof(ones));
        memset(diff, 0, sizeof(diff));
        solve();
        t++;
    }
}