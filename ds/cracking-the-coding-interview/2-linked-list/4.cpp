/* 
 * 4. x 값을 갖는 노드 기준으로 리스트를 나누는 코드 작성
 *  x 보다 작은 값을 갖는 노드가 x와 같거나 큰 노드보다 앞쪽으로 오도록 한다
 * 전략 : x 보다 작은놈들을 마주치면서 넘어간다.
 * 그러다가 큰 놈이 나오면 head에 insert 하기
 * XXX 잘 동작하나 앞으로 옮긴 놈들이 찍히지 않는다. 파라미터를 int_list
 * 객체로 받아와서 그렇다. 레퍼런스로 받아오도록 해야겠다...
 * 코딩 컨벤션같은데서 통상적으로 레퍼런스는 in ref만 쓰던지 네이밍에
 * out이라고 명시하는게 일반적이지만 알고리즘의 편의를 위해서 일단 이렇게함
 * */

#include <iostream>
#include <string>
#include <algorithm>
#include "linked_list.h"

using namespace std;

// int_list : in/out
void order_by_pivot(SingleLinkedList<int>& int_list, int pivot) {
    // bool move_over = false;
    int i = 0;

    // move_over 가 꺼져있다면 
        // 작은 놈이면 넘어가자
        // 큰 놈을 만나면 넘기는 상태로 전환(bool move_over) : 안해도될듯
    auto cur = int_list.head();
    for (; i < int_list.size(); i++) {
        if (cur->elem > pivot) {
            // move_over = true;
            break;
        }
        cur = cur->next;
    }

    auto prev = cur;
    cur = cur->next;
    ++i;
    // move_over가 켜져있다면 : 이어서 하는 동작으로 바꾸자
        // 작은 놈이면 앞으로, 큰 놈이면 그대로 두기
    for (; i < int_list.size(); i++) {
        if (cur->elem < pivot) {
            // int_list.move_first(cur);
            // 직접 remove 하는게 search 하지 않아 더 빠를듯
            prev->next = cur->next ? cur->next : NULL;
            cur->next = int_list.head();
            int_list.set_head(cur);
            // XXX 고친 부분
            // cur 되돌리기. prev로 돌리면 된다.
            cur = prev;
        }
        prev = cur;
        cur = cur->next ? cur->next: NULL;
    }
}

int main() {
	SingleLinkedList<int> int_list;

	int_list.push_back(3);
	int_list.push_back(2);
	int_list.push_back(1);
	int_list.push_back(11);
	int_list.push_back(5);
	int_list.push_back(7);
	int_list.push_back(1);
	int_list.push_back(3);
	int_list.push_back(9);
	int_list.push_back(3);
	int_list.push_back(4);
	int_list.push_back(10);
	int_list.push_back(3);

    cout << "before\n";
	int_list.print();
    order_by_pivot(int_list, 5);

    cout << "after\n";
	int_list.print();

	return 0;
}
