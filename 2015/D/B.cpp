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

# define INF INT_MAX

int n, m, q;
vect(vm);
vect(vel);
vector <pair <int, int>> vp;

bool poss()
{
    int energy = 0;

    lp(i, n)
    {
        int pos = vp[i].ff, level = vp[i].ss;
        if (pos == 0)
            continue;
        if (pos > 0)
        {
            if (vel[level] < 0)
                continue;

            int ue = 0, de = 0;
            int up = level + 1, down = level - 1;

            while (up < m and vel[up] < 0)
            {
                up++;
                ue++;
            }
            while (down > -1 and vel[down] < 0)
            {
                down++;
                de++;
            }
            if (ue == 0 and de == 0)
                return false;
            energy += min(de, ue);
        }
        else 
        {
            if (vel[level] > 0)
                continue;

            int ue = 0, de = 0;
            int up = level + 1, down = level - 1;

            while (up < m and vel[up] > 0)
            {
                up++;
                ue++;
            }
            while (down > -1 and vel[down] > 0)
            {
                down++;
                de++;
            }
            if (ue == 0 and de == 0)
                return false;
            energy += min(de, ue);
        }
    }

    if (energy > q)
        return false;
    
    return true;
}

ll ans = INF;

ll min_time(int index, int energy, ll time)
{
    // cout << index << ' ' /<< energy << endl;
    // cout << index << ' ' << time << endl;

    if (index >= n)
    {
        ans = min(ans, time);
        // time = INF;
        return ans;
    }

    if (energy > q)
        return INF;


    int pos = vp[index].ff, height = vp[index].ss;

    if (pos == 0)
        return min_time(index + 1, energy, time);

    for (int i = 0; i < m; i++)
    {
        if (pos * vel[i] >= 0)
            continue;
        
        int v = abs(vm[i]);
        int e = abs(height - i), t = ceil(abs(pos) / v);
        // cout << "T : " << t << endl;
        time = min(min_time(index + 1, energy + e, time + t), time);
        // cout << time << endl;
    }
}

void solve()
{
    cin >> n >> m >> q;
    vm.resize(m+1);
    vel.resize(m+1, 0);
    lp(i, m)
    {
        cin >> vm[i];
        if (vm[i] > 0)
            vel[i] = 1;
        else if (vm[i] < 0 )
            vel[i] = -1;
    }
    lp(i, n)
    {
        int p, h;
        cin >> p >> h;
        vp.eb(mp(p, h));
    }

    if (!poss())
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    cout << min_time(0, 0, INF) << endl;
    cout << ans << endl;
}

int main()
{
    // for t test cases
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // auto start = high_resolution_clock::now();
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        cout << "Case #" << t << ": ";
        solve();
        ans = INF;
        vp.clear();
        vm.clear();
        vel.clear();
        t++;
    }
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cerr << duration.count() / 1000000 << " S " << endl;
}