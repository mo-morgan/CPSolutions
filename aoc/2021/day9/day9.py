dx = [-1, 0, 1, 0] # Left, Up, Right, Down
dy = [0, -1, 0, 1]

if __name__ == "__main__":
    ans = 0
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
                ans += pt + 1
    
    print(ans)