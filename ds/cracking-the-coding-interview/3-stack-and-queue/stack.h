#include <vector>

template<typename T> 
class VectorStack
{
public:
    VectorStack() : _vec(), _offset(-1) {}

    bool is_empty() { return _vec.empty(); } 
    virtual void push(T data) {
        _vec.push_back(data);
        ++_offset;
    } 
    virtual T pop() {
        // XXX check if (is_empty()) 
        --_offset;
        T data = _vec.back();
        _vec.pop_back();
        return data;
    }
    virtual T peek() {
        // XXX check if (is_empty()) 
        return _vec.at(_offset);
    }

private:
    std::vector<T> _vec;
    int _offset;
};
