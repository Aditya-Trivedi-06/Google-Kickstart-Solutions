#include <stdio.h>
#include <unordered_map>
#include <string>
#include <iostream>
#include <memory.h>
#include <stdlib.h>
#include <set>
#include <cmath>
#include <vector>
#include <algorithm>

#define MASK 0x10000
#define MAXN 100

using namespace std;

typedef long long lld;
typedef vector<pair<int, int>> CONSTYPE;

const int SMASK = (1 << 15) - 1;
const lld INF = pow(10, 18) + 1;
int cnt[MASK], toZero[MASK];
CONSTYPE cons[MAXN];
lld f[MAXN][MASK];

bool ableV(int last, int b)
{
    for (auto &con : cons[b])
    {
        if (cnt[last & ((1 << con.first) - 1)] != con.second)
            return false;
    }
    return true;
}

lld add(lld a, lld b)
{
    if (a == INF || b == INF)
        return INF;
    return min(INF, a + b);
}

void generateF(int n)
{
    for (int last = 0; last < MASK; last++)
        if (ableV(last, n - 1))
            f[n - 1][last] = 1;
    for (int i = n - 2; i >= 0; --i)
    {
        for (int last = 0; last < MASK; ++last)
        {
            if (ableV(last, i))
            {
                f[i][last] = add(f[i + 1][toZero[last]], f[i + 1][toZero[last] ^ 1]);
            }
        }
    }
}

void solve(int n, lld p)
{
    memset(f, 0, sizeof(lld) * MASK * MAXN);
    generateF(n);
    int last = 0;
    for (int i = 0; i < n; ++i)
    {
        lld base = f[i][toZero[last]];
        if (p > base)
        {
            printf("1");
            last = toZero[last] ^ 1;
            p -= base;
        }
        else
        {
            last = toZero[last];
            printf("0");
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("outputHELP.txt", "w", stdout);

    for (int i = 0; i < MASK; ++i)
    {
        cnt[i] = cnt[i >> 1] + (i & 1);
        toZero[i] = (i & SMASK) << 1;
    }
    int t;
    scanf("%d", &t);
    for (auto round = 1; round <= t; ++round)
    {
        int n, k;
        lld p;
        scanf("%d%d%lld", &n, &k, &p);
        for (int i = 0; i < n; ++i)
            cons[i].clear();
        for (int i = 0; i < k; ++i)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            cons[b - 1].push_back(make_pair(b - a + 1, c));
        }
        printf("Case #%d: ", round);
        solve(n, p);
        printf("\n");
    }
}
