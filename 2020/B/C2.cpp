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

#define mod 1000000000
#define og 1000000000

// Yes/ No for CodeForces ---------------
// # define 	yes 			cout << "YES" << endl
// # define 	no 				cout << "NO" << endl

using namespace std;
using namespace std::chrono;

unordered_map <int, int> m;

void bracks(string s)
{
    stack <int> st;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            st.push(i);
        if (s[i] == ')')
        {
            int open = st.top();
            st.pop();
            m.insert(mp(open, i));
        }
    }
}

void solve()
{
    string s;
    cin >> s;
    bracks(s);
    
    vectl(v);
    ll cur_num = 1;
    v.eb(cur_num);
    ll x = 1, y = 1;

    for (int i = 0; i < s.size(); i++)
    {
        cur_num = v.back();
        if (isdigit(s[i]))
        {
            int cur_digit = s[i] - '0';
            cur_num *= cur_digit;
            cur_num %= og;
            v.eb(cur_num);
            i++;
        }
        else if (s[i] == ')')
            v.pop_back();
        
        else
        {
            switch(s[i]){
                case 'N' : y = (y-cur_num) % og;
                break;
                case 'S' : y = (y+cur_num) % og;
                break;
                case 'E' : x = (x+cur_num) % og;
                break;
                case 'W' : x = (x-cur_num) % og;
                break;
            }
        }

        if (y > mod)
            y-= mod;
        else if (y <= 0)
            y += mod;

        if (x > mod)
            x -= mod;
        else if (x <= 0)
            x += mod;
    }

    cout << x << ' ' << y << endl;
}

int main()
{
    // for t test cases
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // auto start = high_resolution_clock::now();
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        cout << "Case #" << t << ": ";
        solve();
        m.clear();
        t++;
    }
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << duration.count() << endl;
}