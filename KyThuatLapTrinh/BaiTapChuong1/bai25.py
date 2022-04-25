import math

def uscln(a, b):
    if (b == 0):
        return a
    return uscln(b, a % b)

def bscnn(a, b):
    return int((a * b) / uscln(a, b))

def main():
    a, b = map(lambda x: int(x), input("Nhap cap (a, b): ").split())
    print(f"USCLN (a, b): {uscln(a, b)}")
    print(f"BSCNN (a, b): {bscnn(a, b)}")

    

if __name__ == "__main__":
    main()