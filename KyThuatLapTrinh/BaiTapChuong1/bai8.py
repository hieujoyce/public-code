import math

def main():
    a, b, c = map(lambda x: float(x), input("Nhap a, b, c: ").split())
    if (a == 0):
        if (b == 0):
            print("Phuong trinh vo nghiem")
        else:
            print("x = ", + (-c / b))
        return
 
    delta = b * b - 4 * a * c
    if (delta > 0):
        x1 = (-b + math.sqrt(delta)) / (2 * a)
        x2 = (-b - math.sqrt(delta)) / (2 * a)
        print(f"x1 = {x1}")
        print(f"x2 = {x2}")
    elif (delta == 0):
        x1 = (-b / (2 * a))
        print("x1 = x2 = ", x1)
    else:
        print("Phuong trinh vo nghiem")

if __name__ == "__main__":
    main()

