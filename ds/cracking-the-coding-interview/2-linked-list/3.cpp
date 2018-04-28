/*
3. �߰��� �ִ� ��� �ϳ� �����ϴ� ����
�߰� �� ��忡�� �����ϴ� ��Ȳ�϶� �����ϱ�
elem, next���� �ƿ� copy �ع����� 
�� ���� ���(next�� ����) ��������.
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