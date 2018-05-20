#include <vector>
#include <iostream>

template <typename T>
struct BinTreeNode {
    T elem;
    BinTreeNode<T>* left;
    BinTreeNode<T>* right;

    BinTreeNode<T>(T data) : elem(data), left(nullptr), right(nullptr) {};
    void print() {
        std::cout << elem << ", ";
        left->print();
        right->print();
    }
};

template <typename T>
class BinTree {
public:
    // 노드로 이미 트리를 만든 형태로만 트리를 생성하자
    BinTree(BinTreeNode<T>* head) :_head(head) {} 
    void print() { std::cout << _head->print() << std::endl; }
private:
    BinTreeNode<T> *_head;
};
