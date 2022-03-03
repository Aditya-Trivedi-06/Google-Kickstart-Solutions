#include <bits/stdc++.h>

using namespace std;

int a[1000010];
int am[1000010];

int main()
{
    int t;  cin >> t;
    for (int T = 1; T <= t; T++)
    {
        int n;
        cin >> n;

        memset(am, 0, 1000010);
        int ele;

        for (int i = 0; i < n; i++)
            cin >> ele,
            a[i] = ele;

        
        cout << "Case #" << T << ": ";

        int ans = 0, coun = 0;

        for (int i = 0; i < n; i++)
        {
            am[a[i]]++;
            
            if (a[i] >= ans)    coun++;

            if (coun - am[ans] >= ans + 1) {
                coun -= am[ans];
                ans++;
            }

            cout << ans << ' ';
        }
        cout << endl;
    }
}