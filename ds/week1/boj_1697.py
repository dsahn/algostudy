"""
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다.
수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다.
순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

입력 : 첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다.
출력 : 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
"""


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
