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

// Vectors / pairs / unordered_maps  ---------------

#define pairint pair<int, int> pint
#define pairll pair<ll, ll> pll

#define unordered_mapn unordered_map<int, int> mint
#define unordered_mapll unordered_map<ll, ll> mll

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

unordered_map<string, unordered_set<string>> adj;
unordered_set<string> all_var, vis;
unordered_map<string, int> topo;
queue<string> q, st;

void fill(vector<string> &temp)
{
    for (auto words : temp)
    {
        string cur = words, var;
        int index = 0;
        while (cur[index] != '=')
        {
            var += cur[index];
            index++;
        }
        all_var.insert(var);
        index++;
        while (cur[index] != '(')
            index++;
        index++;
        string cur_var = "";
        unordered_set<string> us;
        while (cur[index] != ')')
        {
            if (cur[index] == ',')
            {
                us.insert(cur_var);
                cur_var = "";
                index++;
            }
            cur_var += cur[index];
            index++;
        }
        if (cur_var.size() != 0)
            us.insert(cur_var);
        if (us.size() != 0)
        {
            adj[var] = us;
        }
    }
}

void topo_sort(string cur)
{
    vis.insert(cur);
    for (auto i : adj[cur])
    {
        if (all_var.find(i) != all_var.end())
        {
            if (vis.find(i) == vis.end())
            {
                topo_sort(i);
            }
        }
    }

    q.push(cur);
}

void util()
{
    for (auto i : adj)
        if (vis.find(i.first) == vis.end())
            topo_sort(i.first);
}

bool cycle(vector<string> &order)
{
    unordered_map<string, int> um;

    lp(i, order.size())
    {
        // cout << order[i] << endl;
        um.insert(mp(order[i], i));
    }

    for (auto i : adj)
    {
        for (auto j : i.second)
        {
            if (all_var.find(j) == all_var.end())
                continue;

            if (um[i.first] < um[j])
                return true;
        }
    }

    return false;
}

bool depend_itself()
{
    for (auto i : adj)
    {
        string cur = i.first;
        for (auto j : i.second)
        {
            if (j == cur)
                return true;
        }
    }
    return false;
}

void solve()
{
    int n;
    cin >> n;
    vector<string> temp;
    lp(i, n)
    {
        string ele;
        cin >> ele;
        temp.eb(ele);
    }

    fill(temp);

    if (depend_itself())
    {
        cout << "BAD" << endl;
        return;
    }
    
    util();
    vector <string> order;
    // cout << q.size() << endl;
    while (!q.empty())
    {
        string cur = q.front();
        // cout << cur << endl;
        order.eb(cur);
        q.pop();
    }

    if (cycle(order))
    {
        cout << "GOOD" << endl;
    }
    else
    {
        cout << "BAD" << endl;
    }
}

int main()
{
    // for t test cases
    freopen("input.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        cout << "Case #" << t << ": ";
        // cout << endl;
        solve();
        adj.clear();
        all_var.clear();
        vis.clear();
        topo.clear();
        t++;
    }
}