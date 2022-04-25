def checkHopLe(d, m, y):
    if(y < 1582):
        return False
    if(m < 1 or m > 12):
        return False
    if(m == 4 or m == 6 or m == 9 or 11):
        dayOfMonth = 30
    elif(m == 2):
        dayOfMonth = 28 + int( ( y % 4 == 0 and y % 100 != 0 ) or y % 400 == 0)
    else:
        dayOfMonth = 31
    if(d < 1 or d > dayOfMonth):
        return False
    return True

def main():
    d, m, y = map(lambda x: int(x), input("Nhap ngay, thang va nam: ").split())
    if(checkHopLe(d, m, y) == True):
        print("Hop le")
        a = (14 - m) / 12
        y = y - a
        m = m + 12 * a -2
        dayOfWeek = int(d + y + y/4 - y/100 + y/400 + (31*m)/12) % 7
        if(dayOfWeek == 0):
            print("Chu nhat")
        else:
            print(f"Thu {dayOfWeek + 1}")
    else:
        print("Khong hop le")
    

if __name__ == "__main__":
    main()