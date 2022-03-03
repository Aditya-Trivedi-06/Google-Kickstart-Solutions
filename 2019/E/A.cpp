# include <bits/stdc++.h>

using namespace std;

void solve(){

    // vector < pair <int, int>> v;
    int n, m, a, b;
    cin >> n >> m;

    vector <int> adjlist[n+1];

    for (int i = 0; i < m; i++){
        cin >> a >> b;
        adjlist[a].push_back(b);
    }

    for (int i = 0; i <= n; i++){
        for (auto it = adjlist[i].begin(); it != adjlist[i].end(); it++) 
            cout << i << " : ",
            cout << *it << endl;
    }

    vector <bool> vis(n+1);

    for (int i = 0; i <= n; i++){
        for (auto it = adjlist[i].begin(); it != adjlist[i].end(); it++) {
            vis[i] = 1;
            vis[*it] = 1;
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) ans += 2;
        else ans ++;
    }

    cout << ans << endl;
}

int main(){
    int T, t = 1;
    cin >> T;

    for (t; t <= T; t++){
        cout << "Case #" << t << ": ";
        solve();
    }
}