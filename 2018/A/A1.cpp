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

void nine(string s_num)
{
    int i = 0, index, odd_digit;
    for (i; i < s_num.size(); i++)
    {
        int digit = s_num[i] - '0';
        if (digit % 2)
        {
            index = i;
            odd_digit = digit;
            break;
        }
    }

    string s_low = s_num.substr(0, index);

    int low_digit = odd_digit - 1;
    string s_low_digit = to_string(low_digit);
    s_low += s_low_digit;

    int len = s_num.size() - s_low.size();
    for (int j = 0; j < len; j++)
    {
        s_low += '8';
    }

    string s_high_num = "";
    index--;
    while (index >= 0 and s_num[index] == '8')
    {
        index--;
    }
    if (index <= 0)
    {
        s_high_num += '2';
        lp(i, s_num.size())
            s_high_num += '0';
    }
    else
    {
        s_high_num = s_num.substr(0, index-1);
        int last_digit = s_num[index] - '0';
        last_digit++;
        s_high_num += to_string(last_digit);

        int len = s_num.size() - s_high_num.size();
        for (int j = 0; j < len; j++)
            s_high_num += '0';
    }

    ll low = stoll(s_low), high = stoll(s_high_num), num = stoll(s_num);
    cout << min(high - num, num - low) << endl;
}

void solve()
{
    ll n;
    cin >> n;
    string s_num = to_string(n);
    int i = 0, index, odd_digit;

    for (i; i < s_num.size(); i++)
    {
        int digit = s_num[i] - '0';
        if (digit % 2)
        {
            index = i;
            odd_digit = digit;
            break;
        }
    }
    if (i == s_num.size())
    {
        cout << 0 << endl;
        return;
    }
    // if (index == 0)
    //     index++;

    if (odd_digit == 9)
    {
        nine(s_num);
        return;
    }

    string s_low = s_num.substr(0, index), s_high = s_num.substr(0, index);

    int low_digit = odd_digit - 1, high_digit = odd_digit + 1;
    string s_low_digit = to_string(low_digit), s_high_digit = to_string(high_digit);
    s_low += s_low_digit;
    s_high += s_high_digit;

    int len = s_num.size() - s_low.size();
    for (int j = 0; j < len; j++)
    {
        s_low += '8';
        s_high += '0';
    }

    // cout << s_low << endl;
    // cout << s_high << endl;

    ll low = stoll(s_low), high = stoll(s_high), num = stoll(s_num);
    cout << min(high - num, num - low) << endl;
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