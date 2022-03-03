import sys
# sys.stdout = open('output.txt', 'wt')

def binomialCoeff(n, k):

    # Declaring an empty array
    C = [0 for i in range(k+1)]
    C[0] = 1  # since nC0 is 1

    for i in range(1, n+1):

        # Compute next row of pascal triangle using
        # the previous row
        j = min(i, k)
        while (j > 0):
            C[j] = C[j] + C[j-1]
            j -= 1

    return C[k]


T = int(input())

mod = 1000000007

for t in range(0, T):
    m, n = map(int, input().split())
    dp = []
    for i in range(105) :
        dp.append(1)
    
    for i in range(2, m+1):
        ans = pow(i, n)
        for j in range(1, i):
            comb = binomialCoeff(i, j)
            comb *= dp[j]
            ans -= comb
        dp[i] = ans
        dp[i] = dp[i] % mod
    print("Case #{}: {}".format(t+1, dp[m]))
    # print(dp[m])
    # print('\n')