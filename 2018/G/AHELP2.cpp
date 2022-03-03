#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <ctime>
using namespace std;

// Kickstart Round G Problem A. Product Triplets

const int maxn = 7010;
int T;
int N;
long long A[maxn];
long long ans;
long long compare()
{
    long long ret = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                if (A[i] * A[j] == A[k] || A[i] * A[k] == A[j] || A[k] * A[j] == A[i])
                {
                    cout << A[i] << " " << A[j] << " " << A[k] << endl;
                    ret++;
                    if (ret < 0)
                    {
                        cout << "error " << ret << endl;
                    }
                }
            }
        }
    }
    return ret;
}
int main()
{
    //   int x0=2*1e5;
    //   long long x1=2*1e5;
    //   cout<<x0*x0<<" "<<x1*x1<<endl;
    //   long long x=65537;
    //   long long y=131073;
    //   cout<<x*x<<endl;
    //   return 0;
    // use long long for A[i], otherwise, overflow, when overflow, a*b can still be positive, ahrd to find out
    // freopen("input.txt","r",stdin);
    // freopen("A-large-practice.in", "r", stdin);
    // freopen("A.txt", "w", stdout);
    clock_t START_TIME;
    clock_t FINISH_TIME;
    START_TIME = clock();
    scanf("%d", &T);

    for (int ca = 1; ca <= T; ca++)
    {
        memset(A, 0, sizeof(A));
        ans = 0;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        //       printf("Case #%d: %d\n",ca,compare());
        //       continue;
        sort(A, A + N);
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                //               cout<<A[i]<<" and "<<A[j]<<endl;
                long long goal = A[i] * A[j];
                long long pos0 = lower_bound(A + j + 1, A + N, goal) - A;
                long long pos1 = upper_bound(A + j + 1, A + N, goal) - A;
                if (pos0 == N)
                {
                    continue;
                }
                else if (A[pos0] > goal)
                {
                    //                   cout<<A[pos0]<<" "<<A[pos1]<<endl;
                    continue;
                }
                else
                {
                    //                   cout<<A[pos0]<<" "<<A[pos1]<<" "<<pos0<<" "<<pos1<<endl;
                    ans += pos1 - pos0;
                }
            }
        }
        // deal with 0, as 0 * x=0, is not in increasing order
        long long pos0 = lower_bound(A, A + N, 0) - A;
        long long pos1 = upper_bound(A, A + N, 0) - A;
        //       cout<<pos0<<" "<<pos1<<endl;
        if (pos0 != N && pos1 != N && A[pos0] == 0) // 0 exists and not all are 0
        {
            if (pos1 - pos0 >= 2) // at least 2 zeros
            {
                long long tmp = (pos1 - pos0) * (pos1 - pos0 - 1) / 2 * (N - pos1);
                ans += tmp;
            }
        }
        printf("Case #%d: %lld\n", ca, ans);
        cerr << "finish case " << ca << endl;
    }

    FINISH_TIME = clock();
    cerr << 1.0 * (FINISH_TIME - START_TIME) / CLOCKS_PER_SEC << " (s) " << endl;
    return 0;
}