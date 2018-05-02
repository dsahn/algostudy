/* 
 * 회문 검사 알고리즘 
 * 재귀로 풀어보자.  
 * is_palindrome = compare(first,last) && ret_bool 의 형태
 * 재귀 못들어 가는 지점일때, 홀수 짝수 잘 판별해주기!
 * ?? : last 까지 어떻게 접근할 것이며, 또 last의 이전거는 어떻게
 *      표현할것인가?
 *      배열을 array 처럼 표현하여 접근하는것은 문제의 의도가 아닐거같은데..
 *      리스트의 전체 길이는 알 수 있으니까, 중간에 접근하는건 가능할 듯.
 *      중간부터 스택과 next를 이용하여 표현해보자
 * fail1: 
 * - _is_palindrome 내부에 int_list.size() 호출..
 *      size를 얻을 다른 인자를 넣어주자
 * - ->,. operator 혼동
 * fail2:
 * - segfault 발생.
 *   - 하나 있는 경우를 테스트 케이스에 넣어서 그런듯.
 *
 * */

#include <iostream>
#include <string>
#include <algorithm>
#include "linked_list.h"

bool _is_palindrome(SinglePtrNode<int>* prev, int pos, int size, 
        SinglePtrNode<int>* next) 
{
    if (pos >= size / 2) {
        if (next != nullptr)
            *next = *prev->next;
        return true;
    }
    else {
        SinglePtrNode<int> outer(0);
        bool before_val = _is_palindrome(prev->next, pos+1, size, &outer);
        if (pos != 0)
            *next = *outer.next;
        return before_val && (outer.elem == prev->elem); 
    }
}

bool is_palindrome(SingleLinkedList<int> int_list) {
    return _is_palindrome(int_list.head(), 0, int_list.size(), nullptr);
}

using namespace std;

int main() {
	SingleLinkedList<int> must_true;
	SingleLinkedList<int> must_false;
	SingleLinkedList<int> single;

    must_true.push_back(1);
    must_true.push_back(2);
    must_true.push_back(3); 
    must_true.push_back(2); 
    must_true.push_back(1); 

    must_false.push_back(3); 
    must_false.push_back(2); 
    must_false.push_back(2); 

    single.push_back(2); 

    bool val;
    val = is_palindrome(must_true);
    cout << val << endl;
    val = is_palindrome(must_false);
    cout << val << endl;
    val = is_palindrome(single);
    cout << val << endl;

	return 0;
}

