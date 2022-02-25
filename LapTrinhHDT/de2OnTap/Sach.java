package de2OnTap;

import java.util.Scanner;

public class Sach extends TaiLieu {
    private String tenTacGia;
    private int soTrang;

    public String getTenTacGia() {
        return tenTacGia;
    }

    public void setTenTacGia(String tenTacGia) {
        this.tenTacGia = tenTacGia;
    }

    public int getSoTrang() {
        return soTrang;
    }

    public void setSoTrang(int soTrang) {
        this.soTrang = soTrang;
    }

    public Sach(String tenTacGia, int soTrang, String maTaiLieu, String tenNhaSX, int soBanPhatHanh) {
        super(maTaiLieu, tenNhaSX, soBanPhatHanh);
        this.tenTacGia = tenTacGia;
        this.soTrang = soTrang;
    }

    public Sach() {
    }
    
    public void nhap() {
        super.nhap();
        Scanner sc = new Scanner(System.in);
        System.out.printf("Nhap Ten Tac Gia: ");
        this.tenTacGia = sc.nextLine();
        System.out.printf("Nhap So Trang: ");
        this.soTrang = sc.nextInt();
        sc.nextLine();
    }

    @Override
    public String toString() {
        return "Sach: " + super.toString() + ", tenTacGia=" + tenTacGia + ", soTrang=" + soTrang;
    }
    
    
    
}
