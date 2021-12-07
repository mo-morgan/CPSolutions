def calcMaj(lines2, maj, mino):
    m = len(lines2[0])
    for i in range(m):
        c1 = 0
        c0 = 0
        n = len(lines2)
        for j in range(n):
            c = lines2[j][i]
            if c == maj:
                c0 += 1
            else:
                c1 += 1

        if c0 >= c1:
            it = filter(lambda l: (l[i] == maj), lines2)
            lines2 = list(it)
        else:
            it = filter(lambda l: (l[i] == mino), lines2)
            lines2 = list(it)

        if lines2[:-1] == lines2[1:]:
            minority = lines2[0]
            break
    return minority

def calcMin(lines2, mino, maj):
    m = len(lines2[0])
    for i in range(m):
        c1 = 0
        c0 = 0
        n = len(lines2)
        for j in range(n):
            c = lines2[j][i]
            if c == mino:
                c0 += 1
            else:
                c1 += 1

        if c0 <= c1:
            it = filter(lambda l: (l[i] == mino), lines2)
            lines2 = list(it)
        else:
            it = filter(lambda l: (l[i] == maj), lines2)
            lines2 = list(it)

        if lines2[:-1] == lines2[1:]:
            minority = lines2[0]
            break
    return minority

if __name__ == "__main__":
    lines = []
    while True:
        try:
            s = input()
            lines.append(s)
        except EOFError:
            break
    m = len(lines[0])
    lines2 = []
    lines2[:] = lines[:]
    majority = calcMaj(lines, '1', '0')
    minority = calcMin(lines2, '0', '1')
    
    k = int(majority, 2) * int(minority, 2)
    print(k)