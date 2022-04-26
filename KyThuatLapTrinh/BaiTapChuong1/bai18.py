def main():
    t = int(input("Nhap so gio: "))
    gio = t % 24
    ngay = (t // 24) % 7
    tuan = (t // 24) // 7
    print(f"{tuan} tuan, {ngay} ngay, {gio} gio")

if __name__ == "__main__":
    main()