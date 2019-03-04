from LinkedList import Node

class LinkedList(object):

    def __init__(self):
        self.head = None
        self.cnt = 0

    def push_front(self, data):
        self.cnt += 1
        newNode = Node(data)
        if not self.head:
            self.head = newNode
        else:
            newNode.next = self.head
            self.head = newNode

    def size(self):
        return self.cnt

    def push_back(self, data):
        newNode = Node()
        actualNode = self.head

        while actualNode.next is not None:
            actualNode = actualNode.next

        actualNode.next = newNode

    def remove(self, data):
        
