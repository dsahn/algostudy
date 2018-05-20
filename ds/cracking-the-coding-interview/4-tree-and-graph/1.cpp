/* 주어진 유향 그래프에서 특정한 두 노드 간에 경로가 존재하는지 
 * 판별하는 알고리즘을 구현하라  
 *
 * 결국에 전수 조사하는 방법으로 구현해야 할 것 같다.
 * dfs, bfs 중 택일하자..
 *
 * binary tree라는 조건은 없었지만 문제를 단순화 시키기 위해서...
 * */

#include <iostream>
#include <string>
#include "tree.h"

using namespace std; 
typedef BinTreeNode<int> intnode;

// dfs way
// 사실 반대로 오는 경우도 해줘야 한다. 유향 그래프이기 때문에 반대로 오는
// 경우도 생각해야 할듯..
bool has_path(intnode* from, intnode* to) {
    if (from == nullptr || to == nullptr)
        return false;
    if (from->elem == to->elem)
        return true;
    else
        return has_path(from->left, to) || has_path(from->right, to);
}

int main() {
    intnode *a = new intnode(1);
    intnode *b = new intnode(2);
    intnode *c = new intnode(3);
    intnode *d = new intnode(4);
    intnode *e = new intnode(5);
    intnode *f = new intnode(6);
    
    a->left = b;
    b->left = c;
    b->right = d;
    d->right = e;

    bool res;

    res = has_path(a, e); // expected true
    cout << res << endl;
    res = has_path(a, f); // expected false
    cout << res << endl;
}


