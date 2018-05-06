/* push, pop 뿐만 아니라 최소값을 반환하는 min 연산을 갖춘 스택을 구현하라
 * O(1) 시간에 해결되어야 한다.
 *
 * 처음엔 단순히 min 값을 하나 들고있게 해주는것을 생각하였으나, pop 할 때
 * 문제가 발생한다. 최소값이 중간에 있고, 이걸 빼었을때 문제가 생김
 *
 * 결국 각각이 그 상태의 min값을 들고 있도록 구성하면 될 것.
 *
 * int 스택이라 가정하고 해보자
 * */

#include <iostream>
#include <string>
#include "stack.h"

template<typename T>
class MinStack
{
public:
    struct node {
        T elem;
        T min;
    };

    T min() {
        return _internal_stack.peek().min;
    }

    void push(T data) {
        T min_val;
        if (!_internal_stack.is_empty())
            min_val = (data < min()) ? data : min();
        else
            min_val = data;
        _internal_stack.push({data, min_val});
    }

    T pop() {
        return _internal_stack.pop().elem;
    }

private:
    VectorStack<struct node> _internal_stack;
};

using namespace std;

int main() {
    MinStack<int> int_min_stack;
    int_min_stack.push(3);
    int_min_stack.push(2);
    int_min_stack.push(1);
    int_min_stack.push(3);
    int_min_stack.push(2);
    cout << int_min_stack.min() << endl;

    int_min_stack.pop();
    int_min_stack.pop();
    int_min_stack.pop();
    cout << int_min_stack.min() << endl;
    return 0;
}
