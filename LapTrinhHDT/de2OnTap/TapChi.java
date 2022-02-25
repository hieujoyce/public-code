package de2OnTap;

import java.util.Scanner;

public class TapChi extends TaiLieu {
    private int soPhatHanh, thangPhatHanh;

    public TapChi() {
    }

    public int getSoPhatHanh() {
        return soPhatHanh;
    }

    public void setSoPhatHanh(int soPhatHanh) {
        this.soPhatHanh = soPhatHanh;
    }

    public int getThangPhatHanh() {
        return thangPhatHanh;
    }

    public void setThangPhatHanh(int thangPhatHanh) {
        this.thangPhatHanh = thangPhatHanh;
    }

    public TapChi(int soPhatHanh, int thangPhatHanh, String maTaiLieu, String tenNhaSX, int soBanPhatHanh) {
        super(maTaiLieu, tenNhaSX, soBanPhatHanh);
        this.soPhatHanh = soPhatHanh;
        this.thangPhatHanh = thangPhatHanh;
    }
    
    public void nhap() {
        super.nhap();
        Scanner sc = new Scanner(System.in);
        System.out.printf("Nhap So Phat Hanh: ");
        this.soPhatHanh = sc.nextInt();
        sc.nextLine();
        System.out.printf("Nhap Thang Phat Hanh: ");
        this.thangPhatHanh = sc.nextInt();
        sc.nextLine();
    }

    @Override
    public String toString() {
        return "Tap chi: " + super.toString() + ", soPhatHanh=" + soPhatHanh + ", thangPhatHanh=" + thangPhatHanh;
    }
    
}
