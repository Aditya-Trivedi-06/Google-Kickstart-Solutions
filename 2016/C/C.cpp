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

unordered_map <string, unordered_set <string>> adj;
unordered_set <string> all_var, vis, total_rhs;
unordered_map <string, int> topo;
queue <string> q;

void fill(vector <string> &temp)
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
        while(cur[index] != '(')
            index++;
        index++;
        string cur_var = "";
        unordered_set <string> us;
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
            adj[var] = us;
        
    }
}

bool check()
{
    for (auto i : adj)
    {
        for (auto j : i.second)
            total_rhs.insert(j);
    }

    for (auto i : total_rhs)
    {
        if (all_var.find(i) == all_var.end())
            return false;
    }
    return true;
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

void dfs(string cur_string)
{   
    vis.insert(cur_string);

    for (auto i : adj[cur_string])
    {
        if (all_var.find(i) != all_var.end())
        {
            if (vis.find(i) == vis.end())
            {
                dfs(i);
            }
        }
    }

    q.push(cur_string);
}   

bool dfs_util()
{
    for (auto i : all_var)
    {
        if (vis.find(i) == vis.end())
            dfs(i);
    }
    
    int count = 0;
    while (!q.empty())
    {
        string cur = q.front();
        // cout << cur << endl;
        topo[cur] = count;
        q.pop();
        count++;
    }

    for (auto i : adj)
    {
        string cur = i.first;
        int parent_index = topo[cur];

        for (auto j : i.second)
        {
            string child = j;
            if (topo.find(child) == topo.end())
                continue;

            int child_index = topo[child];

            if (child_index > parent_index)
            {
                return false;
            }
        }
    }

    return true;
}

void solve()
{
    int n;
    cin >> n;
    vector <string> temp;
    lp(i, n)
    {
        string ele;
        cin >> ele;
        temp.eb(ele);
    }
    fill(temp);
    // for (auto i : adj)
    // {

        // cout << i.first << " : ";
        // for (auto j : i.second)
        //     cout << j << ' ';
        // cout << endl;
    // } 

    if (depend_itself())
    {
        cout << "BAD" << endl;
        return;
    }
    if (!check())
    {
        cout << "BAD" << endl;
        return;
    }
    if (dfs_util())
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
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        cout << "Case #" << t << ": ";
        solve();
        adj.clear();
        all_var.clear();
        vis.clear();
        topo.clear();
        total_rhs.clear();
        t++;
    }
}