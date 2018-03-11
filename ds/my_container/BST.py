from ds.my_container.BinaryTree import BinaryTree, BinaryTreeNode

"""
TODO
find, remove
left, right setter를 막아야 하나??
==> 굳이 안막고 그냥 add 하는 동작만 BST에 둬도 될거같은데?
"""


class BST(BinaryTree):
    # recursive approach 는 피해보자
    def add(self, data):
        new = BinaryTreeNode(data)
        if self.root is None:
            self.root = new
            return
        cur = self.root
        while True:
            if data < cur.data:
                if cur.left is None:
                    cur.left = new
                    break
                else:
                    cur = cur.left
            else:  # data > cur.data
                if cur.right is None:
                    cur.right = new
                    break
                else:
                    cur = cur.right


def test():
    bst = BST()
    bst.add(1)
    bst.add(2)
    bst.add(3)
    bst.add(4)

    print(bst)
