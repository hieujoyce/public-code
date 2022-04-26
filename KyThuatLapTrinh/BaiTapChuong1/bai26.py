def uscln(a, b):
    if (b == 0):
        return a
    return uscln(b, a % b)

def main():
    a, b = map(lambda x: int(x), input("Nhap tu so, mau so: ").split())
    c = uscln(a, b)
    if((a < 0 and b < 0) or (a >= 0 and b > 0)):
        if(abs(int(b / c)) == 1):
            print(f"Rut gon: {abs(int(a / c))}")
            return
        print(f"Rut gon: {abs(int(a / c))}/{abs(int(b / c))}")
    else:
        if(abs(int(b / c)) == 1):
            print(f"Rut gon: -{abs(int(a / c))}")
            return
        print(f"Rut gon: -{abs(int(b / c))}/{abs(int(b / c))}")

if __name__ == "__main__":
    main()