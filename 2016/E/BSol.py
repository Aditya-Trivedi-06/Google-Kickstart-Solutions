import math

T = int(input())
mod = 10**9 + 7

for t in range(1, T+1):
    n = int(input())
    val = int(math.log2(n));
    ans = 0
    for i in range(val, 1, -1):
        base = int(pow(n, 1/i))

        if (pow(base, i+1) - 1) // (base - 1) == n:
            ans = base
            break
    
    if ans == 0:
        ans = n-1

    print(f'Case #{t}: {ans}')
