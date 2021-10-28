import sys
import heapq

sys.stdin = open('input.txt')
input = sys.stdin.readline

N = int(input())
heap = []

# for _ in range(N):
#     heapq.heappush(heap, int(input()))

# sum = 0
# while len(heap) != 1:
#     n1 = heapq.heappop(heap)
#     n2 = heapq.heappop(heap)
#     sum += (n1+n2)
#     heapq.heappush(heap, n1+n2)

# print(sum)

# 직접 힙 정렬을 해보자 
# 만들어야 되는 함수 : swap, heap_insert, heap_popmin
# 최소 힙은 자식 노드 값이 자기보다 크거나 같아야 한다

def swap(a1, a2):
    heap[a1], heap[a2] = heap[a2], heap[a1]

def heap_insert(a1):
    heap.append(a1)
    new_node = len(heap) -1

    while new_node >0:
        parent_node = (new_node-1) // 2

        # 새로 추가한 node가 더 낮은 값이어서 swap 해주어야 할 때
        if heap[new_node] < heap[parent_node]:
            swap(new_node, parent_node)
            new_node = parent_node
        else:
            return

def heap_popmin():

    # 대가리랑 맨 뒤에 애 swap하면 맨 뒷자리에 min값이 들어가니까 그거 바로 빼주면 되고
    swap(0, len(heap)-1)
    return_val = heap.pop()

    # 그다음에 0번 index에 최소 value넣기 위한 작업
    start_idx = 0
    while True:
        left_idx = start_idx *2 + 1
        right_idx = start_idx *2 + 2
        # 인덱스 맞을때랑 오른쪽이 왼쪽보다 더 작을 때랑 부모보다도 작을때
        if right_idx < len(heap) and heap[right_idx] < heap[left_idx] and heap[start_idx] > heap[right_idx]:
            swap(start_idx, right_idx)
            start_idx = right_idx
        # elif 이니까 위에 중 하나라도 안됬다는 소리임 고로 heap[left_idx] < heap[right_idx] 이건 해줄 필요없음
        elif left_idx < len(heap) and heap[start_idx] > heap[left_idx]:
            swap(start_idx, left_idx)
            start_idx = left_idx

        else:
            return return_val
            
for _ in range(N):
    heap_insert(int(input()))

sum = 0
while len(heap) != 1:
    n1 = heap_popmin()
    n2 = heap_popmin()
    sum += (n1+n2)
    heapq.heappush(heap, n1+n2)

print(sum)






