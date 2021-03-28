#   Created by Elshad Karimov
#   Copyright © 2021 AppMillers. All rights reserved.

from collections import defaultdict


class Graph:
    def __init__(self, numberofVertices):
        self.graph = defaultdict(list)
        self.numberofVertices = numberofVertices

    def addEdge(self, vertex, edge):
        self.graph[vertex].append(edge)

    def topogologicalSortUtil(self, v, visited, stack):
        visited.append(v)

        for node in self.graph[v]:
            if node not in visited:
                self.topogologicalSortUtil(node, visited, stack)

        stack.insert(0, v)

    def topologicalSort(self):

        visited = []
        stack = []

        for k in list(self.graph):
            if k not in visited:
                self.topogologicalSortUtil(k, visited, stack)

        print(stack)


g = Graph(8)
g.addEdge("A", "C")
g.addEdge("C", "E")
g.addEdge("E", "H")
g.addEdge("E", "F")
g.addEdge("F", "G")
g.addEdge("B", "D")
g.addEdge("B", "C")
g.addEdge("D", "F")

g.topologicalSort()
