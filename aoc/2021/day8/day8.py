if __name__ == "__main__":
    c = 0
    while True:
        try:
            after = input().split(" | ")[1]
            nums = after.split()
            valid = [2, 3, 4, 7]
            for i in range(len(nums)):
                k = len(nums[i])
                if k in valid:
                    c += 1
        except EOFError:
            break

    print(c)
