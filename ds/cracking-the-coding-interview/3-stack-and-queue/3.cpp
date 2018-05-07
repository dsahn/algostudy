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
 *
 * fail1 : 
 *      list initializer는 순서에 신경써야 워닝이 안난다.. 새로 안사실..
 *      _stacks 가 비어있었다. 생성자에 하나 push_back 하도록.
 * fail2 :
 *      index와 size 간의 차이를 잘 파악한 후 클래스를 구성하자.
 *   */
#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

template<typename T>
class SetOfStacks {
public:
    SetOfStacks(int height) : _width(0), _height(height), _stacks() {
        _stacks.push_back(VectorStack<T>());
    }

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
		if (_stacks.at(_width).index() >= _height - 1) {
			++_width;
            // if _stacks[i] is not created, created it.
            if (_stacks.size() <= _width)
                _stacks.push_back(VectorStack<T>());
        }
		// insert data
		_stacks.at(_width).push(data);
		return;
	}
	// void pop_at(int idx) {}
	void print() {
		for (unsigned i = 0; i <= _width; i++) {
			cout << "Stack " << i << endl;
			_stacks.at(i).print();
            cout << endl;
		}
	}
private:
    unsigned _width;  //내부적으로 유지되는 스택의 개수
    int _height; //접시 더미의 최대 높이
    std::vector<VectorStack<T>> _stacks;
};

int main() {
    SetOfStacks<int> stacks(3);

    stacks.push(3);
    stacks.push(2);
    stacks.push(1);
    stacks.push(3);
    stacks.push(2);
    stacks.push(2);
    stacks.push(2);
	stacks.print();

    cout << "=== before pop ===" << endl;

    stacks.pop();
    stacks.pop();
	stacks.print();

    return 0;
}
