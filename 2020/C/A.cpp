# include <bits/stdc++.h>

using namespace std;

int solve(int n, vector <int> v, int k){
    int count = 0, sum = 0;

    for (int i = 0; i < n; i++){
        if (v[i] == k){
            if (v[i+v[i]-1] == 1){
                while (v[i+1] == v[i]-1){
                    i++;
                    count++;
                    if (v[i] == 1) break;
                }
            }
            if (count == k-1) sum++;
            count = 0;
        }
    }

    return sum;
}

int main(){

    int T, t = 1; cin >> T;

    while (t <= T){
        int N, ele, k; cin >> N >> k;
        vector <int> v;

        for (int n = 0; n < N; n++){
            cin >> ele;
            v.push_back(ele);
        }

        int num = solve(N, v, k);

        cout << "Case #" << t << ": " << num << endl;

        t++;
    }
}