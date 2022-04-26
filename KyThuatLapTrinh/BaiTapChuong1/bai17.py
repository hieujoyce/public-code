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

def printMonth(m, dayBegin, y, stt, boolen):
    if dayBegin == 7:
        dayBegin = 0
    d = daysOfMonth(m, y)
    list = [(i + 1) for i in range(d)]
    for i in range(dayBegin):
        list.insert(0, " ")
    if(boolen == True):
        print(f"Thang {m}")
    l = ["Sun", "Mon", "Tue", "Wen", "Thu", "Fri", "Sat"]
    l1 = ["A", "B", "C", "D", "E"]
    if boolen == True:
        for i in range(7):
            print("%7s" %(l[i]), end="")
    if(boolen == True):
        print("")
    dem = 0
    dem1 = stt
    while True:
        for i in range(7):
            if boolen == True:
                if i != 0 and list[dem] != " ":
                    print("%3s [%s]" %(list[dem], l1[dem1]), end="")
                else:
                    print("%3s [ ]" %(list[dem]), end="")
            if(list[dem] != " " and i != 0):
                dem1 = dem1 + 1 if ((dem1 + 1) < len(l1)) else 0
            dem += 1
            if(dem >= len(list)):
                return [i + 1, dem1]
        if(boolen == True):
            print("")


def main():
    y = int(input("Nhap nam: "))
    m = int(input("Nhap thang: "))
    dayBegin = zeller(1, 1, y)
    if (m == 1):
        printMonth(1, dayBegin, y, 0, True)
    else:
        dayBegin, stt = printMonth(1, dayBegin, y, 0, False)
        for i in range(2, m + 1):
            if(i == m):
                dayBegin, stt = printMonth(i, dayBegin, y, stt, True)
                print("")
            else:
                dayBegin, stt = printMonth(i, dayBegin, y, stt, False)



if __name__ == "__main__":
    main()