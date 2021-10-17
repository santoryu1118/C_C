import sys
from collections import deque
sys.stdin = open('input.txt')
input = sys.stdin.readline

Y, X = map(int, input().split())
maze = [list(map(int, input().strip())) for _ in range (Y)]

maze_bool = [[False for _ in range (X)] for _ in range (Y)]
maze_bool[0][0] = 1

que = deque([(0,0)])

dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]

while maze_bool[Y-1][X-1] == False:
    prev_y, prev_x = que.popleft()
    for i in range (4):
        new_y, new_x = prev_y + dy[i], prev_x + dx[i]
        # 맵 밖으로 나갔거나 (얘네 먼저 확인해줘야함 index error 안뜰려면) maze에 얘네는 못가는 길이거나 (0)
        # 아니면 이미 방문했던 길이라 이미 최소 거리가 등록되어있으면 que에 또 넣어줄 필요없다
        if new_y >= Y or new_y < 0 or new_x >= X or new_x < 0 or \
            maze[new_y][new_x] == 0 or maze_bool[new_y][new_x] != False:
            continue
        else:
            que.append((new_y, new_x))
            maze_bool[new_y][new_x] = maze_bool[prev_y][prev_x] + 1

print(maze_bool[Y-1][X-1])

