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

set < pair <int, int>> rows[50001], cols[50001];

void merge_row(int x)
{

}

pair <int, int> check_row(int x, int y, bool north)
{
    set < pair <int, int>> &temp = rows[x];

    for (auto it = temp.begin(); it != temp.end(); it++)
    {
        int f = it->ff, s = it->ss, ans;
        if (y >= f and y <= s)
        {
            if (north)
            {
                f--;
                ans = f;
                if (it != temp.begin())
                {
                    it--;
                    if (it->ss == f - 1)
                    {
                        int new_f = it->ff;
                        temp.erase(it);
                        temp.erase(mp(f + 1, s));
                        temp.insert(mp(new_f, s));
                    }
                    else
                    {
                        it++;
                        temp.erase(it);
                        temp.insert(mp(f, s));
                    }
                }
                else
                {
                    temp.erase(it);
                    temp.insert(mp(f, s));
                }
                return mp(x, ans);
            }
            else
            {
                s++;
                ans = s;
                it++;
                if (it != temp.end())
                {
                    if(it->ff == s + 1)
                    {
                        int new_s = it->ss;
                        temp.erase(it);
                        temp.erase(mp(f, s - 1));
                        temp.insert(mp(f, new_s));
                    }
                }
                else
                {
                    it--;
                    temp.erase(it);
                    temp.insert(mp(f, s));
                }
                return mp(x, ans);
            }
        }
        else if (y == s - 1)
        {
            it++;
            if (it != temp.end())
            {
                int next_f = it->ff;
                if (s + 2 == next_f)
                {
                    int next_s = it->ss;
                    temp.erase(it);
                    temp.erase(mp(f, s));
                    temp.insert(mp(f, next_s));
                }
            }
            else
            {
                it--;
                int new_s = s+1;
                temp.erase(it);
                temp.insert(mp(f, new_s));
            }
            return mp(x, y);
        }
        else if (y == f + 1)
        {
            
            int new_f = f - 1;
            temp.erase(it);
            temp.insert(mp(new_f, s));
            return mp(x, y);
        }
    }
    temp.insert(x, x);
    return mp(x, y);
}

void solve()
{

    int n, r, c, sr, sc;
    cin >> n >> r >> c >> sr >> sc;

    string s;
    cin >> s;

    
}

int main()
{
    // for t test cases
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {

        cout << "Case #" << t << ": ";
        solve();
        cout << endl;
        t++;
    }
}