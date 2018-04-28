/* 비정렬 리스트에서 중복 문자를 제거하는 코드? 
 * 1. 비정렬 리스트 자료구조 만들기
 * 2. 테스트 케이스 만들기
 * 3. 아이디어 : 해시테이블이나 비트배열 만들기
 *   소팅하기..는 복잡할듯
 *   셀렉션 소트처럼 n^2의 복잡도로 탐색하기
 *
 *   q1: ascii 인가 다른 캐릭터셋인가?
 *
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>
#include "linked_list.h"

using namespace std;
void remove_dup(SingleLinkedList<char> char_list){
    bitset<256> ascii_counted;
    for (auto cur = char_list.head(); cur != nullptr; cur = cur->next) 
    {
        if(ascii_counted[cur->elem] == true) {
			auto next = cur->next;
            char_list.remove(cur);
			if (next == nullptr)
				return;
			cur = next;
        }
        ascii_counted[cur->elem] = true;
    }
}

int main() {
    SingleLinkedList<char> char_list;
    char_list.push_back('a');
    char_list.push_back('b');
    char_list.push_back('c');
    char_list.push_back('c');

    remove_dup(char_list);

    char_list.print();
    return 0;
}

