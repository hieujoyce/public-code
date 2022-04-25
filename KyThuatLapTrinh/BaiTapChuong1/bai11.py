import random

def checkWin(myChoice, computerChoice):
    if(myChoice == "b"):
        if(computerChoice == "d"):
            return 1
        elif(computerChoice == "k"):
            return -1
    elif(myChoice == "d"):
        if(computerChoice == "k"):
            return 1
        elif(computerChoice == "b"):
            return -1
    else:
        if(computerChoice == "b"):
            return 1
        elif(computerChoice == "d"):
            return -1
    return 0


def main():
    listChoices = ["b", "d", "k"]
    choice = "b"
    myScore = 0
    comScore = 0
    while (choice == "b" or choice == "d" or choice == "k"):
        choice = input("Nhap ky tu (b-d-k), ky tu khac de thoat: ")
        computerChoice = random.choice(listChoices)
        print(f"Computer: {computerChoice}")
        if(checkWin(choice, computerChoice) == 1):
            myScore += 1
        elif(checkWin(choice, computerChoice) == -1):
            comScore += 1
        print(f"Ty so human - computer: {myScore} - {comScore}")
    

if __name__ == "__main__":
    main()