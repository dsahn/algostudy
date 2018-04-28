/* 
2. �ڿ��� k ��° ���� ã�� ����
���� �˰��� å���� �о��� ������ ���� ����.
K��°�� ������Ų ��������� �ϳ��� 0��°�� ������ �ϳ��� 
���� ������Ű��.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include "linked_list.h"

using namespace std;

void kth_elem(SingleLinkedList<int> int_list, int k) {
	// k�� list�� ��ü ������� ū �� üũ�ϱ�
	// ù��°�� k��ŭ ������Ű��
	auto front = int_list.head();
	for (int i = 0; i < k; i++) {
		if (front->next == nullptr) {
			cerr << "k is bigger than list size" << endl;
			return;
		}
		front = front->next;
	}
	// �ι�°�� head��
	auto back = int_list.head();

	// ���� ������Ű��
	while (front->next != nullptr) {
		front = front->next;
		back = back->next;
	}
	cout << "kth elem : " << back->elem << endl;
}

int main() {
	SingleLinkedList<int> int_list;
	int_list.push_back(1);
	int_list.push_back(2);
	int_list.push_back(3);
	int_list.push_back(4);
	int_list.push_back(5);

	kth_elem(int_list, 2);

	return 0;
}