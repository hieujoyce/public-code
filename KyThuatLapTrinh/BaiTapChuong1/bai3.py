import math

def main():
    xC, yC = map(lambda x: float(x), input("Nhap toa do tam C(xC, yC)? ").split())
    r = float(input("Nhap ban kinh R? "))
    xM, yM = map(lambda x: float(x), input("Nhap toa do M(xM, yM)? ").split())

    d = math.sqrt((xC - xM) ** 2 + (yC - yM) ** 2)
    if(d < r):
        print("M nam trong C()")
    elif(d > r):
        print("M nam ngoai C()")
    else:
        print("M nam tren C()")

if __name__ == "__main__":
    main()