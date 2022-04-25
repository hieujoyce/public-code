from functools import reduce
from tabnanny import check

def totalDigitsOfNumber(n):
    result = reduce( lambda x, y: int(x) + int(y) ,list(str(n)) )
    return result


def main():
    while True:
        sin = input("SIN (0 de thoat): ")
        if(sin == "0"):
            break
        checkDigit = int( sin[len(sin) - 1] )
        newSin = sin[:len(sin) - 1]
        s1 = reduce(lambda x, y: int(x) + int(y), list( newSin[0::2] ))
        listS2 = newSin[1::2]
        listS2 = list(map(lambda x: totalDigitsOfNumber(int(x) * 2) , listS2))
        s2 = reduce(lambda x, y: int(x) + int(y), listS2)
        if((s1 + s2 + checkDigit) % 10 == 0):
            print("Sin hop le")
        else:
            print("Sin khong hop le")


if __name__ == "__main__":
    main()