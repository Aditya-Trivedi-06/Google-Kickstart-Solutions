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

void solve()
{
    int m;
    cin >> m;

    unordered_set <string> total, grp1, grp2;

    lp(i, m)
    {
        vector <string> s;

        lp(j, 2)
        {
            string temp;
            cin >> temp;
            s.eb(temp);
        }    
        SORT(s);
        string s1 = s[0];
        string s2 = s[1];

        if (total.find(s1) != total.end() and total.find(s2) != total.end())
        {
            int s1_grp = 1, s2_grp = 1;

            if (grp2.find(s1) != grp2.end())
                s1_grp = 2;

            if (grp2.find(s2) != grp2.end())
                s2_grp = 2;

            if (s1_grp == s2_grp)
            {
                cout << "No" << endl;
                return;
            }
        }

        else if (total.find(s1) != total.end())
        {
            int s1_grp = 0;
            if (grp2.find(s1) != grp2.end())
                s1_grp = 1;
            
            if (s1_grp)
                grp1.insert(s2);
            else
                grp2.insert(s2);
        }

        else if (total.find(s2) != total.end())
        {
            int s2_grp = 0;
            if (grp2.find(s2) != grp2.end())
                s2_grp = 1;

            if (s2_grp)
                grp1.insert(s1);
            else
                grp2.insert(s1);
        }

        else 
        {
            grp1.insert(s1);
            grp2.insert(s2);
        }
        total.insert(s1);
        total.insert(s2);
    }

    int len = total.size();
    if (len % 2)
    {
        cout << "No" << endl;
        return;
    }
    if (grp1.size() != len / 2 or grp2.size() != len / 2)
    {
        cout << "No" << endl;
        return;
    }

    cout << "Yes" << endl;
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
        t++;
    }
}