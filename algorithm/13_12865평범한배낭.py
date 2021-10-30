import sys
sys.stdin = open('input.txt')
input = sys.stdin.readline

num_things, max_weight = map(int, input().split())

bag  = {0:0}

for _ in range(num_things):
    weight, value =  map(int, input().split())
    a = {}

    for w, v in bag.items():
        new_weight = weight + w
        new_value = value + v
        if new_weight <= max_weight and new_value > bag.get(new_weight,0):
            a[new_weight] = new_value   
    bag.update(a)

print(max(bag.values()))
        


