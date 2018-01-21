/* boj에서 시간 초과로 패스되지 않아 cpp로 작성.
 * 주석은 boj_1697.py 참고할 것
 * */
#include <iostream>
#include <vector>

using namespace std;

int solve(int n, int k)
{
    vector<int> dp(max(n,k)*2, 1000);
    vector<int> visited(max(n,k)*2, -1);
    dp[n] = 0;
    visited[n] = 1;

    for(int i = 0; i < abs(n - k); i++) {
        for(int j = 0; j < dp.size(); j++) {
            if(visited[j] == 1) {
                dp[j - 1] = min(dp[j - 1], i + 1);
                if(visited[j - 1] <= 0)
                    visited[j - 1] = 0;
                if(j + 1 < dp.size()) {
                    dp[j + 1] = min(dp[j + 1], i + 1);
                    if(visited[j + 1] <= 0)
                        visited[j + 1] = 0;
                }
                if (j * 2 < dp.size()) {
                    dp[j * 2] = min(dp[j * 2], i + 1);
                    if (visited[j * 2] <= 0)
                        visited[j * 2] = 0;
                }
            }
        }
        for (int &l : visited) {
            if(l == 0)
                l = 1;
        }

        if (dp[k] != 1000)
            break;
    }
    return dp[k];
}

int main(void) {
    int n, k;
    cin >> n >> k;
    cout << solve(n, k) << endl;
    return 0;
}
