"""
키로거 (https://www.acmicpc.net/problem/5397)
"""

from ds.my_container.LinkedList import LinkedList, LinkedListNode


class StringList(LinkedList):
    def __init__(self):
        super().__init__()
        self.pos = self.add_back('POS')

    def remove_char(self):
        if self.pos == self.head:
            self.head = self.pos
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
            if self.pos != self.tail():
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
            if cur.data is not 'POS':
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

"""
n = 1
in_list = ['-----abc<<<-']
solve(in_list)
"""

"""
n = 2
in_list = ['<<BP<A>>Cd-', 'ThIsIsS3Cr3t']
solve(in_list)
"""
