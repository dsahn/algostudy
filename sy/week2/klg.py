class Node :
    def __init__(self, data) :
        self.data = data
        self.next = None
        self.prev = None

class LinkedList :
    def __init__(self) :
        self.head = None

    def add(self, data) :
        node = Node(data)
        if self.head == None :
            self.head = node
        else :
            node.next = self.head
            node.prev = self.head.prev
            if self.head.prev != None :
                self.head.prev.next = node
            self.head.prev = node

    def mv_left(self) :
        if self.head.prev != None :
            tmp = self.head.prev
            self.head.prev = tmp.prev
            if tmp.prev != None :
                tmp.prev.next = self.head
            tmp.next = self.head.next
            if self.head.next != None :
                self.head.next.prev = tmp
            self.head.next = tmp
            tmp.prev = self.head


    def mv_right(self) :
        if self.head.next != None :
            tmp = self.head.next
            tmp.prev = self.head.prev
            if tmp.next != None :
                tmp.next.prev = self.head
            self.head.next = tmp.next
            tmp.next = self.head
            if self.head.prev != None :
                self.head.prev.next = tmp
            self.head.prev = tmp

    def remove(self) :
        if self.head.prev != None :
            tmp = self.head.prev
            if tmp.prev != None :
                self.head.prev = tmp.prev
                tmp.prev.next = tmp.next
            if tmp.next != None :
                tmp.next.prev = tmp.prev

    def remove_cursor(self) :
        tmp = self.head
        if self.head.prev != None :
            self.head.prev.next = self.head.next
            self.head = self.head.prev
        if tmp.next != None :
            tmp.next.prev = tmp.prev
            self.head = tmp.next

    def __str__(self) :
        s = ""
        p = self.head
        if p != None :
            while p.prev != None :
                p = p.prev
            while p.next != None :
                s += p.data
                p = p.next
            s += p.data
        return s

str_list = [ ]
l = [ ]
input_num = int(input())
for i in range(input_num) :
    str_list.append(input())
    l.append(LinkedList())
    l[i].add("*Cursor*")

for i in range(input_num) :
    for j in str_list[i] :
        if j == '>' :
            l[i].mv_right()
        elif j == '<' :
            l[i].mv_left()
        elif j == '-' :
            l[i].remove()
        else :
            l[i].add(j)
    l[i].remove_cursor()

for i in range(input_num) :
    print(l[i])
