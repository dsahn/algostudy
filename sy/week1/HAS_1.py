import sys
global limit_k

def count_ways (x, k, counted) :
    print(x, k)
    global limit_k
    if x < 0 and k >= limit_k :
        return sys.maxint
    if x == k :
        return 0
    elif (x+1) == k :
        return 1
    elif (x*2) == k :
        return 1
    elif x > k :
        return x - k
    elif counted[x][k] > -1 :
        return counted[x][k]
    else :
        if k % 2 == 0 and k != 0 :
            if k < limit_k :
                counted[x][k] = min(count_ways(x, k-1, counted), \
                                    count_ways(x, k/2, counted)) + 1
        else :
            if k < limit_k :
                counted[x][k] = min(count_ways(x, k-1, counted), \
                                    count_ways(x, k+1, counted)) + 1
            else :
                counted[x][k] = count_ways(x, k-1, counted) + 1
        return counted[x][k]

def count_ways_wrap (x, k) :
    global limit_k
    limit_k = k*2
    return count_ways(x, k, [[-1 for col in range(max(list)*8+1)] for row in range(max(list)*8+1)])

list = map(int, raw_input().split())
print(count_ways_wrap(list[0], list[1]))
