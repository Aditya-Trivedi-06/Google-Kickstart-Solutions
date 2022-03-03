import sys
from math import exp, log
sys.stdout = open('output.txt', 'wt')

T = int(input())

for t in range(0, T):
    print("Case #{}:".format(t+1))
    n, m = map(int, input().split())
    arr = [int(x) for x in input().split()]

    for i in range(m):
        l, r = map(int, input().split())
        prod = 1
        for j in range(l, r+1):
            prod *= arr[j]
        
        

        # print("prod : ", prod)
        
        # low = 1.00000
        # high = prod % 10e9+7
        n = r-l+1

        ans = exp(log(prod)/n)
        print('{:.10f}'.format(ans))

        # for j in range(100000):
        #     mid = low + (high - low) / 2
        #     mid_power_n = pow(mid, n)
        #     # print(mid_power_n)
        #     # if mid_power_n == prod:
        #     #     break

        #     if mid_power_n > prod:
        #         high = mid

        #     else :
        #         low = mid + 1e-8
        
        # print('{:.10f}'.format(high))
        
# def power(num, n):
#     low = 1
#     high = num

#     for i in range(100):
#         mid = low + (high - low) / 2
#         mid_power_n = pow(num, n)

#         if mid_power_n > num:
#             high = mid

#         else :
#             low = mid + 1
    
#     return high