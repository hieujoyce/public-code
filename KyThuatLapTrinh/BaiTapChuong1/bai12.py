def main():
    a1, b1, c1 = map(lambda x: float(x), input("Nhap a1, b1, c1: ").split())
    a2, b2, c2 = map(lambda x: float(x), input("Nhap a2, b2, c2: ").split())

    D = a1 * b2 - a2 * b1
    Dx = c1 * b2 - c2 * b1
    Dy = a1 * c2 - a2 * c1
    if (D == 0):
        if (Dx + Dy == 0):
            print("He phuong trinh co vo so nghiem")
        else:
            print("He phuong trinh vo nghiem")
    else:
        x = Dx / D
        y = Dy / D
        print(f"x = {x}")
        print(f"y = {y}")
    

if __name__ == "__main__":
    main()