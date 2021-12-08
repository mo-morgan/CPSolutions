if __name__ == "__main__":
    c = 0
    while True:
        try:
            before, after = input().split(" | ")
            # figure out digits:
            inp = before.split()
            pos = 'abcdefg'
            d = {}
            for i in range(len(before)):
                k = before[i]
                n = len(k)
                if n == 2:
                    d[k] = 1
                elif n == 3:
                    d[k] = 7
                    pos
                elif n == 4:
                    d[k] = 4
                elif n == 7:
                    d[k] = 8
            


            nums = after.split()
            num = ""
            for i in range(len(nums)):
                k = ''.join(sorted(nums[i]))
                print(k)
                num += str(d[k])
            
            c += int(num)
        except EOFError:
            break

    print(c)