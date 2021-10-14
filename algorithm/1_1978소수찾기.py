import sys
input = sys.stdin.readline

# 골드 바흐의 추측 : N = 15이면 N/2 ->15/2 = 7 이 수 이하로 나뉘어 지는 소수가 존재한다

# 어려웠던 점
# 1. 어떤 방식으로 시간 최적화 할지. 소수 아닌 애들을 소수 list 에서 곱하면서 false 넣어주고 그 소수로 나뉘어지면 멈추면 됨
#   예: 12를 6*2, 4*3 둘다 체크하게 되니, 4에서 4는 2로 나뉘어 지므로 4*2 만하고 멈추기. 그리고 나중에 6이 *2 해서 12 넣어주기. 마찬가지로 18 도 9*2 가 넣어주기 6*3이 아니라
# 2. 0 하고 1은 소수가 아니다...... -,-^

howmany = int(input())
given_numbers = list(map(int, input().split()))

N = 1000
num_list = [True] * (N +1)
num_list[0] = False
num_list[1] = False
prime_list = []

# 1부터 1000까지 의 수 중에서 2 가 true이면 소수란 뜻이니까 list 에서 2의 배수 싹다 false 로 바꿔줌
def get_prime():
    for i in range(2, N + 1):

        # true == 소수
        if num_list[i] == True:
            prime_list.append(i)
            for prime in prime_list:
                make = i*prime
                if make <= N:    # 인덱스 에러 때매
                    num_list[make] = False

        # false == 소수 아닐때
        else:
            for prime in prime_list:
                make = i*prime
                if make <= N:
                    num_list[make] = False
                    if i % prime == 0:  # 어려웠던 점 1번
                        break

get_prime()

cnt = 0
for i in given_numbers:
    if num_list[i] == True:
        cnt +=1
print(cnt)
