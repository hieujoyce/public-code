package de05CuoiKi;

import java.util.Scanner;

public class ThiSinhKhoiC extends ThiSinh {
    protected float diemVan;
    protected float diemSu;
    protected float diemDia;

    @Override
    public void toStrings() {
        //return "Ho Ten: " + hoTen + ", Ngay Sinh: " + ngaySinh + ", DiaChi: " + diaChi + ", Diem Van: " + diemVan + ", Diem Su, " + diemSu + ", Diem Dia: " + diemDia;
        System.out.printf("| %-30s| %-12s| %-20s| %-12.2f| %-12.2f| %-12.2f|", hoTen, ngaySinh, diaChi, diemVan, diemSu, diemDia);
    }

    public ThiSinhKhoiC(float diemVan, float diemSu, float diemDia, String hoTen, String ngaySinh, String diaChi) {
        super(hoTen, ngaySinh, diaChi);
        this.diemVan = diemVan;
        this.diemSu = diemSu;
        this.diemDia = diemDia;
    }

    public ThiSinhKhoiC() {
    }
    
    
    
    @Override
    public boolean nhap() {
        super.nhap(); //To change body of generated methods, choose Tools | Templates.
        Scanner sc = new Scanner(System.in);
        
        try {
            System.out.printf("Nhap diem Van: ");
            diemVan = sc.nextFloat();
            while(diemVan < 0 || diemVan > 10) {
                System.out.println("Hay nhap diem Van trong khoang [0, 10]");
                System.out.printf("Nhap lai diem Van: ");
                diemVan = sc.nextFloat();
            }
            
            System.out.printf("Nhap diem Su: ");
            diemSu = sc.nextFloat();
            while(diemSu < 0 || diemSu > 10) {
                System.out.println("Hay nhap diem Su trong khoang [0, 10]");
                System.out.printf("Nhap lai diem Su: ");
                diemSu = sc.nextFloat();
            }
            
            System.out.printf("Nhap diem Dia: ");
            diemDia = sc.nextFloat();
            while(diemDia < 0 || diemDia > 10) {
                System.out.println("Hay nhap diem Dia trong khoang [0, 10]");
                System.out.printf("Nhap lai diem Dia: ");
                diemDia = sc.nextFloat();
            }
            
        } catch (Exception e) {
            System.out.println("Lỗi: lỗi định dạng input");
            return false;
        }
        
        return true;
    }

    @Override
    String getKhoi() {
        return "C";
    }

    @Override
    float getTongDiem() {
        return diemDia + diemSu + diemVan;
    }
}
