/* 1. 문자열에 포함된 문자들이 전부 유일한지를 검사하는 알고리즘을 구현? 
 * 다른 자료구조를 사용할 수 없는 상황이라면 어찌?
 * ==> 일단 소팅을 하면 해결되겠으나 시간복잡도가 커진다
 * ==> 26개의 배열을 선언하여 각 자리에 알파벳의 존재여부 알려주기 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool is_unique1(string input) {
    sort(input.begin(), input.end());
    for (auto i = input.begin(); i != input.end(); i++) {
        if (i + 1 == input.end())
            return true;
        if (*i == *(i + 1))
            return false;
    }
    return true;
}

int main() {
    string s1 = "abcde";
    string s2 = "abcdd";

    bool val = is_unique1(s1);
    cout << val << endl;
    return 0;
}

