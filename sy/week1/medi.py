def pick (w, h) :
    ways = 0
    if w < 0 or h < 0:
        return 0
    elif w == 0 :
        return 1
    else :
       return pick(w-1, h+1) + pick(w, h-1)

input_list = []
while 1:
    input_num = int(input())
    if input_num == 0:
        break
    input_list.append(input_num)

for input_num in input_list:
    print(pick(input_num, 0))