
class Node(object):
    def __init__(self, data):
        self.data  = data
        self.left  = None
        self.right = None

    def insert(self, val):
        if v < self.data:
            if not self.left:
                self.left = Node(val)
            else:
                self.left.insert(val)

        else:
            if not self.right:
                self.right = Node(val)
            else:
                self.right.insert(val)

    def getMin(self):
        if self.left is None:
            return self.data
        else:
            return self.left.getMin()

    def getMax(self):
        if self.right is None:
            return self.right
        else:
            return self.right.getMax()

    def traverseInOrder(self):
        if self.left is not None:
            self.left.traverseInOrder()

        print(self.data)

        if self.right is not None:
            self.right.traverseInOrder()
