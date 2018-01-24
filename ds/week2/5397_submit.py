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

    # p, n : prev, next node
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

class StringList(LinkedList):
    def __init__(self):
        super().__init__()
        self.pos = self.head

    def remove_char(self):
        if self.pos == self.head:
            self.head = None
            self.pos = None
        else:
            self.pos.prev.next = self.pos.next
            self.pos.next.prev = self.pos.prev
            self.pos = self.pos.prev

    def add_char(self, data):
        if self.pos is None:
            super().add_back(data)
            self.pos = self.head
        else:
            super().add_mid(data, self.pos)
            self.pos = self.pos.next


    def add(self, data):
        if data == '<':
            if self.pos != self.head:
                self.pos = self.pos.prev
        elif data == '>':
            if self.pos != self.head.prev:
                self.pos = self.pos.next
        elif data == '-':
            self.remove_char()
        else:
            self.add_char(data)

    def out(self):
        cur = self.head
        if cur is None:
            return
        while True:
            print(cur.data, end="")
            cur = cur.next
            if cur is self.head:
                break

    def write(self, s): #s :string
        for c in s:
            self.add(c)




def solve(inputs):
    for str in inputs:
        str_list = StringList()
        str_list.write(str)
        str_list.out()
        print()



n = input()
in_list = []
for _ in range(int(n)) :
    in_list.append(input())
solve(in_list)