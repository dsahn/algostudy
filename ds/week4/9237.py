
"""
이장님 초대
https://www.acmicpc.net/problem/9237
"""


n = int(input())
assert n >= 1 and n <=100000
li = list(map(int, input().split(' ')[0:n]))

li.sort(reverse=True)

for i, el in enumerate(li):
    li[i] = el + 2 + i

print(max(li))

# 이걸 해보고 싶은데 안되네..
#def map_func(i, el):
    #return int(el) + 1 + i
#answer_li = list(map(lambda (i, el): {int(el) + 1 + i}, enumerate(li)))
#answer_li = list(map(map_func, list(enumerate(li))))
