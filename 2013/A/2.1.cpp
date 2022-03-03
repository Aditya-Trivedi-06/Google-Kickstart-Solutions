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

string number(int num)
{
    switch (num)
    {
    case 1:
        return "one";
        break;

    case 2:
        return "two";
        break;

    case 3:
        return "three";
        break;

    case 4:
        return "four";
        break;

    case 5:
        return "five";
        break;

    case 6:
        return "six";
        break;

    case 7:
        return "seven";
        break;

    case 8:
        return "eight";
        break;

    case 9:
        return "nine";
        break;
    }
}

string count(int cnt)
{
    switch (cnt)
    {
    case 2 : 
        return "double";
        break;

    case 3:
        return "triple";
        break;

    case 4 :
        return "quadruple";
        break;

    case 5 :
        return "quintuple";
        break;

    case 6 :
        return "sextuple";
        break;

    case 7 :
        return "septuple";
        break;

    case 8 :
        return "octuple";
        break;

    case 9 :
        return "nonuple";
        break;

    case 10 :
        return "decuple";
        break;

    default : "";
        break;
    }
}

void solve()
{
    string s;
    getline(cin, s);
    stringstream ss(s);
    string word;
    vects;
    while (ss >> word)
        vs.eb(word);

    string n = vs[0];
    string diff = vs[1];

    vect;
    lp(i, diff.size())
    {
        int num;
        num = diff[i] - '0';
        v.eb(num);
        i++;
    }

    int start = 0;
    for (auto i : v)
    {
        lp(j, i)
        {
            int cnt = 1;
            while (n[j] == n[j+1])
                cnt++, j++;
            
        }
    }
}

int main()
{
    // for t test cases
    int t = 1, T;
    cin >> T;
    cin.ignore();
    while (t <= T)
    {
        cout << "Case #" << t << ": ";
        solve();
        t++;
    }
}