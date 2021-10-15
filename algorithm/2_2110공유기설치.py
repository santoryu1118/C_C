# 답지 한번 참조
import sys
sys.stdin = open('input.txt')
input = sys.stdin.readline

N, C = map(int, input().split())
ward = [int(input()) for _ in range(N)]
ward.sort()

start = 1
end = ward[-1] - ward[0]
max_dist = 0

while start <= end:
    # 끝집과 끝집 사이 거리가 10이고 공유기 4개 필요하면, 최대 가능 길이가 10//4 = 2 임
    max_possible_dist = (start + end) // C
    # 맨 앞집은 와드
    cnt = 1
    current_pos = 0

    # 한집씩 돌면서 설치가능하면 와드박기
    for i in range(1, N):
        if (ward[i] - ward[current_pos] >= max_possible_dist):
            cnt +=1
            current_pos = i

    # 더 많이 설치 됬다는 얘기니까 거리가 좀 더 길어져도 됨
    if cnt >= C:
        max_dist = max(max_dist, max_possible_dist)
        start = max_possible_dist + 1

    # 덜 설치 됬으니까 거리가 짧아져야됨
    else:
        end = max_possible_dist -1

print(max_dist)
