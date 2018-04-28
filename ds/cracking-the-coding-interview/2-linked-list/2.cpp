/* 
2. 뒤에서 k 번째 원소 찾기 문제
전에 알고리즘 책에서 읽었던 문제랑 같은 문제.
K번째로 전진시킨 노드포인터 하나와 0번째의 포인터 하나를 
같이 전진시키자.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include "linked_list.h"

using namespace std;

void kth_elem(SingleLinkedList<int> int_list, int k) {
	// k가 list의 전체 사이즈보다 큰 지 체크하기
	// 첫번째를 k만큼 전진시키기
	auto front = int_list.head();
	for (int i = 0; i < k; i++) {
		if (front->next == nullptr) {
			cerr << "k is bigger than list size" << endl;
			return;
		}
		front = front->next;
	}
	// 두번째는 head임
	auto back = int_list.head();

	// 같이 전진시키기
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