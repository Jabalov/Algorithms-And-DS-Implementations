class Node(object):

    def __init__(self, data):
        self.data = data
        self.next = None

    def remove(self, data, prevNode):
        if self.data == data:
            prevNode.next = self.next
            del self.data
            del self.next
