class tile:
    def __init__(self, x, y, distance):
        self.x = x
        self.y = y
        self.distance = distance
        
def withinGrid(n, x, y):
    return x >= 0 and y >=0 and y < n and x < n

def minMoves(n, startRow, startCol, endRow, endCol):
    movement = [[1, 2], [-1, 2], [1, -2], [-1, -2], [2, 1], [2, -1], [-2, 1], [-2, -1]]
    
    visited = [[False for i in range(n+1)]
                for j in range(n+1)]
    visited[startRow][startCol] = True
    # bfs traversal for the shortest distance the knight can travel
    queue = []
    queue.append(tile(startRow, startCol, 0))
    
    while len(queue) > 0:
        item = queue[0];
        queue.pop(0)
        
        if item.x == endRow and item.y == endCol:
            return item.distance
        
        for i in range(len(movement)):
            changeX = item.x + movement[i][0]
            changeY = item.y + movement[i][1]
            if withinGrid(n, changeX, changeY) and not visited[changeX][changeY]:
                queue.append(tile(changeX, changeY, item.distance + 1))
                visited[changeX][changeY] = True
                
    
    return -1