import fileinput

if __name__ == "__main__":
    hor = 0
    dep = 0
    aim = 0
    for line in fileinput.input():
        typ, dist = line.split()
        dist = int(dist)
        if typ == "forward":
            hor += dist
            dep += aim * dist
        elif typ == "down":
            aim += dist
        else:
            aim -= dist
    
    print(hor * dep)