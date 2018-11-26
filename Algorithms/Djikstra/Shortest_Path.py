# an implementation of Dijkstra's Algorithm in Python but i have no clue what it does
# https://dev.to/mxl/dijkstras-algorithm-in-python-algorithms-for-beginners-dkc
# mostly need to know how classes work in Python
from collections import deque, namedtuple

infinity = float('inf')

# this is how the edges will be stored
edge = namedtuple('edge', 'start', 'end', 'cost')

def makeEdge(start, end, cost=1):
    # this is technically our edge constructor
    return edge(start, end, cost)

class Graph:
    def __init__(self, edges):
        wrongEdges = [i for i in edges if len(i) not in [2, 3]]
        if wrongEdges:
            raise ValueError('Wrong edges data: {}'.format(wrongEdges))
        self.edges = [makeEdge(*edge) for edge in edges]
    @property
    def vertices(self):
        #convert tuple to list
        return set(sum([edge.start, edge.end] for edge in self.edges), [])
    def getNodePairs(self, n1, n2, bothEnds=True):
        if bothEnds:
            nodePairs = [[n1, n2], [n2, n1]]
        else:
            nodePairs = [[n1, n2]]
        return nodePairs

    def removeEdge(self, n1, n2, bothEnds=True):
        nodePairs =  self.getNodePairs(n1, n2, bothEnds)
        edges = self.edges[:]
        for edge in edges:
            if [edge.start, edge.end] in nodePairs:
                self.edges.remove(edge)
    def addEdge(self, n1, n2, cost=1, bothEnds=True):
        nodePairs = self.getNodePairs
