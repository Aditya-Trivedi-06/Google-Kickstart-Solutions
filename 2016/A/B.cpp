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

int mat[51][51], r, c;

int dxy[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool update(int prev_sum)
{
    int new_sum = 0;

    lp(i, r)
        lp(j, c)
            new_sum += mat[i][j];
        
    if (new_sum == prev_sum)
        return false;

    return true;
}

int util(int prev_sum)
{
    for (int i = 1; i < r - 1; i++)
    {
        for (int j = 1; j < c - 1; j++)
        {
            int cur_num = mat[i][j];
            int min_num = INT16_MAX;
            lp(k, 4)
            {
                int x = j + dxy[k][0], y = i + dxy[k][1];
                min_num = min(min_num, mat[x][y]);
            }
            cout << cur_num << ' ' << min_num << endl;
            if (cur_num < min_num)
            {
                cout << "Min_num" << min_num << endl;
                mat[i][j] = min_num;
            }
        }
    }
    int new_sum = prev_sum;
    cout << new_sum << endl;

    while(update(new_sum))
    {
        for (int i = 1; i < r - 1; i++)
        {
            for (int j = 1; j < c - 1; j++)
            {
                int cur_num = mat[i][j];
                int min_num = INT16_MAX;
                lp(k, 4)
                {
                    int x = j + dxy[k][0], y = i + dxy[k][1];
                    min_num = min(min_num, mat[x][y]);
                } 
                if (cur_num < min_num)
                {
                    mat[i][j] = min_num;
                }
            }
        }

        lp(i, r)
        {
            lp(j, c)
            {
                cout << mat[i][j] << ' ';
            }
            cout << endl;
        }

        new_sum = 0;

        lp(i, r)
            lp(j, c)
                new_sum += mat[i][j];
    }
    
    return new_sum;
}

void solve()
{
    cin >> r >> c;

    int sum = 0;

    lp(i, r)
    {
        lp(j, c)
        {
            cin >> mat[i][j];
            sum += mat[i][j];
        }
    }
    cout << sum << endl;
    int new_sum = util(sum);

    cout << new_sum - sum << endl;

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
        memset(mat, 0, sizeof(mat));
        solve();
        t++;
    }
}