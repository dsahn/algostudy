#include <vector>

template<typename T> 
class VectorStack
{
public:
    VectorStack() : _vec(), _offset(-1) {}

    bool is_empty() { return _vec.empty(); }
	int index() { return _offset; }
	// XXX full size를 허용할 것인지?

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
    virtual T peek(int idx) {
        // XXX check if (is_empty()) 
        return _vec.at(idx);
    }

	void print() {
		if (is_empty())
			std::cout << "empty!" << std::endl;
		else {
			for (int i = 0; i <= _offset; i++) {
				std::cout << _vec.at(i) << ",";
			}
			std::cout << "\n";
		}
	}

private:
    std::vector<T> _vec;
    int _offset;
};
