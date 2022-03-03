# include <bits/stdc++.h>

using namespace std;

int solve(int total, int n, vector <int> v){
    int count = 0;

    for (int i = 0; i < n; i++){
        if (total >= v[i]){
            total -= v[i];
            count++;
        }
    }

    return count;
}

int main(){

    int T, t = 1; cin >> T;

    while (t <= T){
        int N, total, ele; cin >> N >> total;
        vector <int> v;

        for (int n = 0; n < N; n++){
            cin >> ele;
            v.push_back(ele);
        }

        sort(v.begin(), v.end());

        int num = solve(total, N, v);

        cout << "Case #" << t << ": " << num << endl;

        t++;
    }
}