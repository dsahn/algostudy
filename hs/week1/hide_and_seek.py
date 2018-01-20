'''
  @ file name : hide_and_seek.py
  @ brief     : homework
  @ author    :
  @ desc      : hide and seek.

                x can be (0 <= N <= 100,000)
                y can be (0 <= K <= 100,000)

                x can walk(x+1 or x-1) or teleport(x*2)
                
                one move(walk or teleport) will take 1 seconds...

                calculate the fastest time for x to find y.
                
  @ Sample     : input[5 17] output[4]
'''
def min (x, y):
    if (x > y):
        return y
    return x

def seek(x, target):
    if (x > target):
        return seek(x-1, target)+1
    if (x == target):
        return 1

#    return min(seek(x+1, target), seek(x*2, target))+1
    val1 = seek(x+1, target)
    val2 = seek(x*2, target)
    print "x : ", x
    print "  seek(x+1, target)",  val1
    print "  seek(x*2, target)",  val2
    return min(val1, val2)
     
   
print "answer : ", seek(5, 17)
