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
        --_offset;
        return _vec.pop_back(); 
    }

private:
    std::vector<T> _vec;
    int _offset;
};
