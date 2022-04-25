def main():
    a, b, c = map(lambda x: float(x), input("Nhap a, b, c: ").split())

    if(a > b):
        tmp = a
        a = b
        b = tmp
    if(a > c):
        tmp = a
        c = c
        c = tmp
    if(b > c):
        tmp = b
        b = c
        c = tmp
    print(f"Tang dan: {a} {b} {c}")

if __name__ == "__main__":
    main()