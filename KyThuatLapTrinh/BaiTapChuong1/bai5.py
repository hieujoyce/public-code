import math

def getArea(x1, y1, x2, y2, x3, y3):
    return (1 / 2) * abs(x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3)

def main():
    xA, yA = map(lambda x: float(x), input("A(xA, yA)? ").split())
    xB, yB = map(lambda x: float(x), input("B(xB, yB)? ").split())
    xC, yC = map(lambda x: float(x), input("C(xC, yC)? ").split())
    xM, yM = map(lambda x: float(x), input("M(xM, yM)? ").split())

    areaABM = getArea(xA, yA, xB, yB, xM, yM)
    areaBCM = getArea(xB, yB, xC, yC, xM, yM)
    areaACM = getArea(xA, yA, xC, yC, xM, yM)
    areaABC = getArea(xA, yA, xB, yB, xC, yC)
    d = (areaABM + areaACM + areaBCM) - areaABC

    if (d > 0):
        print("M nam ngoai tam giac")
    elif (areaABM == 0 or areaACM == 0 or areaBCM == 0):
        print("M nam tren canh tam giac")
    else:
        print("M nam trong tam giac")


if __name__ == "__main__":
    main()