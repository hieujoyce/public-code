
def main():
    d, m, y = map(lambda x: int(x), input("Nhap ngay, thang va nam: ").split())
    sum = int(30.42 * (m - 1)) + d
    if( ( ( ( y % 4 == 0 and y % 100 != 0 ) or y % 400 == 0 ) and m > 2 ) or m == 2):
        sum += 1
    if(m > 2 and m < 8):
        sum -= 1
    print(f"Ngay thu: {sum}")

    

if __name__ == "__main__":
    main()