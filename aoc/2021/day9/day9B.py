import math
dx = [-1, 0, 1, 0] # Left, Up, Right, Down
dy = [0, -1, 0, 1]

if __name__ == "__main__":
    arr = []
    while True:
        try:
            line = str(input())
            row = [int(line[x]) for x in range(len(line))]
            arr.append(row)
        except EOFError:
            break
    
    n = len(arr)
    m = len(arr[0])

    low_pts = []

    for i in range(n):
        for j in range(m):
            pt = arr[i][j]
            shouldAdd = True
            for k in range(len(dx)):
                dirx = dx[k]
                diry = dy[k]
                hor = i + dirx
                ver = j + diry 
                if hor >= 0 and hor < n and ver >= 0 and ver < m:
                    # valid square
                    if pt >= arr[hor][ver]:
                        shouldAdd = False
            
            if shouldAdd:
                low_pts.append([i, j])
    
    sizes = []
    visited = [[False]*m for i in range(n)]
    for low_pt in low_pts:
        x, y = low_pt
        size = 0
        if visited[x][y]:
            continue
        q = []
        q.append([x, y])
        while not len(q) == 0:
            pt = q.pop(0)
            i, j = pt
            if visited[i][j]:
                continue
            visited[i][j] = True
            size += 1
            for k in range(len(dx)):
                dirx = dx[k]
                diry = dy[k]
                hor = i + dirx
                ver = j + diry
                if hor >= 0 and hor < n and ver >= 0 and ver < m:
                    if arr[hor][ver] > arr[i][j] and arr[hor][ver] != 9:
                        q.append([hor, ver])
        sizes.append(size)
    print(sorted(sizes)[-3:])
    print(math.prod(sorted(sizes)[-3:]))
    # print(sorted(sizes[-3:]))

