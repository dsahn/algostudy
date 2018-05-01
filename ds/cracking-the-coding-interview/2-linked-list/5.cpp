/* 2.5. 링크드 리스트를 두개의 수로 표현. 합을 구하기.
 * 역순으로 했을때, 정순으로 했을때 각각 구하기 
 * 역순 문제는 풀기 쉽다. 각자리 elem 의 합을 result에 반영하고,
 * 만약 필요하다면(받아올림 발생) 추가노드를 만들어주면 된다.
 * 정순일 경우가 까다롭다. 받아올림이 발생한다던지, 각자리 수가 다를 때
 * 어떻게 다룰 건지가 중요함. 역순만 풀어보자.
 * 
 * 자리수가 다른 게 문제가 되는데, 자리수를 맞춰주면 어떤가?
 *   가장 긴 노드에 맞춰서, 맞춰주자.
 * 계산을 뒤에서부터 해줘야한다? 
 *   이건 재귀로 풀어보자.
 * 가장 긴 노드에 맞춰도 자리수가 모자란 경우 : 99 + 1 --> 한자리 추가
 *   그냥 한자리를 더 추가하자
 * */

#include <iostream>
#include <string>
#include <algorithm>
#include "linked_list.h"

using namespace std;

unsigned _sum(SinglePtrNode<int> *f,
        SinglePtrNode<int> *s,
        SinglePtrNode<int> *r) {
    if (f->next != nullptr) {
        int carry = _sum(f->next, s->next, r->next);
        r->elem = (f->elem + s->elem + carry) % 10;
        return (f->elem + s->elem + carry) / 10;
    }
    else {
        r->elem = (f->elem + s->elem) % 10;
        return (f->elem + s->elem) / 10;
    }
}

void sum(SingleLinkedList<int> f,
        SingleLinkedList<int> s,
        SingleLinkedList<int> *r) {
    // get length and
    // align max(f,s)+1
    int max_len = std::max(f.size(), s.size()) + 1;

    while(f.size() != max_len)
        f.push_front(0);
    while(s.size() != max_len)
        s.push_front(0);
    while(r->size() != max_len)
        r->push_front(0);

    // sum recursively
    _sum(f.head(), s.head(), r->head());
}

int main() {
	SingleLinkedList<int> first;
	SingleLinkedList<int> second;
	SingleLinkedList<int> result;

    first.push_back(9);
    first.push_back(9);
    first.push_back(8); 
    second.push_back(3); 
	first.print();
	second.print();

    sum(first, second, &result);

    cout << "result\n";
	result.print();

	return 0;
}
