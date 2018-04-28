/*
3. 중간에 있는 노드 하나 삭제하는 문제
중간 그 노드에만 접근하는 상황일때 삭제하기
elem, next값을 아예 copy 해버리고 
그 다음 노드(next에 접근) 삭제하자.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include "linked_list.h"

using namespace std;

void remove_using_this_ptr(SinglePtrNode<int>* nodep) {
	if (nodep == nullptr || nodep->next == nullptr)
		return;

	auto next = nodep->next;
	nodep->elem = next->elem;
	nodep->next = next->next;
	delete next;
}

int main() {
	SingleLinkedList<int> int_list;

	int_list.push_back(1);
	int_list.push_back(2);
	int_list.push_back(3);
	int_list.push_back(4);
	int_list.push_back(5);

	remove_using_this_ptr(int_list.head()->next->next);
	int_list.print();

	return 0;
}