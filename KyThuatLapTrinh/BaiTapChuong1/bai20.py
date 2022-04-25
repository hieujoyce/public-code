import math
from sys import flags

def main():
    soDien = float(input("Nhap so kW tieu thu: "))
    if(soDien >= 0 and soDien < 100):
        chiPhi = soDien * 500
    elif(soDien >= 100 and soDien < 250):
        chiPhi = 100 * 500 + (soDien - 100) * 800
    elif(soDien >= 250 and soDien < 350):
        chiPhi = 100 * 500 + 150 * 800 + (soDien - 250) * 1000
    elif(soDien >= 350):
        chiPhi = 100 * 500 + 150 * 800 + 100 * 1000 + (soDien - 350) * 1500
    
    print(f"Chi phi: {chiPhi}")

    

if __name__ == "__main__":
    main()