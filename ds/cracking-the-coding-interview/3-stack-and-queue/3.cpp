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
 *   */
#include <iostream>
#include <string>
#include "stack.h"

template<typename T>
class SetOfStacks {
    SetOfStacks(int height) : height_(height) {}
private:
    int _width;  //내부적으로 유지되는 스택의 개수
    int _height; //접시 더미의 최대 높이
    std::vector<VectorStack> _stacks;
};

int main() {
    SetOfStacks<int> stacks;

    stacks.push(3);
    stacks.push(2);
    stacks.push(1);
    stacks.push(3);
    stacks.push(2);
    cout << stacks.min() << endl;

    return 0;
}
