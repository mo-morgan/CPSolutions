if __name__ == "__main__":
    lines = []
    while True:
        try:
            s = input()
            lines.append(s)
        except EOFError:
            break
    n = len(lines)
    m = len(lines[0])
    majority = ''
    for i in range(m):
        c1 = 0
        c0 = 0
        for j in range(n):
            c = lines[j][i]
            if c == '0':
                c0 += 1
            else:
                c1 += 1
        
        if c1 > c0:
            majority += '1'
        else:
            majority += '0'
    
    minority = ''
    for i in range(len(majority)):
        if majority[i] == '1':
            minority += '0'
        else:
            minority += '1'
    
    k = int(majority, 2) * int(minority, 2)
    print(k)