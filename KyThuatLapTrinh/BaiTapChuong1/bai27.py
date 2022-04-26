def phanTichSoNguyen(n):
    i = 2
    listNumbers = []
    while (n > 1):
        if (n % i == 0):
            n = int(n / i)
            listNumbers.append(i)
        else:
            i = i + 1
    if (len(listNumbers) == 0):
        listNumbers.append(n)
    return listNumbers

def main():
    n = int(input("Nhap n: "))
    listNumbers = phanTichSoNguyen(n)
    size = len(listNumbers)
    sb = ""
    for i in range(0, size - 1):
        sb = sb + str(listNumbers[i]) + " * "
    sb = sb + str(listNumbers[size-1])
    print(sb)

if __name__ == "__main__":
    main()