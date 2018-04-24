/* 2. 문자열 두 개를 입력받아 하나가 다른 하나의 순열인지 확인하는 문제
 * */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_permutation(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;

    vector<int> countarray1(256, 0);
    /* vector<int> countarray2(256, 0); */

    for (char i : s1)
    { countarray1[i]++; }
    /* FIXME 더한 만큼 빼주는 방식으로 풀면 배열을 하나만 사용할 수 있다. */
    /* for (char i : s2)
    { countarray2[i]++; }
    
    return countarray1 == countarray2; */
    for(unsigned int i = 0; i < s1.length(); i++) {
        char c = s2[i];
        if (--countarray1[c] < 0)
            return false;
    }
    return true;

}

int main() {
    string s1 = "abcde";
    string s2 = "cdeab";

    bool val = is_permutation(s1, s2);
    cout << "res: " << val << endl;

    string s3 = "dod";
    string s4 = "god";

    val = is_permutation(s3, s4);
    cout << "res: " << val << endl;
    return 0;
}
