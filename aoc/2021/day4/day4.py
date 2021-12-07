def calculateSum(grid):
    sum = 0
    for i in range(len(grid)):
        for j in range(5):
            if grid[i][j] != -1:
                sum += grid[i][j]
    return sum

def bingoSum(grid):
    for i in range(len(grid)):
        bingo = True
        for j in range(5):
            if grid[i][j] != -1:
                bingo = False
        if bingo:
            return calculateSum(grid)
    for i in range(len(grid)):
        bingo = True
        for j in range(5):
            if grid[j][i] != -1:
                bingo = False
        if bingo:
            return calculateSum(grid)
    bingo = True
    for i in range(5):
        if grid[i][i] != -1:
            bingo = False
    if bingo:
        return calculateSum(grid)
    bingo = True
    for i in range(4, 0, -1):
        if grid[i][i] != -1:
            bingo = False
    if bingo:
        return calculateSum(grid)

    return -1

def Boards(allGrids):
    for i in range(len(allGrids)):
        s = bingoSum(allGrids[i])
        if s != -1:
            return s
    
    return -1

if __name__ == "__main__":
    order = [int(x) for x in input().split(',')]
    allGrids = []
    grid = []
    while True:
        try:
            row = [int(x) for x in input().split()]
            if row != []:
                grid.append(row)
            if len(grid) == 5:
                allGrids.append(grid)
                grid = []
        except EOFError:
            break
    t = len(allGrids)
    idx = 0
    while True:
        if idx == len(order):
            print("Error cause reached end of order")
            break
        for i in range(t):
            for j in range(5):
                for k in range(5):
                    if allGrids[i][j][k] == order[idx]:
                        allGrids[i][j][k] = -1
        s = Boards(allGrids)
        if s != -1:
            print(s * order[idx])
            break

        idx += 1
                