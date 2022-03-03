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

// Yes/ No for CodeForces ---------------
// # define 	yes 			cout << "YES" << endl
// # define 	no 				cout << "NO" << endl

using namespace std;

int n;
vector<int> adj[1005];
bool visited[1005] {};
int dis[1005] {};

void addedge(int src, int dst)
{
    adj[src].eb(dst);
    adj[dst].eb(src);
}

void cycle(int n)
{
    unordered_map <int, int> deg;

    lp1(i, n)
        deg.insert(mp(i, adj[i].size()));
    
    queue <int> q;

    while (true)
    {
        for (auto i : deg)
            if (i.second == 1 and !visited[i.first])
                q.push(i.first);
        
        if(q.empty())
            break;

        while (!q.empty())
        {
            int f = q.front();
            q.pop();

            visited[f] = 1;

            for (auto i : adj[f])
                deg[i]--;
        }
    }
}

void dfs(int cur_node)
{
    for (auto i : adj[cur_node])
    {
        if (visited[i])
        {
            dis[i] = dis[cur_node] + 1;
            visited[i] = 0;
            dfs(i);
        }
    }
}

void solve()
{
    int src, dst;
    cin >> n;

    lp(i, n)
    {
        cin >> src >> dst;
        addedge(src, dst);
    }

    cycle(n);
    vect;

    lp1(i, n)
        if(!visited[i])
            v.eb(i);

    for (auto i : v)
        dfs(i);

    lp1(i, n)
        cout << dis[i] << ' ';
    cout << endl;

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
        for (int i = 0; i < 1005; i++)
            adj[i].clear();
        memset(dis, 0, sizeof(dis));
        for (auto i : adj)
            i.clear();
        t++;
    }
}