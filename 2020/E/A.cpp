# include <bits/stdc++.h>

using namespace std;

int solve(vector <int> v, int n){
    int count = 1, maxnum = 1;

    for (int i = 1; i < n - 1; i++){
        if (v[i] == v[i-1]) count ++;
        else count = 1;
        maxnum = max(count, maxnum);
    }

    return maxnum+1;
}

int main(){

    int T, t = 1; cin >> T;

    while (t <= T){
        int N, ele, temp = 0; cin >> N;
        vector <int> v;

        for (int n = 0; n < N; n++){
            cin >> ele;
            v.push_back(ele);
        }
        vector <int> diff;

        for (int i = 1; i < N; i++){
            diff.push_back(v[i]-v[i-1]);
        }

        int num = solve(diff, N);

        cout << "Case #" << t << ": " << num << endl;

        t++;
    }
}