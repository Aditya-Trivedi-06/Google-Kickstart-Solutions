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

#define mod 1000000007

// Yes/ No for CodeForces ---------------
// # define 	yes 			cout << "YES" << endl
// # define 	no 				cout << "NO" << endl

#define INF INT_MAX

using namespace std;
using namespace std::chrono;

bool segs[8] {};

vector <string> okay;

void instr()
{
    okay.eb("1111110");
    okay.eb("0110000");
    okay.eb("1101101");
    okay.eb("1111001");
    okay.eb("0110011");
    okay.eb("1011011");
    okay.eb("1011111");
    okay.eb("1110000");
    okay.eb("1111111");
    okay.eb("1111011");
}

bool is_poss(int num, string &s)
{
    for (int i = 0; i < 7; i++)
    {
        if (s[i] == '1' and okay[num][i] == '0')
            return false;
        
        if (segs[i] and okay[num][i] == '1' and s[i] == '0')
            return false;
    }
    cout << okay[num] << endl;
    return true;
}

void solve()
{
    int n;
    cin >> n;
    vects(vs);
    
    lp(i, n)
    {
        string s;
        cin >> s;
        vs.eb(s);
    }   

    for (auto i : vs)
    {
        int index = 0;
        for (auto j : i)
        {
            if (j == '1')
                segs[index] = 1;
            index++;
        }
    }

    int not_broken = 0;
    for (int i = 0; i < 8; i++)
    {
        if (segs[i])
            not_broken++;
    }

    if (not_broken == 7)
    {
        string s = vs[0];
        auto it = find(ALL(okay), s);
        if (it == okay.end())
        {
            cout << "ERROR!" << endl;
            return;
        }
        int num = it - okay.begin();

        for (int i = 0; i < n; i++)
        {
            if (num < 0)
                num = 9;

            if (okay[num] != vs[i])
            {
                cout << "ERROR!" << endl;
                return;
            }

            num--;
        }

        cout << okay[num] << endl;

        return;
    }

    vector <int> possible;

    for (int i = 0; i <= 9; i++)
    {
        string s = vs[0];
        if (is_poss(i, s))
        {
            cout << i << endl;
            possible.eb(i);
        }
    }

    if (possible.size() == 0)
    {
        cout << "ERROR!" << endl;
        return;
    }

    if (possible.size() == 1)
    {
        cout << 1 << " : ";
        int num = possible[0];
        num--;
        for (int i = 1; i < n; i++)
        {
            string s = vs[i];
            if (num < 0)
                num = 9;
            if (!is_poss(num, s))
            {
                cout << "ERROR!" << endl;
                return;
            }
            num--;
        }
        if (num < 0)
            num = 9;

        string s = okay[num];
        string temp = "";
        for (int i = 0; i < 7; i++)
        {
            if (s[i] == '1')
            {
                if (!segs[i])
                {
                    cout << "ERROR!" << endl;
                    return;
                }
                else
                {
                    temp += '1';
                }
            }
            else
            {
                cout << '0';
            }
        }
        cout << endl;
        return;
    }

    int index = 1;

    while (index < n)
    {
        if(possible.size() == 0)
        {
            cout << " SIZE 0" << endl;
            return;
        }

        for (auto i : possible)
            cout << i << ' ';
        cout << endl;

        vector <int> temp;

        for (auto i : possible)
        {   
            int num = i - 1;
            string s = vs[index];
            
            if (num < 0)
                num = 9;

            if (is_poss(num, s))
            {
                temp.eb(num);
            }
        }
        index++;
        possible.clear();
        // cout << temp.size() << endl;
        possible = temp;
    }

    // cout << possible.size() << endl;

    if (possible.size() > 1 or possible.size() == 0)
    {
        cout << "ERROR!" << endl;
        return;
    }
    // cout << possible[0]-1 << endl;
    // cout << okay[possible[0] - 1] << endl;
    string s = okay[possible[0] - 1];
    string temp = "";
    for (int i = 0; i < 7; i++)
    {
        if (s[i] == '1')
        {
            if (!segs[i])
            {
                cout << "ERROR!" << endl;
                return;
            }
            else
            {
                temp += '1';
            }
        }
        else
        {
            cout << '0';
        }
    }
    cout << endl;
}

int main()
{
    // for t test cases
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // auto start = high_resolution_clock::now();
    int t = 1, T;
    cin >> T;
    instr();

    // for (int i = 0; i <= 9; i++)
    // {
    //     cout << "i : " << okay[i] << endl;
    // }

    while (t <= T)
    {
        cout << "Case #" << t << ": ";
        solve();
        memset(segs, 0, sizeof(segs));
        // cerr << "Case : " << t << " Solved !" << endl;
        t++;
    }
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cerr << duration.count() / 1000000 << " S " << endl;
}