import sys
sys.stdin = open('input.txt')
input = sys.stdin.readline

N = int(input())
numbers = [True for i in range(1000)]
# 같은 수 있는거 빼기
for i in range(1000):
    first = i // 100
    second = (i % 100) // 10
    third = i % 10  
    
    if first == 0 or second == 0 or third == 0:
        numbers[i] = False
    elif first == second or second == third or third == first:
        numbers[i] = False
    

# 스트라이크 : 동일한 자리에 있으면, 볼: 숫자는 같은데 다른 자리에 있으면
for _ in range(N):
    num, strike, ball = map(int, input().split())
    input_first = num // 100
    input_second = (num % 100) // 10
    input_third = num % 10  
    input_list = [input_first, input_second, input_third]

    for j in range(len(numbers)):
        if numbers[j] == False:
            continue

        comp_first = j // 100
        comp_second = (j % 100) // 10
        comp_third = j % 10 
        comp_list = [comp_first, comp_second, comp_third]
        
        temp_strike = 0
        temp_ball = 0

        for i in range(3):
            if comp_list[i] == input_list[i]:
                temp_strike += 1
            elif comp_list[i] in input_list:
                temp_ball += 1
            
        if temp_strike != strike or temp_ball != ball:
           numbers[j] = False

for i in range(len(numbers)):
    if numbers[i]:
        print(i)
# print(sum(numbers))

