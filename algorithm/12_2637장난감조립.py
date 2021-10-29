import sys
sys.stdin = open('input.txt')
input = sys.stdin.readline

N = int(input())
n_lines = int(input())

components = []
for _ in range(n_lines):
    components.append(list(map(int, input().split())))

# 첫번째 원소 내림차순 그다음에 두번째 원소 내림차순 정렬
components.sort(key=lambda x:(x[0], x[1]), reverse = True)
# big_component = components[-1][0]

stack = [0] * (N+1)
stack[-1] = 1

# 중간 부품을 담는 list. 부품 6이라 해도 6을 만드는데 기본부품이 필요없으면 6이 기본 부품인거다
big_component = []

for i in range(n_lines):
    bigger, smaller, how_many = components[i]
    stack[smaller] += stack[bigger] * how_many
    big_component.append(bigger)
    
big_component = set(big_component)

for i in range(1, N):
    if i not in big_component and stack[i] != 0:
        print(i,stack[i])
