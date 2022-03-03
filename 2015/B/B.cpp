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

int np, ne, nt;
vector<ll> p, e, t;

bool check_one_a(ll ratio)
{
    lp(i, ne)
    {
        lp(j, np)
        {
            ll num = e[i] * p[j];

            lp(k, ne)
            {
                if (k == i)
                    continue;

                lp(l, nt)
                {
                    ll denom = e[k] * t[l];

                    if (denom / (float)num == ratio)
                    {
                        // cout << denom << ' ' << num << endl;
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

bool check_one_b(ll ratio)
{
    lp(i, ne)
    {
        lp(j, np)
        {
            ll num = e[i] * p[j];

            lp(k, ne)
            {
                if (k == i)
                    continue;

                lp(l, nt)
                {
                    ll denom = e[k] * t[l];

                    if (num / (float)denom == ratio)
                        return true;
                }
            }
        }
    }

    return false;
}

bool check(int a, int b)
{
    ll count_a = 0, count_b = 0, a_index, b_index;
    for (ll i = 0; i < ne; i++)
    {
        ll cur_e = e[i];

        for (ll j = 0; j < np; j++)
        {
            if ((cur_e * p[j]) % a == 0)
                count_a++;
        }
        for (ll j = 0; j < nt; j++)
        {
            if ((cur_e * t[j]) % b == 0)
                count_b++;
        }
    }
    if (count_a == 0 or count_b == 0)
        return false;

    if (count_a > 1 or count_b > 1)
        return true;

    if (a_index == b_index)
        return false;

    return true;
}

void solve()
{
    cin >> np >> ne >> nt;

    vectin(p, np);
    vectin(e, ne);
    vectin(t, nt);

    ll m;
    cin >> m;

    lp(i, m)
    {
        ll p, q;
        cin >> p >> q;

        ll com = __gcd(p, q);
        p /= com;
        q /= com;

        if (p == 1)
        {
            if (check_one_a(q))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
            continue;
        }
        if (q == 1)
        {
            if (check_one_b(p))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
            continue;
        }

        if (check(p, q))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}

int main()
{
    // for t test cases
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc = 1, T;
    cin >> T;
    while (tc <= T)
    {
        cout << "Case #" << tc << ":";
        cout << endl;
        solve();
        p.clear();
        e.clear();
        t.clear();
        tc++;
    }
}