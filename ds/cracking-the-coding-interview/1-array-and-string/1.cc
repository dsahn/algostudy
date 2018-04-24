/* 1. 문자열에 포함된 문자들이 전부 유일한지를 검사하는 알고리즘을 구현? 
 * 다른 자료구조를 사용할 수 없는 상황이라면 어찌?
 * ==> 일단 소팅을 하면 해결되겠으나 시간복잡도가 커진다
 * ==> 26개의 배열을 선언하여 각 자리에 알파벳의 존재여부 알려주기 
 * 아스키 값이라고 가정하고 문제 풀기 */

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

inline int bit(char c) { return 1 << c; }

bool is_counted(int *ba, char c) {
    if (*ba | bit(c)) return true;
    *ba |= bit(c);
    return false;
}

/* bit array를 int 값 하나로 하려 했으나 통상 int는 4바이트이므로 32개의
 * 정보만 표현할 수 있다. 256개의 정보를 가지는 ascii는 표현할 수 없다.
 * NOTE 일단 1 bit 씩 가지는 ascii 개수만큼의 array를 만들자.
 * */
bool is_unique2(string input) {
    vector<bool> bitarray(256, false);

    for (auto i = input.begin(); i != input.end(); i++) {
        int index = *i;
        if (bitarray[index] == false)
            bitarray[index] = true;
        else 
            return false;
        /* if (is_counted(&bitarray, *i))
            return false; */
    }
    return true;
}

int main() {
    string s1 = "abcde";
    string s2 = "abcdd";

    bool val = is_unique2(s1);
    cout << val << endl;

    val = is_unique2(s2);
    cout << val << endl;
    return 0;
}

