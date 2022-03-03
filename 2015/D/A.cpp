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

// Yes/ No for CodeForces ---------------
// # define 	yes 			cout << "YES" << endl
// # define 	no 				cout << "NO" << endl

using namespace std;

int R, C, n, maxnum = 10000000;
char mat[105][105];
vector<vector<int>> vis;
int dir[4][2]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool safe(int x, int y)
{
    return (x >= 0 and y >= 0 and x < C and y < R and mat[y][x] == '1' and !vis[y][x]);
}

bool safe_fill(int x, int y, int cur_num)
{
    return (x >= 0 and y >= 0 and x < C and y < R and mat[y][x] == '1' and vis[y][x] == cur_num);
}

void dfs(int x, int y, int num)
{
    vis[y][x] = num;
    lp(i, 4)
    {
        int newx = x + dir[i][0], newy = y + dir[i][1];
        if (safe(newx, newy))
        {
            dfs(newx, newy, num);
        }
    }
}

int dfs_util()
{
    int count = 0;

    lp(i, R)
    {
        lp(j, C)
        {
            if (mat[i][j] == '1' and !vis[i][j])
            {
                count++;
                dfs(j, i, count);
            }
        }
    }

    // lp(i, R)
    // {
    //     lp(j, C)
    //     {
    //         cout << vis[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    return count;
}

int adj_one(int x, int y)
{
    set <int> temp;
    lp(i, 4)
    {
        int new_x = x + dir[i][0], new_y = y + dir[i][1];
        if (new_x >= 0 and new_y >= 0 and new_x < C and new_y < R and mat[new_y][new_x] == '1')
        {
            int cur_num = vis[new_y][new_x];
            temp.insert(cur_num);
        }
    }
    return temp.size();
}

void one(int x, int y)
{
    int new_x, new_y;
    lp(i, 4)
    {
        new_x = x + dir[i][0], new_y = y + dir[i][1];
        if (new_x >= 0 and new_y >= 0 and new_x < C and new_y < R and mat[new_y][new_x] == '1')
            break;
    }
    // cout << new_x << ' ' << new_y << endl;
    vis[y][x] = vis[new_y][new_x];
}

void dfs_fill(int x, int y, int cur_num, int num)
{
    vis[y][x] = num;
    lp(i, 4)
    {
        int newx = x + dir[i][0], newy = y + dir[i][1];
        if (safe_fill(newx, newy, cur_num))
        {
            dfs_fill(newx, newy, cur_num, num);
        }
    }
}

void fill(int x, int y)
{
    int new_x, new_y;
    lp(i, 4)
    {
        new_x = x + dir[i][0]; new_y = y + dir[i][1];
        if (new_x >= 0 and new_y >= 0 and new_x < C and new_y < R and mat[new_y][new_x] == '1')
            break;
    }
    // cout << new_x << ' ' << new_y << endl;
    int num = vis[new_y][new_x];
    vis[y][x] = num;

    lp(i, 4)
    {
        new_x = x + dir[i][0]; new_y = y + dir[i][1];
        if (new_x >= 0 and new_y >= 0 and new_x < C and new_y < R and mat[new_y][new_x] == '1' and vis[new_y][new_x] != num)
        {
            int cur_num = vis[new_y][new_x];
            dfs_fill(new_x, new_y, cur_num, num);
        }
    }
}

void fillzero(int x, int y)
{
    vis[y][x] = 0;
    lp(i, 4)
    {
        int new_x = x + dir[i][0], new_y = y + dir[i][1];
        if (new_x >= 0 and new_y >= 0 and new_x < C and new_y < R and mat[new_y][new_x] == '1' and vis[new_y][new_x])
        {
            int num = maxnum;
            int cur_num = vis[new_y][new_x];
            dfs_fill(new_x, new_y, cur_num, num);
            maxnum++;
        }
    }
}

void solve()
{
    cin >> R >> C;

    int max_num = max(R, C);
    vect;
    lp(i, max_num)
        v.eb(0);
    lp(i, max_num)
        vis.eb(v);

    lp(i, R)
            lp(j, C)
                cin >> mat[i][j];
    cin >> n;

    int count = dfs_util();

    lp(i, n)
    {
        char test;
        cin >> test;

        if (test == 'M')
        {
            int x, y;
            char z, before;
            cin >> x >> y >> z;
            before = mat[x][y];
            mat[x][y] = z;

            if (z == '1')
            {
                if(before == '1')
                    continue;

                int adj = adj_one(y, x);
                cout << "Adj : " << adj << endl; 
                if (adj == 0)
                {
                    count++;
                    continue;
                }
                else if (adj == 1)
                {
                    one(y, x);
                    continue;
                }
                else if (adj > 1)
                {
                    fill(y, x);
                    count -= (adj - 1);
                    continue;
                }
            }
            else
            {
                if (before == '0')
                    continue;

                int adj = adj_one(y, x);
                cout << "Adj : " << adj << endl;

                if (adj == 0)
                {
                    count--;
                    continue;
                }
                else if (adj == 1)
                {
                    vis[x][y] = 0;
                    continue;
                }
                else if (adj > 1)
                {
                    fillzero(y, x);
                    count += (adj - 1);
                    continue;
                }
            }
        }
        else    
            cout << count << endl;
        cout << "Vis : " << endl;
        lp(i, R)
        {
            lp(j, C)
            {
                cout << vis[i][j] << ' ';
            }
            cout << endl;
        }
        cout << "VIS End !" << endl;
    }

    // lp(i, R)
    // {
    //     lp(j, C)
    //     {
    //         cout << vis[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    // dfs_util();
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
        cout << "Case #" << t << ": " << endl;
        memset(mat, ' ', sizeof(mat));
        vis.clear();
        maxnum = 10000000;
        solve();
        t++;
    }
}