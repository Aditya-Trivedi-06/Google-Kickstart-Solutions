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

vector<vector<char>> mat;
unordered_set<char> temp, prev_ele;
// queue<char> elements;
int r, c;

bool poss(char remove_c)
{
    lp(i, r - 1)
        lp(j, c) if (mat[i][j] == remove_c) if (mat[i + 1][j] != remove_c and prev_ele.find(mat[i + 1][j]) == prev_ele.end()) return false;

    return true;
}

bool poss_util(string s)
{
    prev_ele.clear();
    lp(i, s.size())
    {
        if (!poss(s[i]))
            return false;
        prev_ele.insert(s[i]);
    }
    return true;
}

string util(string s)
{
    sort(s.begin(), s.end());
    do
    {
        if (poss_util(s))
            return s;
        
    } while(next_permutation(s.begin(), s.end()));
    return "-1";
}

void solve()
{
    cin >> r >> c;

    lp(i, r)
    {
        vector<char> v;
        lp(j, c)
        {
            char ele;
            cin >> ele;
            v.eb(ele);
            temp.insert(ele);
        }
        mat.eb(v);
    }

    string s = "";

    for (auto i : temp)
        s += i;

    cout << util(s) << endl;
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
        solve();
        temp.clear();
        prev_ele.clear();
        mat.clear();
        t++;
    }
}