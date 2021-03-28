
class Graph:
    def __init__(self, gdict=None):
        if gdict is None:
            gdict = {}
        self.gdict = gdict

    def add_edge(self, vertex, edge):
        self.gdict[vertex].append(edge)

    def dfs(self, vertex):
        visited = [vertex]
        stack = [vertex]

        while stack:
            popVertex = stack.pop()
            print(popVertex)
            for adjacentVertex in self.gdict[popVertex]:
                if adjacentVertex not in visited:
                    visited.append(adjacentVertex)
                    stack.append(adjacentVertex)


customDict = {"a": ["b", "c"],
              "b": ["a", "d", "e"],
              "c": ["a", "e"],
              "d": ["b", "e", "f"],
              "e": ["d", "f", "c"],
              "f": ["d", "e"]
              }


g = Graph(customDict)
g.dfs("a")
