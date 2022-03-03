# import sys
# sys.stdin = open('input.txt', 'r')
# f = open("output.txt", "a")

T = int(input())
mod = 10**9

for t in range(1, T+1):
    s = input()
    cur_num = 1
    stack = []
    x = 0
    y = 0
    for i in s:
        if i.isdigit():
            cur_num *= int(i)
            stack.append(int(i))
        if i == '(' :
            continue
        if i == ')' :
            cur_num //= stack[len(stack) - 1]
            stack.pop()
            continue
        else :
            if i == 'N' :
                y -= cur_num
            elif i == 'S':
                y += cur_num
            elif i == 'E':
                x += cur_num
            elif i == 'W':
                x -= cur_num
        
        y %= mod
        x %= mod

    print('Case #{}: {} {}'.format(t, x+1, y+1))

f.close()