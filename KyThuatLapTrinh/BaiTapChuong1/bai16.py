def zeller(d, m, y):
    a = (14 - m) // 12
    y = y - a
    m = m + 12 * a -2
    dayOfWeek = int(d + y + y//4 - y//100 + y//400 + (31*m)//12) % 7
    return dayOfWeek

def daysOfMonth(m, y):
    if(m == 4 or m == 6 or m == 9 or m == 11):
        return 30
    elif(m == 2):
        return (28 + int( ( y % 4 == 0 and y % 100 != 0 ) or y % 400 == 0))
    else:
        return 31

def printMonth(m, dayBegin, y):
    if dayBegin == 7:
        dayBegin = 0
    d = daysOfMonth(m, y)
    list = [(i + 1) for i in range(d)]
    for i in range(dayBegin):
        list.insert(0, " ")
    print(f"Thang {m}")
    l = ["S", "M", "T", "W", "T", "F", "S"]
    for i in range(7):
        print("%3s" %(l[i]), end="")
    print("")
    dem = 0
    while True:
        for i in range(7):
            print("%3s" %(list[dem]), end="")
            dem += 1
            if(dem >= len(list)):
                return i + 1
        print("")


def main():
    y = int(input("Nhap nam: "))
    dayBegin = zeller(1, 1, y)
    dayBegin = printMonth(1, dayBegin, y)
    print("")
    for i in range(2, 13):
        dayBegin = printMonth(i, dayBegin, y)
        print("")

if __name__ == "__main__":
    main()