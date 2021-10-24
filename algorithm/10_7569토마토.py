import sys
from collections import deque
sys.stdin = open('input.txt')
input = sys.stdin.readline

X, Y, H = map(int, input().split())

box = [[[0] *X for _ in range(Y)] for _ in range(H)]

stack = deque()
for h in range(H):
    for y in range(Y):
        box[h][y] = list(map(int, input().split()))
        # box안에 input넣어주면서 동시에 토마토 1인 부분 stack에 담아주기
        for x in range(X):
            if box[h][y][x] == 1:
                stack.append((h,y,x))

dx = [1,0,-1,0,0,0]
dy = [0,1,0,-1,0,0]
dh = [0,0,0,0,1,-1]

while len(stack) != 0:
    h,y,x = stack.popleft()
    for i in range(6):
        newh, newy, newx = h + dh[i], y + dy[i], x + dx[i]
        # index out of bound check
        if 0 <= newh and newh <H and 0 <= newy and newy < Y and 0 <= newx and newx < X:
            if box[newh][newy][newx] == 0:
                box[newh][newy][newx] = box[h][y][x] + 1
                stack.append((newh, newy, newx))

time_needed = 0
for h in range(H):
    for y in range(Y):
        for x in range(X):
            if box[h][y][x] == 0:
                print(-1)
                exit()
            time_needed = max(time_needed, box[h][y][x])

print(time_needed-1)