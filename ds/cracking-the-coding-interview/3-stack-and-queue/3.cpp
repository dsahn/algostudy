/* 접시 무더기 문제. SetOfStacks 구현하기
 * - 특정 수준 이상 높아지면 새 무더기 만들 것
 * - 연관문제 : 특정한 하위 스택에 대해서 pop 을 수행하는 pop_at 함수
 *   구현하기
 * 
 * 연관문제가 고민된다. 중간에 있는걸 빼면 그다음 push/pop 은 어디서부터
 * 해야하는가?
 * - 중간걸 뺐으니 바로 그자리를 채우는건 이상하다
 * - 시프팅 시키던지? 아니면 그대로 놔두고 push/pop은 마지막거에서 이어서
 *   하던지.
 * - 후자로 일단 구현해보자.
 *
 * vs에서 디버깅이 잘 안되어 일단 리눅스로 가자
 *   */
#include <iostream>
#include <string>
#include "stack.h"

template<typename T>
class SetOfStacks {
public:
    SetOfStacks(int height) : _height(height), _width(0), _stacks() {}
	T pop() {
		// if empty, decrease width
		// pop_at으로 다 소진되었을 수도 있으니까 loop 돌리자
		while (_stacks.at(_width).is_empty()) 			
			--_width;
		// return data
		return _stacks.at(_width).pop();
	}
	void push(T data) {
		// if full, increase width
		if (_stacks.at(_width).index() >= _height)
			++_width;
		// insert data
		_stacks.at(_width).push(data);
		return;
	}
	// void pop_at(int idx) {}
	void print() {
		for (int i = 0; i < _width; i++) {
			cout << "Stack " << i << endl;
			_stacks.at(i).print();
		}
		cout << endl;
	}
private:
    int _width;  //내부적으로 유지되는 스택의 개수
    int _height; //접시 더미의 최대 높이
    std::vector<VectorStack<T>> _stacks;
};

using namespace std;

int main() {
    SetOfStacks<int> stacks(3);

    stacks.push(3);
    stacks.push(2);
    stacks.push(1);
    stacks.push(3);
    stacks.push(2);
    // cout << stacks.min() << endl;
	stacks.print();

    return 0;
}
