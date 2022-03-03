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

#define INF INT_MAX

using namespace std;
using namespace std::chrono;

unordered_map<string, char> um;

bool issafe(int f, int s)
{
    if (f < 65 or f > 72 or s < 1 or s > 8)
        return false;
    
    return true;
}

int king(string pos)
{
    int total = 0;

    int dir[8][2] {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    int fnum = int(pos[0]), snum = pos[1] - '0';

    for (int i = 0; i < 8; i++)
    {
        int newf = fnum + dir[i][0], news = snum + dir[i][1];
        if (issafe(newf, news))
        {
            string s = "";
            s += char(newf);
            s += to_string(news);

            // cout << s << endl;

            if (um.find(s) != um.end())
                total++;
        }
    }
    return total;
}

int knight(string pos)
{
    int total = 0;

    int dir[8][2]{{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

    int fnum = int(pos[0]), snum = pos[1] - '0';

    for (int i = 0; i < 8; i++)
    {
        int newf = fnum + dir[i][0], news = snum + dir[i][1];
        if (issafe(newf, news))
        {
            string s = "";
            s += char(newf);
            s += to_string(news);

            if (um.find(s) != um.end())
                total++;
        }
    }
    return total;
}

int pawn(string pos)
{
    int total = 0;

    int dir[2][2]{{1, 1}, {1, -1}};

    int fnum = int(pos[0]), snum = pos[1] - '0';

    for (int i = 0; i < 2; i++)
    {
        int newf = fnum + dir[i][0], news = snum + dir[i][1];
        if (issafe(newf, news))
        {
            string s = "";
            s += char(newf);
            s += to_string(news);
            // cout << s << endl;
            if (um.find(s) != um.end())
                total++;
        }
    }
    return total;
}

bool found(int f, int s)
{
    string temp = "";
    temp += char(f);
    temp += to_string(s);

    return (um.find(temp) != um.end());
}   

int queen(string pos)
{
    int total = 0;
    int fnum = int(pos[0]), snum = pos[1] - '0';

    int tempf = fnum;
    while (true)
    {
        tempf++;
        if (!issafe(tempf, snum))
        {
            break;
        }
        if (found(tempf, snum))
        {
            total++;
            break;
        }
    }

    tempf = fnum;
    while (true)
    {
        tempf--;
        if(!issafe(tempf, snum))
        {
            break;
        }
        if (found(tempf, snum))
        {
            total++;
            break;
        }
    }

    int temps = snum;
    while (true)
    {
        temps++;
        if (!issafe(fnum, temps))
        {
            break;
        }
        if (found(fnum, temps))
        {
            total++;
            break;
        }
    }

    temps = snum;
    while (true)
    {
        temps--;
        if (!issafe(fnum, temps))
        {
            break;
        }
        if (found(fnum, temps))
        {
            total++;
            break;
        }
    }

    tempf = fnum;
    temps = snum;
    while (true)
    {
        tempf++;
        temps++;

        if (!issafe(tempf, temps))
        {
            break;
        }
        if (found(tempf, temps))
        {
            total++;
            break;
        }
    }

    tempf = fnum;
    temps = snum;
    while (true)
    {
        tempf++;
        temps--;

        if (!issafe(tempf, temps))
        {
            break;
        }
        if (found(tempf, temps))
        {
            total++;
            break;
        }
    }

    tempf = fnum;
    temps = snum;
    while (true)
    {
        tempf--;
        temps++;

        if (!issafe(tempf, temps))
        {
            break;
        }
        if (found(tempf, temps))
        {
            total++;
            break;
        }
    }

    tempf = fnum;
    temps = snum;
    while (true)
    {
        tempf--;
        temps--;

        if (!issafe(tempf, temps))
        {
            break;
        }
        if (found(tempf, temps))
        {
            total++;
            break;
        }
    }

    return total;
}

int bishop(string pos)
{
    int total = 0;
    int fnum = int(pos[0]), snum = pos[1] - '0';

    int tempf = fnum;
    int temps = snum;
    while (true)
    {
        tempf++;
        temps++;

        if (!issafe(tempf, temps))
        {
            break;
        }
        if (found(tempf, temps))
        {
            total++;
            break;
        }
    }

    tempf = fnum;
    temps = snum;
    while (true)
    {
        tempf++;
        temps--;

        if (!issafe(tempf, temps))
        {
            break;
        }
        if (found(tempf, temps))
        {
            total++;
            break;
        }
    }

    tempf = fnum;
    temps = snum;
    while (true)
    {
        tempf--;
        temps++;

        if (!issafe(tempf, temps))
        {
            break;
        }
        if (found(tempf, temps))
        {
            total++;
            break;
        }
    }

    tempf = fnum;
    temps = snum;
    while (true)
    {
        tempf--;
        temps--;

        if (!issafe(tempf, temps))
        {
            break;
        }
        if (found(tempf, temps))
        {
            total++;
            break;
        }
    }

    return total;
}

int rook(string pos)
{
    int total = 0;
    int fnum = int(pos[0]), snum = pos[1] - '0';

    int tempf = fnum;
    while (true)
    {
        tempf++;
        if (!issafe(tempf, snum))
        {
            break;
        }
        if (found(tempf, snum))
        {
            total++;
            break;
        }
    }

    tempf = fnum;
    while (true)
    {
        tempf--;
        if (!issafe(tempf, snum))
        {
            break;
        }
        if (found(tempf, snum))
        {
            total++;
            break;
        }
    }

    int temps = snum;
    while (true)
    {
        temps++;
        if (!issafe(fnum, temps))
        {
            break;
        }
        if (found(fnum, temps))
        {
            total++;
            break;
        }
    }

    temps = snum;
    while (true)
    {
        temps--;
        if (!issafe(fnum, temps))
        {
            break;
        }
        if (found(fnum, temps))
        {
            total++;
            break;
        }
    }

    return total;
}

void solve()
{
    int n;
    cin >> n;

    lp(i, n)
    {
        string s;
        cin >> s;
        um.insert(mp(s.substr(0, 2), s[3]));
    }

    // for (auto i : um)
    // {
    //     cout << i.ff << " : " << i.ss << endl;
    // }   

    int sum = 0;

    for (auto i : um)
    {
        char piece = i.ss;
        switch (piece)
        {
        case 'K': 
            sum += king(i.ff);
            // cout << king(i.ff) << endl;
            break;
        case 'Q':
            sum += queen(i.ff);
            // cout << queen(i.ff) << endl;
            break;
        case 'R':
            sum += rook(i.ff);
            break;
        case 'B':
            sum += bishop(i.ff);
            break;
        case 'N':
            sum += knight(i.ff);
            break;
        case 'P':
            sum += pawn(i.ff);
            // cout << pawn(i.ff) << endl;
            break;
        
        default:
            break;
        }
    }

    cout << sum << endl;
}

int main()
{
    // for t test cases
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // auto start = high_resolution_clock::now();
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        cout << "Case #" << t << ": ";
        solve();
        um.clear();
        // cerr << "Case : " << t << " Solved !" << endl;
        t++;
    }
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cerr << duration.count() / 1000000 << " S " << endl;
}