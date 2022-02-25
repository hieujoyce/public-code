package de2OnTap;

import java.util.Scanner;

public class TaiLieu {
    private String maTaiLieu;
    private String tenNhaSX;
    private int soBanPhatHanh;

    public String getMaTaiLieu() {
        return maTaiLieu;
    }

    public void setMaTaiLieu(String maTaiLieu) {
        this.maTaiLieu = maTaiLieu;
    }

    public String getTenNhaSX() {
        return tenNhaSX;
    }

    public void setTenNhaSX(String tenNhaSX) {
        this.tenNhaSX = tenNhaSX;
    }

    public int getSoBanPhatHanh() {
        return soBanPhatHanh;
    }

    public void setSoBanPhatHanh(int soBanPhatHanh) {
        this.soBanPhatHanh = soBanPhatHanh;
    }

    public TaiLieu(String maTaiLieu, String tenNhaSX, int soBanPhatHanh) {
        this.maTaiLieu = maTaiLieu;
        this.tenNhaSX = tenNhaSX;
        this.soBanPhatHanh = soBanPhatHanh;
    }

    public TaiLieu() {
    }
    
    public void nhap() {
        Scanner sc = new Scanner(System.in);
        System.out.println("-> Nhap tai lieu: ");
        System.out.printf("Nhap Ma Tai Lieu: ");
        this.maTaiLieu = sc.nextLine();
        System.out.printf("Nhap Nha San Xuat: ");
        this.tenNhaSX = sc.nextLine();
        System.out.printf("Nhap So Ban Phat Hanh: ");
        this.soBanPhatHanh = sc.nextInt();
        sc.nextLine();
    }

    @Override
    public String toString() {
        return "maTaiLieu=" + maTaiLieu + ", tenNhaSX=" + tenNhaSX + ", soBanPhatHanh=" + soBanPhatHanh;
    }
    
    
    
}
