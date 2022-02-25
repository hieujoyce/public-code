package deSo07;

import java.util.Scanner;

public abstract class ThiSinh {
    protected String hoTen;
    protected String ngaySinh;
    protected String diaChi;

    public ThiSinh() {
    }

    public ThiSinh(String hoTen, String ngaySinh, String diaChi) {
        this.hoTen = hoTen;
        this.ngaySinh = ngaySinh;
        this.diaChi = diaChi;
    }
    
    public void nhap() {
        Scanner sc = new Scanner(System.in);
        System.out.printf("Nhap ho ten: ");
        hoTen = sc.nextLine();
        System.out.printf("Nhap ngay sinh: ");
        ngaySinh = sc.nextLine();
        System.out.printf("Nhap dia chi: ");
        diaChi = sc.nextLine();
    }

    @Override
    public String toString() {
        return "Thong tin: " + "hoTen=" + hoTen + ", ngaySinh=" + ngaySinh + ", diaChi=" + diaChi;
    }
    
    abstract float getTongDiem();
}
