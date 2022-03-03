#include <bits/stdc++.h>

#define ll long long
#define ld double
#define uint unsigned int
#define ull unsigned long long

#define ff first
#define ss second

// For Loops ----------------------------

#define lp(n) for (int i = 0; i < n; i++)
#define lp1(n) for (int i = 1; i < n; i++)
#define dlp(n)                  \
    for (int i = 0; i < n; i++) \
        for (int j = 0; j < n; j++)

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

#define bn begin
#define rs resize
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

#define yes cout << "YES" << endl
#define no cout << "NO" << endl

// Google KickStart ---------------------

#define vectcase vector<int> vcase
#define vcaseprint                                          \
    int countcase = 1;                                      \
    for (auto i : vcase)                                    \
    {                                                       \
        cout << "Case #" << countcase << ": " << i << endl; \
        countcase++;                                        \
    }

using namespace std;

int count (vect, int n){
    int maxnum = -1, sum = 0;
    for (int i = 0; i < n; i++){
        if (v[i] > maxnum) {
            maxnum = v[i];
            if (i == n-1) {
                sum++;
            }
            else if (v[i] > v[i+1]){
                sum ++;
            }
        }
    }

    return sum;
}

int main()
{
    // for t test cases
    int t;
    vectcase;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vect;
        vectin(v, n);

        int num = count(v, n);

        vcase.pb(num);
    }
    vcaseprint
}