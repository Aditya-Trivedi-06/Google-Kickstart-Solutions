T = int(input())
mod = 10**9 + 7

for t in range(1, T+1):
    r, c = map(int, input().split())
    n = min(r,c)
    first = (n*(n+1))// 2
    first = first % mod
    second = ((n*(n+1)*((2*n)+1)) // 6)*(r+c) 
    second = second % mod
    third = first * (r*c)
    third = third % mod
    first = first * first
    first = first % mod
    ans = first + third - second
    ans = ans % mod

    print(f'Case #{t}: {ans}')