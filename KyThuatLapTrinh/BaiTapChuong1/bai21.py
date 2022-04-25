import math

def main():
    diemChuan = float(input("Nhap diem chuan: "))
    diemToan, diemVan, diemAnh = map(lambda x: float(x), input("Nhap diem 3 mon thi(Toan, Van, Anh): ").split())
    tongDiem = diemToan + diemVan + diemAnh
    khuVuc = input("Nhap khu vuc (A, B, C, X): ")
    if(khuVuc == "A"):
        tongDiem += 2
    elif(khuVuc == "B"):
        tongDiem += 1
    elif(khuVuc == "C"):
        tongDiem += 0.5
    doiTuong = input("Nhap doi tuong (1, 2, 3, 0): ")
    if(doiTuong == "1"):
        tongDiem += 2.5
    elif(doiTuong == "2"):
        tongDiem += 1.5
    elif(doiTuong == "3"):
        tongDiem += 1
    s = "DO" if tongDiem >= diemChuan else "ROT"
    print(f"{s} [{tongDiem}]")

    

if __name__ == "__main__":
    main()