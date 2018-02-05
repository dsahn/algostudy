#include<stdio.h>
#include <iostream>
#include<deque>
using namespace std;
const int MAX_N = 1e6;
int b[7] = {1, 1, 1, 1, 1, 1, 1};
int n, x, res;
deque<pair<int, int> > dq;
typedef long long ll;
ll tot;

int main() {
    // scanf("%d %d", &n, &x);
    n = 7;
    x = 3;
    tot = 7;
    /*
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        tot += b[i];
    }
    */
    
    int s = 0, tmp;
    for (int i = 0; i<x; i++) {     // 0 ~ 브러시보다 작은 구간
        while (!dq.empty() && dq.back().second>b[i]) dq.pop_back();
        dq.push_back({ i, b[i] });
    }
    tmp = dq.front().second;                // n : board count
    // 뒤에꺼 ~ 쭉
    for (int i = x; i <= n; i++) {              // x: brush width
        while (!dq.empty() && dq.back().second>b[i]) dq.pop_back(); // 탑이 현재높이보다 클때
        dq.push_back({ i, b[i] });
        cout << "b[" << i << "] : " << b[i] << endl;
        if (tmp != dq.front().second) {     // 브러시질을 새로 해줘야 할 때
            cout << "first if : " << tmp << endl;
            res += (i - s - 1) / x + 1;     // res : 롤러질 회수
            tot -= (ll)(i - s)*tmp;     // tot : 치솔질 회수
            s = i;      // s : 이전 브러시질 끝의 idx
            tmp = dq.front().second;        //tmp : 이전 브러시질의 높이
        }
        if (dq.front().first <= i - x) {        // x <= (var)i - dq.front.first : 롤러 와이드만큼 찼을때
            cout << "second if : " << tmp << endl;
            int tp = dq.front().first;
            dq.pop_front();
            if (tmp != dq.front().second) {
                cout << "   second iiif : " << tmp << endl;
                res += (tp - s) / x + 1;
                tot -= (ll)(tp - s + 1)*tmp;
                s = tp + 1;
                tmp = dq.front().second;
            }
        }
    }
    printf("%lld\n%d", tot, res);
    return 0;
}
