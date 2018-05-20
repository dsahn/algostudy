template <typename T>
struct BinTreeNode {
    T elem;
    BinTreeNode<T>* left;
    BinTreeNode<T>* right;

    BinTreeNode<T>(T data) : elem(data), left(nullptr), right(nullptr) {};
};


/*
 * 귀찮으니 일단 tree node 만 만들자 
 *
 * template <typename T>
 * class BinTree {
 *     BinTree() :_head(nullptr) {}
 * private:
 *     BinTreeNode<T> *_head;
 * };
 */
