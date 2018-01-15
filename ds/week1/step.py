#  n개의 계단을 아이가 오른다. 한번에 1계단 오르기도 하고, 2계단이나 3계단씩 오르기도 한다.
# 계단을 오르는 데 몇 가지 방법이 있는지 계산하는 메서드를 구현하라.


def steps(remains):
    ways = 0
    if remains < 0:
        return 0
    elif remains == 0:
        # print(str(remains) + '\n')
        return 1
    else:
        # print(str(remains) + ' ')
        ways += steps(remains - 3)
        ways += steps(remains - 2)
        ways += steps(remains - 1)
        return ways


print('ways:' + str(steps(3)))
