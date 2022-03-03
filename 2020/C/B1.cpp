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

vector < vector <char>> mat;
unordered_map<char, unordered_set<char>> adj;
unordered_set <char> all_elements, vis;
int r, c;
string ans = "";
queue <char> res;

void topo_sort(char cur_char)
{
    vis.insert(cur_char);
    // cout << cur_char << endl;

    for (auto i : adj[cur_char])
    {
        if(vis.find(i) == vis.end())
            topo_sort(i);
    }

    res.push(cur_char);
}

void util()
{
    for (auto i : all_elements)
        if (vis.find(i) == vis.end())
            topo_sort(i);
}

// bool dfs(char i, unordered_set <char> visited)
// {
//     visited.insert(i);

//     for (auto j : adj[i])
//     {
//         if (visited.find(j) != visited.end())
//             return false;
//         dfs(j, visited);
//     }

//     return true;
// }

// bool cycle()
// {
//     unordered_set <char> visited, elements = all_elements;

//     while(!elements.empty())
//     {
//         for (auto i : elements)
//         {
//             if (elements.find(i) != elements.end())
//                 if(!dfs(i, visited))
//                     return false;

//         }
//     }
// }

void solve()
{
    cin >> r >> c;

    lp(i, r)
    {
        vector <char> v;
        lp(j, c)
        {
            char ele;
            cin >> ele;
            v.eb(ele);
            all_elements.insert(ele);
        }   
        mat.eb(v);
    }

    lp(i, r-1)
    {
        lp(j, c)
        {
            char cur_char = mat[i][j], next_char = mat[i+1][j];
            if (next_char != cur_char)
                adj[cur_char].insert(next_char);
        }
    }

    if (all_elements.size() == adj.size())
    {
        cout << -1 << endl;
        return;
    }

    // for (auto i : all_elements)
    // {
    //     if (adj.find(i) == adj.end())
    //     {
    //         vis.insert(i);
    //         ans += i;
    //     }
    // }

    // cout << endl << ans << endl;

    // for (auto i : adj)
    // {
    //     cout << i.first << " : ";
    //     for (auto j : i.second)
    //     {
    //         cout << j << ' ';
    //     }
    //     cout << endl;
    // }

    // for (auto i : all_elements)
    //     cout << i << ' ';
    // cout << endl;

    util();
    // cout << res.size() << endl;
    while(!res.empty())
    {
        ans += res.front();
        res.pop();
    }
    cout << ans << endl;
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
        // cout << endl;
        solve();
        ans.clear();
        adj.clear();
        all_elements.clear();
        mat.clear();
        vis.clear();
        t++;
    }
}