/* 오름차순으로 정렬된 배열로부터 그 높이가 가장 낮은 이진탐색트리를 생성하는
 * 알고리즘을 작성하라. 배열 내 모든 원소는 배열 내에서 유일한 값을 가진다.
 * 
 * 오름차순으로 정렬되어있다는 조건 자체가 바이너리 트리를 만들기 용이한
 * 구조임을 의미한다. 이 구조를 그대로 유지하려면 중간 값이 무엇인지 알아낸
 * 다음에 그 중간 값을 기준으로 left, right 트리를 차례대로 만들면 되는 문제.
 *
 * fail1 : segfault 발생
 *   0, 1 두개의 노드만 남았을 때 트리를 만드는 경우를 생각하여 구성해보자..  
 *   이 부분이 문제가 된다.
 *   --> 일반적으로 begin > end 일 때만 재귀를 탈출시키면 된다.
 *       begin == end 의 경우는 leaf node에 해당된다.
 * */
#include <iostream>
#include <string>
#include "tree.h"

using namespace std; 
typedef BinTreeNode<int> intnode;

/* 재귀로 본 문제를 푸는 부분. 출력 부분을 vec_to_tree 에서 수행하기 때문에 
 * 이렇게 구성함 */
intnode* _vec_to_tree(vector<int> v, int beg, int end) { 
    if (beg > end) 
        return nullptr;
    
    int mid = ((beg + end) / 2); 

    intnode* root = new intnode(v.at(mid));
    root->left = _vec_to_tree(v, beg, mid-1);
    root->right = _vec_to_tree(v, mid+1, end);

    return root;
}

/* 원래 트리 구조를 돌려줘야 하지만 테스트를 위해 
 * 화면에 찍어주는 루틴으로 구현하자 */
void vec_to_tree(vector<int> v) { 
    intnode* root = _vec_to_tree(v, 0, v.size()-1); 
    root->print(); 
    cout << endl;
}


int main() {
    vector<int> vec1 = {1,2,3,4,5,6};
    vector<int> vec2 = {1,2,3,4,5,6,7};

    vec_to_tree(vec1);
    vec_to_tree(vec2);
    return 0;
}
