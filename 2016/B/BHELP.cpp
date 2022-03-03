# include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXK = 1e5;
ll i_A[MAXK + 1], j_B[MAXK + 1], i_j_same[MAXK + 1];

int pow_mod(int a, int n, int mod)
{
    int r = 1 % mod;
    while (n)
    {
        if (n & 1)
            r = (ll)r * a % mod;
        a = (ll)a * a % mod;
        n >>= 1;
    }

    return r;
}

int main(int argc, char *argv[])
{
#ifndef TEST
    if (argc != 2)
    {
        cout << "Invalid input" << endl;
        return 1;
    }

    string input = argv[1];
    string output = input.substr(0, input.length() - 2) + "out";
    freopen(input.c_str(), "r", stdin);
    freopen(output.c_str(), "w", stdout);
#endif

    const ll MOD = 1e9 + 7;

    int T;
    int A, B;
    ll N, K;

    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        memset(i_A, 0, sizeof(i_A));
        memset(j_B, 0, sizeof(j_B));
        memset(i_j_same, 0, sizeof(i_j_same));

        cin >> A >> B >> N >> K;
        ll res = 0;

        for (int p = 1; p <= min(N, K); p++)
        {
            ll cnt = ((N - p) / K + 1) % MOD;
            int tmp_A = pow_mod(p, A, K), tmp_B = pow_mod(p, B, K);
            i_A[tmp_A] += cnt;
            j_B[tmp_B] += cnt;
            if ((tmp_A + tmp_B) % K == 0) //(0 + 0) != K, but (0 + 0) % K == 0
                i_j_same[p % K] += cnt;
        }

        for (int p = 0; p < K; p++)
        {
            int q = (K - p) % K; // Convert (0, K) to (0, 0)
            res += ((i_A[p] % MOD) * (j_B[q] % MOD)) % MOD;
            res -= i_j_same[p];
            res %= MOD;
        }

        res += MOD;
        res %= MOD;

        cout << "Case #" << i << ": " << res << endl;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}