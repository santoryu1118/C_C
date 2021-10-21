# 퀵 sort 로 풀어본다
# pivot 중심으로 왼쪽의 큰값과 오른쪽의 작은 값을 switch하고 왼쪽부분 recursion, 오른쪽 부분 recursion
import sys
sys.setrecursionlimit(10**9)
sys.stdin = open('input.txt')
input = sys.stdin.readline

N = int(input())
numbers = []
for _ in range(N):
    numbers.append(int(input()))
    
def quicksort(left, right):
    if left >= right:
        return

    l_idx = left
    r_idx = right
    m_idx = (left + right)//2
    pivot = numbers[m_idx]

    print(f'a[{left}] ~ a[{right}]: {numbers[left:right+1]}')

    while (l_idx < m_idx and numbers[l_idx] < pivot):
        l_idx += 1
    while (r_idx > m_idx and numbers[r_idx] > pivot):
        r_idx -= 1

    numbers[l_idx], numbers[r_idx] = numbers[r_idx], numbers[l_idx]
    l_idx +=1
    r_idx -=1

    quicksort(left, r_idx)
    quicksort(l_idx, right)


quicksort(0, N-1)

for num in numbers:
    print(num)
