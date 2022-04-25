def main():
    a, b = map(lambda x: float(x), input("Nhap a, b: ").split())

    if a == 0:
        if b == 0:
            print("Vo so nghiem")
        else:
            print("Vo ngiem")
    else:
        print("x = ", -b / a)

if __name__ == "__main__":
    main()

