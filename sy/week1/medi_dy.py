def count_ways (w, h, counted) :
    if w == 0 :
        return 1
    elif w < 0 or h < 0 :
        return 0
    elif counted[w][h] > -1 :
        return counted[w][h]
    else :
        counted[w][h] = count_ways(w-1, h+1, counted) + count_ways(w, h-1, counted)
        return counted[w][h]

def count_ways_wrap (n) :
    return count_ways(n, 0, [[-1 for col in range(n+1)] for row in range(n+1)])

input_list=[]
while 1:
    input_num = int(input())
    if input_num == 0 :
        break
    input_list.append(input_num)
    
for input_num in input_list :
    print(count_ways_wrap(input_num))
