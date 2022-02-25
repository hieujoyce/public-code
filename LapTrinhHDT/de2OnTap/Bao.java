package de2OnTap;

import java.util.Scanner;

public class Bao extends TaiLieu {
    private int ngayPhatHanh;

    public int getNgayPhatHanh() {
        return ngayPhatHanh;
    }

    public void setNgayPhatHanh(int ngayPhatHanh) {
        this.ngayPhatHanh = ngayPhatHanh;
    }

    public Bao(int ngayPhatHanh, String maTaiLieu, String tenNhaSX, int soBanPhatHanh) {
        super(maTaiLieu, tenNhaSX, soBanPhatHanh);
        this.ngayPhatHanh = ngayPhatHanh;
    }

    public Bao(int ngayPhatHanh) {
        this.ngayPhatHanh = ngayPhatHanh;
    }  

    public Bao() {
    }
    
    public void nhap() {
        super.nhap();
        Scanner sc = new Scanner(System.in);
        System.out.printf("Nhap So Ngay Phat Hanh: ");
        this.ngayPhatHanh = sc.nextInt();
        sc.nextLine();
    }

    @Override
    public String toString() {
        return "Bao: " + super.toString() + ", ngayPhatHanh=" + ngayPhatHanh;
    }
}
