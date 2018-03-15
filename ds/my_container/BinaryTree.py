class BinaryTreeNode(object):
    def __init__(self, data, left = None, right = None):
        self.__data = data
        self.__left = left
        self.__right = right

    @property
    def data(self):
        return self.__data

    @data.setter
    def data(self, data):
        self.__data = data

    @property
    def left(self):
        return self.__left

    @left.setter
    def left(self, node):
        if not isinstance(node, BinaryTreeNode):
            raise TypeError
        self.__left = node

    @property
    def right(self):
        return self.__right

    @right.setter
    def right(self, node):
        if not isinstance(node, BinaryTreeNode) and node is not None:
            print(node)
            raise TypeError
        self.__right = node

    def __repr__(self):
        return "({}:{})".format(str(self.data), str(self.left) + "/" + str(self.right) if (self.left is not None or self.right is not None)  else "LEAF")


class BinaryTree(object):
    def __init__(self):
        self.__root = None

    @property
    def root(self):
        return self.__root

    @root.setter
    def root(self, node):
        if not isinstance(node, BinaryTreeNode):
            raise TypeError
        self.__root = node

    def __repr__(self):
        ret_str = ""
        if self.__root is None:
            pass
        else:
            ret_str = str(self.root)
            """
            q = []
            depth = 0
            q.append(self.root)
            q.append(BinaryTreeNode(None))
            while len(q) > 1:
                node = q.pop(0)
                if node.data is None:
                    q.append(BinaryTreeNode(None))
                    depth += 1
                    continue
                if node.left is not None:
                    q.append(node.left)
                if node.right is not None:
                    q.append(node.right)
                ret_str += "\t"*depth + str(node) + "\n"
            """
        return ret_str


def test():
    bt = BinaryTree()
    bt.root = BinaryTreeNode(1)
    print(bt)

