/* 두 개의 스택을 사용하여 큐를 구현하는 MyQueue 클래스를 작성하라
 * _s1 에서 push, _s2에서 pop을 수행하도록 구성하면될듯
 *
 * */

#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

template<typename T>
class MyQueue {
public:
    MyQueue() : _s1(), _s2() {}
    void push_back(T data) {
        if (!_s2.is_empty()) {
            move_all(_s2, _s1);
        }
        _s1.push(data);
    }
    T pop_front() {
        if (!_s1.is_empty()) {
            move_all(_s1, _s2);
        }
        return _s2.pop();
    }
    void print() {
        if (_s1.is_empty())
            move_all(_s2, _s1);
        _s1.print();
    }
private:
    VectorStack<T> _s1;
    VectorStack<T> _s2;
    void move_all(VectorStack<T> &f, VectorStack<T> &t) {
        T elem;
        while(!f.is_empty()) {
            elem = f.pop();
            t.push(elem);
        }
    }
};

int main() {
    MyQueue<int> q;
    int i;

    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    q.push_back(4);
    q.push_back(5);
    i = q.pop_front();
    i = q.pop_front();
    i = q.pop_front();
    q.push_back(6);

    q.print();

    return 0;
}
