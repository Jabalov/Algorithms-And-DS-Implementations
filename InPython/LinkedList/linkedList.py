
class Node(object):

    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList(object):

    def __init__(self):
        self.head = None
        self.siz = 0

    def insert_at_start(self, data):
        self.siz += 1
        new_node = Node(data)

        if not self.head:
            self.head = new_node
        else:
            new_node.next = self.head
            self.head = new_node

    def insert_at_end(self, data):
        self.siz += 1
        new_node = Node(data)
        current = self.head

        while current.next is not None:
            current = current.next

        current.next = new_node

    def remove(self, data):
        self.siz -= 1
        if self.head is None:
            return

        current = self.head
        prev = None

        while current.data != data:
            prev = current
            current = current.next

        if prev is None:
            self.head = current.next
        else:
            prev.next = current.next

    def get_size(self):
        return self.siz

    def traverse(self):
        current = self.head

        while current is not None:
            print(current.data)
            current = current.next


ll = LinkedList()
numbers = [1, 23, 4, 5, 3, 1]

for number in numbers:
    ll.insert_at_start(number)

ll.insert_at_end(111)
print("size:", ll.get_size())
ll.remove(111)
print("size:", ll.get_size())

ll.traverse()
