#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>

template <typename T>
struct BinTreeNode {
    T elem;
    BinTreeNode<T>* left;
    BinTreeNode<T>* right;
    int _depth;

    BinTreeNode<T>(T data) : elem(data), left(nullptr), right(nullptr), _depth(-1) {};

    void print() {
        // std::cout << "elem:"<< elem ;
        std::cout << elem;
        if (left != nullptr || right != nullptr)
            std::cout << "(";
        if (left != nullptr) {
            std::cout << "left:(";
            left->print();
            std::cout << ")";
        }
        if (right != nullptr) {
            std::cout << "right:(";
            right->print();
            std::cout << ")";
        }
        if (left != nullptr || right != nullptr)
            std::cout << ")";
    }
    int depth() {
        if (_depth != -1)
            return _depth;

        int left_depth = 0, right_depth = 0;
        if (left != nullptr)
            left_depth = left->depth();
        if (right != nullptr)
            right_depth = right->depth();
        return 1 + std::max(left_depth, right_depth);
    }
};

template <typename T>
class BinTree {
public:
    BinTree() : _head(nullptr) {}
    // 노드로 이미 트리를 만든 형태로만 트리를 생성하자
    BinTree(BinTreeNode<T>* head) :_head(head) {} 

    BinTreeNode<T>* head() { return _head; }
    void print() { _head->print(); }
    void insert_with_root(T data, BinTreeNode<T>*& root) {
        if (root == nullptr)
            root = new BinTreeNode<T>(data);
        else {
            if (data < root->elem)
                insert_with_root(data, root->left);
            else
                insert_with_root(data, root->right);
        }
    }
    void insert(T data) {
        insert_with_root(data, _head);
    }

    void postorder(BinTreeNode<T>* p, int indent=0)
    {
        if(p != NULL) {
            if(p->right) {
                postorder(p->right, indent+4);
            }
            if (indent) {
                std::cout << std::setw(indent) << ' ';
            }
            if (p->right) std::cout<<" /\n" << std::setw(indent) << ' ';
            std::cout<< p->elem << "\n ";
            if(p->left) {
                std::cout << std::setw(indent) << ' ' <<" \\\n";
                postorder(p->left, indent+4);
            }
        }
    }

    void print_in_tree() {
        postorder(_head);
    }
private:
    BinTreeNode<T> *_head;
};
