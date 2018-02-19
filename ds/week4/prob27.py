"""
주어진 중위, 전위 탐색 결과로부터 이진 트리를 만드는 알고리즘을 알아보자
예 :
 중위-D B E A F C
 전위-A B D E C F
"""

from ds.my_container.BinaryTree import BinaryTree, BinaryTreeNode


def _build_tree(in_list, pre_list, in_start, in_end):
    pre_char = pre_list.pop(0)
    index = in_list.index(pre_char)
    new_node= BinaryTreeNode(pre_char)
    """
    tree를 생성할 때에는 좌, 우 자식노드를 완성시키고, 노드를 반환하는 방식,
    탐색할때에는 노드를 인자로 주던지 리턴하여 구성하는 식으로 하는듯?
    """
    if index > in_start:
        new_node.left = _build_tree(in_list, pre_list, in_start, index)
    if index+1 < in_end:
        new_node.right = _build_tree(in_list, pre_list, index+1, in_end)
    return new_node


def build_tree(inorder, preorder):
    # in_list, pre_list 굳이 만들 필요가?
    in_list = [x for x in inorder]
    pre_list = [x for x in preorder]
    bt = BinaryTree()

    bt.root = _build_tree(in_list, pre_list, 0, len(preorder))

    print(str(bt))


inorder = "DBEAFC"
preorder = "ABDECF"

build_tree(inorder, preorder)