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
 * */

#include <iostream>
#include <string>
#include <algorithm>
#include "linked_list.h"

using namespace std;

int main() {
	SingleLinkedList<int> must_true;
	SingleLinkedList<int> must_false;

    must_true.push_back(1);
    must_true.push_back(2);
    must_true.push_back(3); 
    must_true.push_back(4); 
    must_true.push_back(5); 

    must_false.push_back(3); 

    is_palindrome(must_true);
    is_palindrome(must_false);

	return 0;
}

