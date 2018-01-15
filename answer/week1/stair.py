"""
# n개의 계단을 아이가 오른다. 한번에 1계단 오르기도 하고, 2계단이나 3계단씩 오르기도 한다.
# 계단을 오르는 데 몇 가지 방법이 있는지 계산하는 메서드를 구현하라.

top-down 접근법을 적용할 수 있는 문제.
간단한 구현 :
"""


def count_ways(n):
    if n < 0 :
        return 0
    elif n == 0 :
        return 1
    else :
        return count_ways(n - 1) + count_ways(n - 2) + count_ways(n - 3)


"""
그런데, 피보나치의 수열처럼 이 알고리즘의 수행시간은 지수적으로 증가(O(3^N))
불필요하게 중복 호출되는 경우를 제거하자 --> dynamic programming 으로 해결하기.
정답 코드는 java 기반으로 작성되어 일단 python 스럽게 바꿔보았습니다.
파이선 syntax 가 생소하여 비효율적으로 작성했을 수 있으니 추가 커밋이나 코멘트 바랍니다.
"""


def count_ways_dp(n, counted):
    if n < 0 :
        return 0
    elif n == 0 :
        return 1
    elif counted[n] > -1 :
        return counted[n]
    else :
        counted[n] = count_ways_dp(n - 1, counted) + count_ways_dp(n - 2, counted) + count_ways_dp(n - 3, counted)
        return counted[n]


def count_ways_dp_wrap(n) :
    return count_ways_dp(n, [-1 for _ in range(n + 1)])


print(count_ways(4))
print(count_ways_dp_wrap(4))

# # range usage
# print([0 for _ in range(4)])
# print(list(range(4)))

