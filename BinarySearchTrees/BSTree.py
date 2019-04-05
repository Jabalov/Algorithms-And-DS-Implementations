from BSTree.Node import Node

class BST(object):

    def __init__(self):
        self.root = None

    def insert(self, val):
        if not self.root:
            self.root = Node(val)
        else:
            self.root.insert(val)

    def remove(self, val):
        if self.root:
            if self.root.data == val:
                tmp = Node(None)
                tmp.left = self.root
                self.root.remove(val, tmp)
        else:
            self.root.remove(val, None)

    def getMax(self):
        if self.root:
            return self.root.getMax()

    def getMin(self):
        if self.root:
            return self.root.getMin()
