#include <string> 

/* 귀찮으니 일단 public.. */
template <typename T> class SinglePtrNode {
public: 
    SinglePtrNode<T>(T data) : elem(data), next(nullptr) {}

    SinglePtrNode<T>* next;
	T elem;
};

template <typename T> class SingleLinkedList { 
public:
    SingleLinkedList<T>() : _head(nullptr), _tail(nullptr) {}

    void push_back(T data) {
        SinglePtrNode<T>* new_node = new SinglePtrNode<T>(data);

        if (_head == nullptr)
            _head = _tail = new_node;
        else {
            _tail->next = new_node;
            _tail = new_node;
        }
    }

    operator const char*() {
        /* 동작이 비효율적이지만 일단 테스트용 */
        std::string ret;

        for (auto cur = _head; cur != nullptr; cur = cur->next) {
            ret += std::to_string(cur->elem);
            ret +=  ", ";
        }
        ret += "\n";

        return ret.c_str();
    }
    
    void print() {
        /* 동작이 비효율적이지만 일단 테스트용 */
        std::string ret;

        for (auto cur = _head; cur != nullptr; cur = cur->next) {
            ret += std::to_string(cur->elem);
            ret +=  ", ";
        }
        ret += "\n";

        std::cout << ret.c_str() << std::endl;
    }

    void remove(SinglePtrNode<T>* dst){
        auto prev = _head;
        for (auto cur = _head; cur != nullptr; cur = cur->next) {
            if(cur == dst) {
                prev->next = cur->next;
                delete cur;
				return;
            }
            prev = cur;
        }
    }

    /* bool find(T data) {
        for (auto cur = _head; cur != nullptr; cur = cur->next) {
            if(cur->data == data)
                return true;
        }
        return false;
    } */

    SinglePtrNode<T>* head() { return _head; }
    SinglePtrNode<T>* tail() { return _tail; }

private:
    SinglePtrNode<T>* _head;
    SinglePtrNode<T>* _tail; 
};
