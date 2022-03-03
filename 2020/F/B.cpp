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

int solve(int n, int k, map <int, int> m)
{
    k--;
    int count = 1, t = m.begin()->first + k;

    for (auto it = m.begin(); it != m.end(); it++){
        int lr = it->first, rr = it->second;
        rr--;
        if (rr > t) {
            if (lr >= t) {  
                t = lr + k;
            }
            else {
                t = t + k;
            }
            count++;
        }
    }

    return count;
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

        int n, k;
        cin >> n >> k;
        
        map <int, int> m;

        for (int i = 0; i < n; i++){
            int a, b;
            cin >> a >> b;
            m.insert({a,b});
        }

        int num = solve(n, k, m);

        cout << "Case #" << t << ": " << num << endl;
        t++;
    }
}