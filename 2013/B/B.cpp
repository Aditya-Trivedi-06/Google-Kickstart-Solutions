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

// Yes/ No for CodeForces ---------------
// # define 	yes 			cout << "YES" << endl
// # define 	no 				cout << "NO" << endl

using namespace std;

void solve()
{
    string code = "";
    string line = "";
    
    while (true)
    {
        getline(cin, line);
        code += line;
        if (code[code.size()-1] == '\n' and code[code.size()-2] != ' ')
            break;
        code += "\n";
        cout << line << endl;
        // if(line[line.size()-1] == 'n' and line[line.size()-2] == '\\')
            // break;
    }

    // for (auto i : code)
    // {
    //     cout << i;
    // }

    // cout << code << endl;

    int open = 0;
    string ans = "", temp = "";

    for (int i = 0; i < code.size(); i++)
    {
        if (code[i] == '/' and code[i+1] == '*')
            open++, i++;

        if (open > 0 and code[i] == '*' and code[i+1] == '/')
            open--, i++;

        else if (open == 0)
            temp += code[i];
    }

    cout << temp;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // for t test cases
    // int t = 1, T;
    // cin >> T;
    // cin.ignore();
    // while (t <= T)
    // {
        cout << "Case #" << 1 << ":" << endl;
        solve();
        // t++;
    // }
}