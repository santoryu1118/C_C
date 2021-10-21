# merge sort 로 풀어본다
# 싹다 1개짜리 원소로 쪼갠뒤 다시 덧붙이는 형식
import sys
sys.setrecursionlimit(10**9)
sys.stdin = open('input.txt')
input = sys.stdin.readline

N = int(input())
numbers = []
for _ in range(N):
    numbers.append(int(input()))

def mergeSort(left, right):
    if left >= right:
        return
    mid = (left + right) // 2

    mergeSort(left, mid)
    mergeSort(mid +1, right)
    l_idx = left
    r_idx = mid +1
    temp = []

    while l_idx <= mid and r_idx <= right:
        if numbers[l_idx] < numbers[r_idx]:
            temp.append(numbers[l_idx])
            l_idx += 1
        else:
            temp.append(numbers[r_idx])
            r_idx +=1

    while l_idx <= mid:
        temp.append(numbers[l_idx])
        l_idx += 1
    
    while r_idx <= right:
        temp.append(numbers[r_idx])
        r_idx += 1

    for i in range(len(temp)):
        numbers[left + i] = temp[i]

mergeSort(0, N-1)
for num in numbers:
    print(num)


    
