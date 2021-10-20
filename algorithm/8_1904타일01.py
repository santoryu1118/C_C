import sys
N = int(input())

# sys.setrecursionlimit(107)
# stack = [0] *N
# stack[0] = 1

# if N != 1:
#     stack[1] = 2

# def fibonacci(n):
#     if n < 1:
#         return 0
#     if stack[n-1] != 0:
#         return stack[n-1]
#     else:
#         stack[n-1] = (fibonacci(n-1) + fibonacci(n-2)) %15746
#         return stack[n-1]

# print(fibonacci(N))

stack = [1,2]
for i in range(2, N):
    stack.append(stack[i-1] + stack[i-2])
print(stack[-1])