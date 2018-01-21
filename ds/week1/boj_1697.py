"""
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다.
수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다.
순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

입력 : 첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다.
출력 : 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
"""


"""
재귀적인 방법으로 풀어보려 했으나, 잘 되지 않아(식이 잘 세워지지 않아) 
그냥 2차원 루프를 돌리는게 좀 더 낫겠다 싶어서 짜봄.
재귀적 방법도 여유가 되면 짜 볼 것.
# sd : shortest distance array
def solve_internal(n, k, cur, time, wasted):
    if wasted[cur] >= 0:
        wasted[cur] = min(wasted[cur], time)
        return # 있으면 안될거 같은데?

    wasted[cur] = time

    print("cur:" + str(cur) + " k:" + str(k) + " time:" + str(time))
    print(wasted[0:20])

    # answer
    if cur == k:
        return
    # too big index
    if cur > 2 * k:
        return

    if cur - 1 >= 0:
        solve_internal(n, k, cur - 1, time + 1, wasted)
    if cur + 1 <= 100000:
        solve_internal(n, k, cur + 1, time + 1, wasted)
    if cur * 2 <= 100000:
        solve_internal(n, k, cur * 2, time + 1, wasted)
    return


def solve(n, k, sd):
    solve_internal(n, k, n, 0, sd)
    return sd[k]


line = input()
n = int(line.split(' ')[0])
k = int(line.split(' ')[1])

print(solve(n, k, [-1 for _ in range(100001)]))
"""


import sys


def solve_internal(n, k):
    # 둘 중 큰 숫자(동생이 앞, 뒤중 어디에 있을지 모르니까)를 택하여 2배(벗어날 수 있는 범위가 2배까지이므로)를
    # dp의 큰 바운더리로 삼아보자
    # dp는 cost time 값이 저장된다
    dp = [sys.maxsize for _ in range(int(max(n, k) * 1.5))]

    dp[n] = 0 # 시작점 초기화
    visited = [-1 for _ in dp] # visited list : 단순히 dp의 maxsize가 아닌 값으로는 중복 계산하는 경우가 생겨서,
                 # 방문한 경로에 대해서만 -1, +1, *2 의 계산을 해준다
    visited[n] = 1
    # i : 걸리는 시간값
    # n - k 의 절대값 : 수민이가 이동하여 찾는 시간이 아무리 오래 걸려도 n - k (1칸씩 이동하여 동생을 찾는 경로)
    # 보다는 빠르기 때문에 이 값을 루프의 회수로 삼고 돌린다
    for i in range(0, int(abs(n - k)/2)):
        for j in range(len(dp)):
            # print("i: " + str(i) + ", j: " + str(j))
            if visited[j] == 1:
                dp[j - 1] = min(dp[j - 1], i + 1)
                if visited[j - 1] <= 0:
                    visited[j - 1] = 0
                # prohibit out of range
                if j + 1 < len(dp):
                    dp[j + 1] = min(dp[j + 1], i + 1)
                    if visited[j + 1] <= 0:
                        visited[j + 1] = 0
                # prohibit out of range
                if j * 2 < len(dp):
                    dp[j * 2] = min(dp[j * 2], i + 1)
                    if visited[j * 2] <= 0:
                        visited[j * 2] = 0
        # for idx, s in enumerate(dp):
        #     print(idx, s, end="), ")
        # print("")
        # for idx, s in enumerate(visited):
        #     print(idx, s, end="), ")
        # print("")
        for l in range(len(visited)):
            if visited[l] == 0:
                # print("visited:", l, end=", ")
                visited[l] = 1
        # print("")
    return dp[k]


def solve(n, k):
    return solve_internal(n, k)


line = input()
n_in = int(line.split(' ')[0])
k_in = int(line.split(' ')[1])
print(solve(n_in, k_in))
