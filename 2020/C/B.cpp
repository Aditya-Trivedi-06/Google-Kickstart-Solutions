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

void solve(int n, int a, int b, int c)
{

    if (a == n and b == n and c < a) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    else if (a == 1 and b == 1 and c == 1 and n > 1){
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    bool ac = true;
    if (a == c) {
        ac = false;
    }

    int arr[n], max_ht = n;

    int i = 1, ht = 2;

    while (i <= a-c and ht < n){
        arr[i] = ht;
        ht++; i++;
    }
    while (i <= n-b and ac){
        arr[i] = 1;
        i++;
    }

    if (!ac) {
        arr[i] = n;
        i++; c--;
        
        while (i <= n-b+1){
            arr[i] = 1;
            i++;
        }

        while (c--){
            arr[i] = n;
            i++;
        }
    }

    while (c-- and ac){
        arr[i] = n;
        i++; 
    }

    while (i <= n){
        max_ht--;
        arr[i] = max_ht;
        i++;
    }

    for (int i = 1; i <= n; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main()
{
    // for t test cases
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {

        int n, a, b, c;
        cin >> n >> a >> b >> c; 

        cout << "Case #" << t << ": ";
        solve(n, a, b, c);
        t++;
    }
}