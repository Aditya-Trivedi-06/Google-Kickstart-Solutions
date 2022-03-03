from audioop import reverse
import math

T = int(input())
mod = 10**9 + 7

def convert(n):
    s = ""

    while n > 0:
        rem = n % 2
        s = str(rem) + s
        n = n // 2
    
    return s


def binary(s):
    count = 0
    ans = 0
    for i in s:
        if i == '1':
            ans += pow(2, count)
        count += 1
    
    return ans


for t in range(1, T+1):
    q, *n = map(int, input().split())

    if q == 1:
        num = convert(n[0])
        top = 1
        bot = 1
        # print(num)
        for i in num[1:]:

            if i == '0':
                bot += top
            else:
                top += bot
        
        print(f'Case #{t}: {top} {bot}')
    
    else:
        top = n[0]
        bot = n[1]
        s = ""

        while top > 1 or bot > 1:
            
            # print(top)
            # print(bot)

            if top < bot:
                bot -= top
                s += '0'
            else:
                top -= bot
                s += '1'
        s += '1'

        # temp = s[::-1]
        # print(s)
        ans = binary(s)

        print(f'Case #{t}: {ans}')
