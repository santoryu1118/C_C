import sys
from collections import deque
sys.stdin = open('input.txt')
input = sys.stdin.readline

Y, X = map(int, input().split())
maze = [list(map(int, input().strip())) for _ in range (Y)]
visited = [[False for _ in range (X)] for _ in range (Y)]
visited[0][0] = True

dy = [0,1,0,-1]
dx = [1,0,-1,0]
min_steps = 10e4

def search_route(y_pos, x_pos):
    global min_steps
    if y_pos == Y-1 and x_pos == X-1:
        min_steps = min(min_steps, maze[y_pos][x_pos])
        return
    
    # 갈 수 있는 길이라면
    for i in range(4):
        new_y, new_x = y_pos + dy[i], x_pos + dx[i]
        if new_y < 0 or new_y >= Y or new_x < 0 or new_x >=X or \
            maze[new_y][new_x] == 0 or visited[new_y][new_x] == True:
                continue
        else:
            visited[new_y][new_x] = True
            maze[new_y][new_x] = maze[y_pos][x_pos] + 1 
            search_route(new_y, new_x)
            visited[new_y][new_x] = False
            maze[new_y][new_x] = 1 

search_route(0,0)
print(min_steps)
