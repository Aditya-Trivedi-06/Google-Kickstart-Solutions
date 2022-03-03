#include <bits/stdc++.h>

#define ll long long
#define ld double
#define uint unsigned int
#define ull unsigned long long

#define ff first
#define ss second

// For Loops ----------------------------

#define lp(n) for (int i = 0; i < n; i++)
#define lp1(n) for (int i = 1; i < n; i++)
#define dlp(n)                  \
    for (int i = 0; i < n; i++) \
        for (int j = 0; j < n; j++)

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

#define bn begin
#define rs resize
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

#define yes cout << "YES" << endl
#define no cout << "NO" << endl

// Google KickStart ---------------------

#define vectcase vector<int> vcase
#define vcaseprint                                          \
    int countcase = 1;                                      \
    for (auto i : vcase)                                    \
    {                                                       \
        cout << "Case #" << countcase << ": " << i << endl; \
        countcase++;                                        \
    }

using namespace std;
vector<vector<int>> mat;

int dx[] = {1, 0, -1, 0};
int dy[] = {0,1,0,-1};
 
bool isvalid(int x,int y, int r, int c) {
	return x >= 0 and y >= 0 and x < r and y < c;
}

void init(int r, int c){
    vector <int> temp (c, -1);
    for (int i = 0; i < r; i++){
        mat.push_back(temp);
    }
} 

void bfs (int i, int j, int r, int c){
    mat[i][j] = 0;

    queue <pair <int, int>> q;
    q.push({i, j});

    while (!q.empty()){
        i = q.front().first;
        j = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++){

            int u = i + dx[k];
            int v = j + dy[k];

            if (isvalid(u, v, r, c)){
                if (mat[u][v] == -1){
                    mat[u][v] = mat[i][j] + 1;
                    q.push({u, v});
                }
                else {
                    if (mat[i][j]+1 < mat[u][v]){
                        mat[u][v] = mat[i][j]+1;
                        q.push({u, v});
                    }
                }
            }
        }
    }
}

int solve(int r, int c){
    int maxnum = -1, x, y;
    for (int i = 0 ;i < r; i++){
        for (int j = 0 ; j < c; j++){
            if (mat[i][j] > maxnum) {
                maxnum = mat[i][j];
                x = i;  y = j;
            }
        }
    }

    bfs(x, y, r, c);

    int max = -1;
    for (int i = 0 ;i < r; i++){
        for (int j = 0 ; j < c; j++){
            if (mat[i][j] > max) {
                max = mat[i][j];
                x = i;  y = j;
            }
        }
    }

    return max;
}

int main()
{
    // for t test cases
    int t;
    vectcase;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector <string> temp;
        for (int j = 0; j < r; j++){
            string s;   cin >> s;
            temp.push_back(s);
        }
        vector < vector <int>> arr (r, vector <int> (c, 0));
        
        for (int i = 0; i < r; i++)
        {
            string s2 = temp[i];
            for (int j = 0; j< c; j++){
                if (s2[j] == '1') arr[i][j] = 1;
            }
        }

        init(r, c);

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (arr[i][j] == 1){
                    bfs(i, j, r, c);
                }
            }
        }
        int num = solve(r, c);
        vcase.push_back(num);
        for (auto i : mat)
            i.clear();
    }
    vcaseprint
}