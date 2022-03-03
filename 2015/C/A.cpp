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
    int p, n;
    cin >> p;
    vector <int> price(p);

    lp(i, p)
        cin >> price[i];
    
    cin >> n;

    map <string, multiset <int, greater <int>>> player;

    lp(i, n)
    {
        int wt;
        cin >> wt;

        lp(j, p)
        {
            string s;
            cin >> s;
            auto it = player.find(s);
            int point = price[j] * wt;

            if (it == player.end())
            {
                multiset <int, greater <int>> temp;
                temp.insert(point);
                player.insert(mp(s, temp));
            }
            else 
                player[s].insert(point);
        }
    }
    int num;
    cin >> num;

    map <int, set <string>, greater <int>> ans;

    for (auto i : player)
    {
        string name = i.first;
        int sum = 0, count = 1;

        for (auto j : i.second)
        {
            if (count > num)
                break;
            sum += j;
            count++;
        }

        auto it = ans.find(sum);

        if (it == ans.end())
        {
            set <string> temp;
            temp.insert(name);
            ans.insert(mp(sum, temp));
        }
        else
            ans[sum].insert(name);
    }
    int count = 1;
    for (auto i : ans)
    {
        int temp_cnt = 0;
        for (auto j : i.second)
        {
            cout << count << ": " << j << endl;
            temp_cnt++;
        }
        count+= temp_cnt;
    }
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
        cout << "Case #" << t << ":" << endl;
        solve();
        t++;
    }
}