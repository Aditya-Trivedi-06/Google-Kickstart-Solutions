import math

T = int(input())
for x in range(1, T + 1):
    N = int(input())
    B = 0
    print(int(math.log(N, 2)))
    print(int(math.log(N, 3)))
    print(int(math.log(N, 4)))
    for n in range(int(math.log(N, 2)), 1, -1):
        b = int(N ** (1 / n))
        # print (n, b)
        if (b ** (n + 1) - 1) // (b - 1) == N:
            B = b
            break
    if not B:
        B = N - 1
    print(f"Case #{x}: {B}")
