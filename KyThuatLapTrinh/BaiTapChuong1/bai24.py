from functools import reduce
import math

def main():
    n = int(input("Nhap n: "))
    print(f"{n} co {len(str(n))} chu so")
    print(f"Chu so cuoi cung la: { str(n)[ len(str(n)) - 1 ] }")
    print(f"Chu so dau tien la: { str(n)[ 0 ] }")

    print(f"Tong cac chu so la: { reduce(lambda x, y: int(x) + int(y), list( str(n) )) }"  )
    print(f"So dao nguoc la: { int( str(n)[::-1] ) }")

if __name__ == "__main__":
    main()