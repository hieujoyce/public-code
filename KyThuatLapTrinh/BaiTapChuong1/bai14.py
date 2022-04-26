def tomorrow(d, m, y):
    if(m == 4 or m == 6 or m == 9 or m == 11):
        dayOfMonth = 30
    elif(m == 2):
        dayOfMonth = 28 + int( ( y % 4 == 0 and y % 100 != 0 ) or y % 400 == 0)
    else:
        dayOfMonth = 31
    if(d + 1 <= dayOfMonth):
        dayOfTomorrow = d + 1
        monthOfTomorrow = m
        yearOfTomorrow = y
    elif(d + 1 > dayOfMonth and m != 12):
        dayOfTomorrow = 1
        monthOfTomorrow = m + 1
        yearOfTomorrow = y
    elif(d + 1 > dayOfMonth and m == 12):
        dayOfTomorrow = 1
        monthOfTomorrow = 1
        yearOfTomorrow = y + 1
    return str(dayOfTomorrow) + "/" + str(monthOfTomorrow) + "/" + str(yearOfTomorrow)

def main():
    d, m, y = map(lambda x: int(x), input("Nhap ngay, thang va nam: ").split())
    print(f"Ngay mai: {tomorrow(d, m, y)}")
    

if __name__ == "__main__":
    main()