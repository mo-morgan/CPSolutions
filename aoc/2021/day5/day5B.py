if __name__ == "__main__":
    ret = 0
    arr = [[0]*1000 for i in range(1000)]
    while True:
        try:
            line = input().split(' -> ')
            startx, starty = [int(x) for x in line[0].split(',')]
            endx, endy = [int(x) for x in line[1].split(',')]

            if startx == endx:
                for i in range(min(starty, endy), max(starty+1, endy+1)):
                    arr[startx][i] += 1
            elif starty == endy:
                for i in range(min(startx, endx), max(startx+1, endx+1)):
                    arr[i][starty] += 1
            # diagonal line is valid if abs(dx) == abs(dy)
            elif abs(startx - endx) == abs(starty - endy):
                # We will first the x value to start as min(startx, endx)
                # since x is fixed, we know that theres only 2 cases left:
                #                       diagonal upwards
                #                       or diagonal downwards
                # the following code is the traversal logic based on the two cases
                x = startx
                y = starty
                if min(startx, endx) == endx:
                    x = endx
                    y = endy
                dist = abs(startx - endx)
                dy = 1
                if y == starty:
                    if starty > endy:
                        dy = -1
                else:
                    if endy > starty:
                        dy = -1
                for i in range(x, max(startx+1, endx+1)):
                    arr[i][y] += 1
                    y += dy

        except EOFError:
            break


    for i in range(1000):
        for j in range(1000):
            ret += arr[i][j] > 1

    print(ret)