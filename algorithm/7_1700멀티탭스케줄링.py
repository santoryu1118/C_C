import sys
sys.stdin = open('input.txt')
input = sys.stdin.readline

N, k = map(int, input().split())
schedule = list(map(int, input().split()))

socket = []
cnt = 0

for i in range(k):
    # 이미 socket에 꽂혀있으면
    if schedule[i] in socket:
        continue

    # 안꽂혀있고 소켓 자리가 비어있으면
    elif len(socket) < N:
        socket.append(schedule[i])
        continue

    # 교체를 해야된다면
    else:
        temp = socket.copy()
        for temp_usage in range(i+1, k) :
            if len(temp) <= 1:
                break
            # socket에 꽂혀있는 것 중, 금방 사용할 것들은 남겨놓고, schedule에서 제일 늦게 사용되는것을 빼는작업
            if schedule[temp_usage] in temp:
                temp.remove(schedule[temp_usage])
    
        # temp[0]로 한 이유는 안쓰게 될 것들이 한개 이상일 수도 있어서
        socket.remove(temp[0])
        socket.append(schedule[i])
        cnt += 1

print(cnt)

        

# print(socket)