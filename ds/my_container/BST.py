from ds.my_container.BinaryTree import BinaryTree, BinaryTreeNode

"""
TODO
find
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

    def remove(self, data):
        self.remove_internal(self.root, data)

    def remove_internal(self, root, data):
        if data < root.data:
            root.left = self.remove_internal(root.left, data)
        elif data > root.data:
            root.right = self.remove_internal(root.right, data)
        # found data
        else:
            # if leaf
            if root.left is None and root.right is None:
                return None
            # else if has only one child
            elif root.left is None or root.right is None:
                if root.left is not None:
                    root = root.left
                else:
                    root = root.right
            # else has two child
            else:
                new_root = self.find_max(root.left)
                root.data = new_root.data
                root.left = self.remove_internal(root.left, new_root.data)
        return root

    def find_max(self, root):
        if root is None:
            return None
        elif root.right is None:
            return root
        else:
            return self.find_max(root.right)


def test():
    bst = BST()
    bst.add(4)
    bst.add(2)
    bst.add(8)
    bst.add(5)
    bst.add(7)
    bst.add(6)
    bst.add(10)
    bst.remove(8)

    print(bst)

test()
