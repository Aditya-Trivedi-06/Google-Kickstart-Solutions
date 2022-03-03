#include <bits/stdc++.h>

using namespace std;

int dp[26][100005];

int main()
{
    int T, t = 1;
    cin >> T;

    for (t; t <= T; t++)
    {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;

        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                dp[j][i + 1] = dp[j][i];
            }
            dp[s[i] - 'A'][i + 1]++;
        }
        // for (int i = 0; i < 26 ; i++){
        //     for (int j = 0; j <= n; j++){
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << endl;
        // }

        int ans = 0;

        for (int i = 0; i < q; i++)
        {
            int l, r;
            cin >> l >> r;
            l--;
            int cnt = 0;

            for (int j = 0; j < 26; j++)
            {
                if ((dp[j][r] - dp[j][l]) & 1)
                    cnt++;
            }
            if (cnt <= 1)
                ans++;
        }

        cout << "Case #" << t << ": " << ans << endl;
    }
}