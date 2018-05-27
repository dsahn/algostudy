/* 주어진 이진 트리가 균형 이진 트리인지 판별하는 함수를 구현하라
 * 이 문제에서 이진 트리는 어떤 노드의 두 자식 트리 깊이가 하나 이상 차이나지
 * 않는 트리이다. 
 *
 * 간단하게 재귀로 풀자면 자식 노드간의 길이를 잰 후에 비교하여 t/f를 돌려주는
 * 방법을 생각할 수 있겠지만, 가장 짧은 노드(리프노드를 가장 처음 만나는 경우)
 * 를 만났을 때 그 이후가 1 이상 차이나는지 확인하면 좀더 노드 방문수를 줄일
 * 수 있을 거 같다.. 시간 복잡도는 똑같겠지만.
 * --> 알고리즘이 두벌이 되던지 2pass로 진행될거같다. 그냥 단벌 알고리즘으로
 *  하자..
 * */

#include <iostream>
#include <string>
#include "tree.h"

using namespace std; 
typedef BinTreeNode<int> intnode;
typedef BinTree<int> inttree;

bool is_balanced(intnode* root)
{
    if (root == nullptr)
        return true;
    int ldepth = 0, rdepth = 0;
    ldepth = (root->left) ? root->left->depth() : 0;
    rdepth = (root->right) ? root->right->depth() : 0;
    if (abs(ldepth - rdepth) > 1)
        return false;
    return is_balanced(root->left) && is_balanced(root->right);
}

int main() {
    inttree tree;
    int a[] = { 5, 3, 8, 1, 4, 7, 10, 2, 6, 9, 11, 12 };
    for (auto i : a)
        tree.insert(i);
    tree.print_in_tree();
    /* tree.print(); */
    cout << is_balanced(tree.head()) << endl;
    /* XXX false 가 나와야 할 것 같은데 true가 나온다.
     * 4와 12의 depth를 max만 가지고는 비교할수 없기때문인데 
     * 이걸 어떻게 해결해야 할지..*/
    return 0;
}
