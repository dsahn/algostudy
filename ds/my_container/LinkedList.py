"""
cyclic double linked list
"""


class LinkedList:
    def __init__(self):
        self.head = None

    def add_back(self, data):
        new_node = LinkedListNode(data)
        if self.head is None:
            self.head = new_node
        else:
            new_node.prev = self.head.prev
            new_node.next = self.head
            self.head.prev.next = new_node
            self.head.prev = new_node
        return new_node

    def add_mid(self, data, pos):
        new_node = LinkedListNode(data)
        if self.head is None:
            self.head = new_node
        else:
            new_node.next = pos.next
            new_node.prev = pos
            pos.next.prev = new_node
            pos.next = new_node

    def tail(self):
        if self.head == None:
            return None
        else:
            return self.head.prev

    def size(self):
        cur = self.head
        i = 0
        if cur is None:
            return 0
        while True:
            i += 1
            cur = cur.next
            if cur is self.head:
                break
        return i


class LinkedListNode(object):
    def __init__(self, data):
        self.prev = self
        self.next = self
        self.data = data
