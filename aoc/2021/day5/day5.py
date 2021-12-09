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
        except EOFError:
            break


    for i in range(1000):
        for j in range(1000):
            ret += arr[i][j] > 1

    print(ret)