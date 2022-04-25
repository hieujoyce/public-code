import math

def main():
    gio1, phut1, giay1 = map(lambda x: int(x), input("Nhap gio, phut, giay [1]: ").split())
    gio2, phut2, giay2 = map(lambda x: int(x), input("Nhap gio, phut, giay [2]: ").split())

    if(gio1 > gio2 or (gio1 == gio2 and phut1 > phut2) or (gio1 == gio2 and phut1 == phut2 and giay1 > giay2) ):
        gio1, gio2 = gio2, gio1
        phut1, phut2 = phut2, phut1
        giay1, giay2 = giay2, giay1

    bienNho = 0
    if(giay2 >= giay1):
        giay = giay2 - giay1
        bienNho = 0
    else:
        giay = giay2 + 60 - giay1
        bienNho = 1
    if(phut2 >= phut1 + bienNho):
        phut = phut2 - (phut1 + bienNho)
        bienNho = 0
    else:
        phut = phut2 + 60 - (phut1 + bienNho)
        bienNho = 1
    gio = gio2 - (gio1 + bienNho)
    print(f"Hieu thoi gian: {gio} gio {phut} phut, {giay} giay")


    

if __name__ == "__main__":
    main()