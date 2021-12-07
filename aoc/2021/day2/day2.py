import fileinput

if __name__ == "__main__":
    hor = 0
    ver = 0
    for line in fileinput.input():
        typ, dist = line.split()
        dist = int(dist)
        if typ == "forward":
            hor += dist
        elif typ == "down":
            ver += dist
        else:
            ver -= dist
    
    print(hor * ver)