package deSo07;

import java.util.Scanner;

public class ThiSinhKhoiC extends ThiSinh{
    protected float diemVan;
    protected float diemSu;
    protected float diemDia;

    public ThiSinhKhoiC() {
    }

    public ThiSinhKhoiC(float diemVan, float diemSu, float diemDia, String hoTen, String ngaySinh, String diaChi) {
        super(hoTen, ngaySinh, diaChi);
        this.diemVan = diemVan;
        this.diemSu = diemSu;
        this.diemDia = diemDia;
    }

    @Override
    public String toString() {
        return super.toString() + ", diemVan=" + diemVan + ", diemSu=" + diemSu + ", diemDia=" + diemDia;
    }

    
    
    @Override
    public void nhap() {
        super.nhap();
        Scanner sc = new Scanner(System.in);
        System.out.printf("Nhap diem Van: ");
        diemVan = sc.nextFloat();
        System.out.printf("Nhap diem Su: ");
        diemSu = sc.nextFloat();
        System.out.printf("Nhap diem Dia: ");
        diemDia = sc.nextFloat();
        sc.nextLine();
    }

    @Override
    float getTongDiem() {
        return diemDia + diemSu + diemVan;
    }
    
}
