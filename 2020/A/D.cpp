#include <bits/stdc++.h>
#include <chrono>

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

#define vect(v) vector<int> v
#define vectl(vl) vector<long long> vl
#define vectodd(vodd) vector<int> vodd
#define vecteven(veven) vector<int> veven
#define vects(vs) vector<string> vs

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
using namespace std::chrono;

int trie_size = 26;

struct Trie
{
    bool isend;
    unordered_map <char, Trie*> um;
};

Trie* new_trie()
{
    Trie *new_node = new Trie;
    new_node->isend = false;
    return new_node;
}

void insert(Trie*&root, string s)
{
    if (root == nullptr)
        root = new_trie();
    
    Trie* temp = root;

    for (auto i : s)
    {
        if (temp->um.find(i) == temp->um.end())
            temp->um[i] = new_trie();
        
        temp = temp->um[i];
    }

    temp->isend = true;
}

void display(Trie *root, string s)
{
    if (root->isend)
    {
        cout << s << endl;
    }

    for (auto i : root->um)
    {
        s += i.first;
        display(i.second, s);
        s.pop_back();
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;

    string ele;
    Trie* root = nullptr;
    lp(i, n)
    {
        cin >> ele;
        insert(root, ele);
    }
    display(root, "");
}

int main()
{
    // for t test cases
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // auto start = high_resolution_clock::now();
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        cout << "Case #" << t << ": ";
        solve();
        t++;
    }
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cerr << duration.count() / 1000000 << " S " << endl;
}