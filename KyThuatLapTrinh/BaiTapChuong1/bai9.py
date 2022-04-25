import math

def main():
    x = float(input("Nhap so do x cua goc (phut): "))
    deg = x / 60
    print(f"x thuoc goc vuong thu {(int)(deg // 90) + 1}")
    print(f"cos(x) = {math.cos( deg * math.pi / 180 )}")
    

if __name__ == "__main__":
    main()