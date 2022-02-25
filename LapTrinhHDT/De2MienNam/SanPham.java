package de2MienNam;

public class SanPham {
    int maSP;
    String nameSP;
    float donGia;
    String ngaySanXuat;
    int soLuong;

    public SanPham(int maSP, String nameSP, float donGia, String ngaySanXuat, int soLuong) {
        this.maSP = maSP;
        this.nameSP = nameSP;
        this.donGia = donGia;
        this.ngaySanXuat = ngaySanXuat;
        this.soLuong = soLuong;
    }

    public void setNameSP(String nameSP) {
        this.nameSP = nameSP;
    }

    public void setDonGia(float donGia) {
        this.donGia = donGia;
    }

    public void setNgaySanXuat(String ngaySanXuat) {
        this.ngaySanXuat = ngaySanXuat;
    }

    public void setSoLuong(int soLuong) {
        this.soLuong = soLuong;
    }
    
    public void themSoLuong(int soLuong) {
        this.soLuong += soLuong;
    }
    
    public void giamSoLuong(int soLuong) {
        this.soLuong -= soLuong;
    }
    
    public void info() {
        System.out.printf("MaSP: %d, Ten: %s, Don gia: %.1f, NgaySX: %s, So luong: %d", this.maSP, this.nameSP, this.donGia, this.ngaySanXuat, this.soLuong);
        System.out.println("");
    }
}
