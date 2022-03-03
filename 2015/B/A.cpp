#include <bits/stdc++.h>

#define ll long long
#define ld double
#define uint unsigned int
#define ull unsigned long long

#define ff first
#define ss second

// For Loops ----------------------------

#define lp(i, n) for (int i = 0; i < n; i++)
#define lp1(i, n) for (int i = 1; i <= n; i++)

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

vector < pair <int, vector <int>>> adj[505];
bool vis[505];
int time_for_each_city[505], n;

void addedge()
{
    int s, d;
    vector <int> temp (24);
    cin >> s >> d;

    lp(i, 24)
        cin >> temp[i];

    auto temp_pair = mp(d, temp);
    adj[s].eb(temp_pair);
    temp_pair = mp(s, temp);
    adj[d].eb(temp_pair);
}

void greedy(int t)
{
    int city = 1, total_time;
    vis[1] = 1;

    // This will Store all the cities and thier times in sorted order !
    // Time : City
    multimap <int, int> m;

    // Pair (City, Time)
    queue <pair <int, int>> q;

    int next_city, next_time;

    for (auto i : adj[city])
    {
        next_city = i.first;
        next_time = i.second[t];
        m.insert(mp(next_time, next_city));
    }

    next_city = m.begin()->second;
    next_time = m.begin()->first;

    total_time = next_time;
    vis[next_city] = 1;
    time_for_each_city[next_city] = next_time;
    q.push(mp(next_city, next_time));

    while (!q.empty())
    {
        int cur_city = q.front().first, city_time = q.front().second;
        total_time += city_time;
        time_for_each_city[cur_city] = total_time;
        vis[cur_city] = 1;
        q.pop();

        for (auto i : adj[cur_city])
        {
            next_city = i.first;
            next_time = i.second[total_time % 24];
            if (!vis[next_city])
                m.insert(mp(next_time, next_city));
        }
        
        for (auto i : m)
        {
            int city = i.second, citytime = i.first;
            if (!vis[city])
            {
                q.push(mp(city, citytime));
                break;
            }
        }

    }
    cout << "ANS" << endl;
    for (int i = 1; i <= n; i++)
        cout << time_for_each_city[i] << ' ';
    cout << endl;
}

void solve()
{
    int m, k;
    cin >> n >> m >> k;
    
    lp(i, m)
        addedge();

    // lp1(i, n)
    // {
    //     cout << i << " : " << endl;
    //     for (auto j : adj[i])
    //     {
    //         cout << j.first << endl;
    //         for (auto k : j.second)
    //         {
    //             cout << k << ' ';
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }

    greedy(3);
}

int main()
{
    // for t test cases
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        cout << "Case #" << t << ": ";
        cout << endl;
        solve();
        t++;
    }
}