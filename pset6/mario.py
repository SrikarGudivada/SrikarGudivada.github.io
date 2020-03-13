def main():
    while True:
        n = input("Height: ")
        try:
            n = int(n)
            if n>=1 and n<=23:
                break
        except:
            pass
    for i in range(n):
        for j in range(n-1-i):
            print(" ",end="")
        j = j+1
        if (n-1-i) == 0:
            j = 0
        for k in range(n-j+1):
            print("#",end="")
        print()
 
if __name__ == "__main__":
    main()
 