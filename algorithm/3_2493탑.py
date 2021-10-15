import sys
sys.stdin = open('input.txt')
input = sys.stdin.readline

N = int(input())
buildings = list(map(int, input().split()))
stack = [(0,0)]
answer = []

# 각 빌딩마다
for i in range(N):

    # stack 에 남아있는 빌딩 높이마다
    while len(stack) != 0:

        # 지금 빌딩이 더 높거나 스택에 남아있는 빌딩 높이가 0일때
        if buildings[i] > stack[-1][0] and stack[-1][0] != 0:
            stack.pop()
        
        # 새로 들어온 빌딩이 스택 맨 오른쪽보다 낮을 때
        else :
            answer.append(stack[-1][1])
            stack.append((buildings[i], i+1))
            break

for ans in answer:
    print(ans, end=' ')

