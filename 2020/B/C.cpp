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

string s, res = "";
unordered_map <int, int> um;

void brackets(string cur_s)
{
    stack <int> st;

    for (int i = 0; i < cur_s.size(); i++)
    {
        if (cur_s[i] == '(')
            st.push(i);
        else if (cur_s[i] == ')')
        {
            int open = st.top();
            st.pop();
            um[open] = i;
        }
    }
}

void func(int l, int r)
{
    int num = s[l] - '0';
    string temp = s.substr(l+2, r-l-2);
    while(num--)
        res += temp;
    // cout << temp << endl;
}

void expand()
{
    while(true)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
            {
                int r = um[i + 1];
                func(i, r);
                i = r;
            }
            else
            {
                res += s[i];
            }
        }
        s = res;
        res.clear();
        // cout << s << endl; 
        um.clear();
        brackets(s);
        // cout << res << " : ";
        // cout << um.size() << endl;
        if (um.empty())
            break;
    }
}

void solve()
{
    cin >> s;
    brackets(s);
    expand();
    // cout << s << endl;

    ll x = 1, y = 1;
    for (auto i : s)
    {
        switch (i)
        {
        case 'N' : y--;
            break;

        case 'S' : y++;
            break;

        case 'E' : x++;
            break;

        case 'W' : x--;
            break;
        }
        if (x < 1)
            x += 10e+8;
        else if (x > 10e+8)
            x -= 10e+8;

        if (y < 1)
            y += 10e+8;
        else if (y > 10e+8)
            y -= 10e+8;
    }

    cout << x << ' ' << y << endl;
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
        s.clear();
        um.clear();
        res.clear();
        t++;
    }
}