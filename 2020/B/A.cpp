# include <bits/stdc++.h>

using namespace std;

int solve(int n, vector <int> v){
    int count = 0;

    for (int i = 1; i < n-1; i++){
        if (v[i] > v[i+1] and v[i] > v[i-1]) count ++;
    }

    return count;
}

int main(){

    int T, t = 1; cin >> T;

    while (t <= T){
        int N, ele; cin >> N;
        vector <int> v;

        for (int n = 0; n < N; n++){
            cin >> ele;
            v.push_back(ele);
        }

        int num = solve(N, v);

        cout << "Case #" << t << ": " << num << endl;

        t++;
    }
}