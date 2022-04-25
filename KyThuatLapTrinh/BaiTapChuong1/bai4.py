import math

def checkDieuKien3CanhTG(a, b, c):
    if(a < 0 or b < 0 or c < 0):
        return False
    if(a + b <= c or a + c <= b or b + c <= a):
        return False
    return True

def checkLoaiTG(a, b, c):
    if ((a == b) and (b == c)):
        return "Tam giac deu"
    elif ((a == b) or (a == c) or (b == c)):
        return "Tam giac can"
    elif ((a * a == b * b + c * c) or (b * b == a * a + c * c) or (c * c == a * a + b * b)):
        return "Tam giac vuong"
    elif ((a * a == b * b + c * c and b == c) or (b * b == a * a + c * c and a == c) or (c * c == a * a + b * b and b == c)):
        return "Tam giac vuong can"
    else:
        return "Tam giac thuong" 

def main():
    a, b, c = map(lambda x: float(x), input("Nhap 3 canh tam giac: ").split())

    while checkDieuKien3CanhTG(a, b, c) == False:
        print("3 canh tam giac khong hop le. Xin hay nhap lai")
        a, b, c = map(lambda x: float(x), input("Nhap 3 canh tam giac: ").split())
    print(checkLoaiTG(a, b, c))
    p = (a + b + c) / 2
    s = math.sqrt(p * (p - a) * (p - b) * (p - c))
    print(f"Dien tich S = {s}")


if __name__ == "__main__":
    main()