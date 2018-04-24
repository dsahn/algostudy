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
    vector<int> countarray2(256, 0);

    for (char i : s1)
    { countarray1[i]++; }
    for (char i : s2)
    { countarray2[i]++; }
    
    return countarray1 == countarray2;

}

int main() {
    string s1 = "abcde";
    string s2 = "cdeab";

    bool val = is_permutation(s1, s2);
    cout << "res: " << val << endl;

    string s3 = "abcde";
    string s4 = "cdeaa";

    val = is_permutation(s3, s4);
    cout << "res: " << val << endl;
    return 0;
}
