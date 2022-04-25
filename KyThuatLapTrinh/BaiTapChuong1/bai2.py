import math

def main():
    xA, yA = map(lambda x: float(x), input("A(xA, yA)? ").split())
    xB, yB = map(lambda x: float(x), input("B(xB, yB)? ").split())
    result = math.sqrt((xB - xA) ** 2 + (yB - yA) ** 2)
    print(f"|AB| = {round(result, 4)}")

if __name__ == "__main__":
    main()