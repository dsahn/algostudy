
def pick (w, h) :
    ways = 0
    if w < 0 or h < 0:
        return 0
    elif w == 0 :
        return 1
    else :
       return pick(w-1, h+1) + pick(w, h-1)
#ways += pick(w, h-1, 2)
#return ways

n = int(input("Enter a number : "))
print(pick(n,0))
