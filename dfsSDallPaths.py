def DFS_all_paths(G, src, dest):
    all_paths = []  # List to store all paths
    path = []  # Current path

    def DFS_visit(G, current, dest, path, all_paths):
        current.color = 'gray'  # Mark as partially visited
        path.append(current)  # Add current node to the path

        if current == dest:
            all_paths.append(path.copy())  # Found a path, add a copy of it to all_paths
        else:
            for v in current.Adj:
                if v.color == 'white':
                    DFS_visit(G, v, dest, path, all_paths)  # Recursive call to unvisited adjacent vertex

        path.pop()  # Backtrack: remove current node from the path
        current.color = 'white'  # Reset the color for other paths

    # Initialize all vertices as unvisited (white)
    for v in G.V:
        v.color = 'white'
        v.PI = None

    # Start DFS from the source vertex
    DFS_visit(G, src, dest, path, all_paths)

    return all_paths


# Example graph structure
class Vertex:
    def __init__(self, id):
        self.id = id
        self.color = 'white'
        self.PI = None
        self.Adj = []


class Graph:
    def __init__(self):
        self.V = []

    def add_vertex(self, vertex):
        self.V.append(vertex)


# Create vertices
v1 = Vertex(1)
v2 = Vertex(2)
v3 = Vertex(3)
v4 = Vertex(4)
v5 = Vertex(5)
v6 = Vertex(6)
v7 = Vertex(7)

# Define adjacency lists
v1.Adj = [v2]
v2.Adj = [v3, v6, v7]
v3.Adj = [v4, v5]
v5.Adj = [v4]
v6.Adj = [v4, v7]
v7.Adj = [v4]

# Create the graph and add vertices
G = Graph()
G.add_vertex(v1)
G.add_vertex(v2)
G.add_vertex(v3)
G.add_vertex(v4)
G.add_vertex(v5)
G.add_vertex(v6)
G.add_vertex(v7)

# Find all paths from v1 to v4
all_paths = DFS_all_paths(G, v1, v4)
for path in all_paths:
    print([v.id for v in path])
