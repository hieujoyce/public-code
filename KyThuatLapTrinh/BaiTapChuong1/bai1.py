import math

def main():
    PI = 3.141593
    s = float(input("Nhap dien tich S: "))
    r = math.sqrt(s / 4 / PI)
    v = (4 / 3) * PI * pow(r, 3)
    print(f"The tich V = {round(v, 6)}")

if __name__ == "__main__":
    main()