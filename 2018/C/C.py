def generate_parameter_array(N, x, y, C, D, E1, E2, F):
    array = [0]
    array.append((x + y) % F)
    for i in range(N - 1):
        old_x = x
        x = (C * x + D * y + E1) % F
        y = (D * old_x + C * y + E2) % F
        array.append((x + y) % F)
    return array


def solution():
    T = int(input())
    for t in range(1, T + 1):
        test_case = [int(n) for n in input().split(" ")]
        N = test_case[0]  # Length of the parameter array
        K = test_case[1]  # Number of exponential powers
        A = generate_parameter_array(N, *(test_case[2:]))
        result = 0
        mod = 10**9 + 7
        P_sum = K  # accumulator of the geometric progressions
        
        table = [1, K]
        result += (K * N * A[1])
        result %= mod
        for i in range(2, N+1):
            temp = table[i-1] + (i * (pow(i, K) - 1) / (i - 1)) % mod
            table.append(temp)
            result += (table[i] * A[i] * (N-i+1))
            result %= mod
        print('Case #{}: {}'.format(t, int(result)))
 
solution()