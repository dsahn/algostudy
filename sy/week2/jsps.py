from __future__ import print_function

class Node :
    def __init__(self, data) :
        self.data = data
        self.next = None

class LinkedList :
    def __init__(self) :
        self.head = None
        self.tail = None

    def add(self, data) :
        node = Node(data)
        if self.head == None :
            self.head = node
            self.tail = node
        else :
            self.tail.next = node
            node.next = None
            self.tail = node

    def remove(self, k) :
        p = self.head
        if k == 1 :
            self.head = self.head.next
            return p.data
        for i in range(k - 2) :
            self.head = self.head.next
        tmp = self.head.next
        self.head.next = tmp.next
        self.head = tmp.next
        return tmp.data

    def circul(self) :
        self.tail.next = self.head

l = LinkedList()
list = map(int, raw_input().split())
for i in range(1, list[0]+1):
    l.add (str(i))

l.circul()

print('<', end='')
for i in range(list[0] - 1):
    print(l.remove(list[1]), end=', ')
print(l.remove(list[1]), end='')
print('>', end=' ')
