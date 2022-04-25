import math

def kiemTraHoanHao(n):
    tong = 0
    for i in range(1, int(n / 2) + 1):
        if (n % i) == 0:
            tong += i
    if tong == n:
        return True
    else:
        return False

def main():
    n = int(input("Nhap n: "))
    print(f"Cac so hoan hao nho hon {n} la: ", end="")
    for i in range(6, n):
        if(kiemTraHoanHao(i) == True):
            print(i, end=" ")
        

    

if __name__ == "__main__":
    main()