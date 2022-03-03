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

vector <int> left(vector <int> row, int n)
{
    vect;

    lp(i, n)
        if (row[i] != 0)
            v.eb(row[i]);
    
    vector <int> temp;

    for (int i = 0; i < v.size(); i++)
    {
        if (i < v.size() - 1 and v[i] == v[i+1])
        {
            temp.eb(2*v[i]);
            i++;
        }
        else
        {
            temp.eb(v[i]);
        }
    }
    
    return temp;
}

vector <int> right(vector <int> row, int n)
{
    vect;

    lp(i, n) if (row[i] != 0)
        v.eb(row[i]);

    reverse(ALL(v));

    vector<int> temp;

    for (int i = 0; i < v.size(); i++)
    {
        if (i < v.size() - 1 and v[i] == v[i + 1])
        {
            temp.eb(2 * v[i]);
            i++;
        }
        else
        {
            temp.eb(v[i]);
        }
    }

    return temp;

    // lp(i, n)
    // {
    //     row[i] = 0;
    // }

    // for (int i = 0; i < temp.size(); i++)
    // {
    //     row[n-1] = temp[i];
    //     n--;
    // }
}

vector <int> up(vector <int> row, int n)
{
    vect;

    lp(i, n) if (row[i] != 0)
        v.eb(row[i]);

    // vectprint(v);
    // cout << endl;

    vector<int> temp;

    for (int i = 0; i < v.size(); i++)
    {
        if (i < v.size() - 1 and v[i] == v[i + 1])
        {
            temp.eb(2 * v[i]);
            i++;
        }
        else
        {
            temp.eb(v[i]);
        }
    }

    return temp;
}

vector<int> down(vector<int> row, int n)
{
    vect;

    lp(i, n) if (row[i] != 0)
        v.eb(row[i]);

    // vectprint(v);
    // cout << endl;

    reverse(ALL(v));

    vector<int> temp;

    for (int i = 0; i < v.size(); i++)
    {
        if (i < v.size() - 1 and v[i] == v[i + 1])
        {
            temp.eb(2 * v[i]);
            i++;
        }
        else
        {
            temp.eb(v[i]);
        }
    }

    return temp;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int arr[n][n];

    lp(i, n)
        lp(j, n)
            cin >> arr[i][j];
    
    if (s == "left")
    {
        lp(i, n)
        {
            vector <int> row;

            lp(j, n)
            {
                row.eb(arr[i][j]);
            }

            vector <int> new_v = left(row, n);

            lp(j, n)
            {
                if (j < new_v.size())
                    arr[i][j] = new_v[j];
                else
                    arr[i][j] = 0;
            }
        }
    }
    else if ( s== "right")
    {
        lp(i, n)
        {
            vector<int> row;

            lp(j, n)
            {
                row.eb(arr[i][j]);
            }

            vector<int> new_v = right(row, n);

            int count = 0;
            for (int j = n - 1; j >= 0; j--)
            {
                if (count < new_v.size())
                    arr[i][j] = new_v[count];
                else
                    arr[i][j] = 0;
                count++;
            }
        }
    }

    else if (s == "up")
    {
        lp(i, n)
        {
            vector <int> row;

            lp(j, n)
            {
                row.eb(arr[j][i]);
            }

            vector <int> new_v = up(row, n);

            lp(j, n)
            {
                if (j < new_v.size())
                    arr[j][i] = new_v[j];
                else
                    arr[j][i] = 0;
            }
        }
    }

    else if (s == "down")
    {
        lp(i, n)
        {
            vector<int> row;

            lp(j, n)
            {
                row.eb(arr[j][i]);
            }

            vector<int> new_v = down(row, n);

            int count = 0;
            for (int j = n-1; j >= 0; j--)
            {
                if (count < new_v.size())
                    arr[j][i] = new_v[count];
                else
                    arr[j][i] = 0;
                count++;
            }
        }
    }

    lp(i, n)
    {
        lp(j, n)
        {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
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