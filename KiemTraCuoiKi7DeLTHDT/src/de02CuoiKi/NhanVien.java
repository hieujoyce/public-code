package de02CuoiKi;

public class NhanVien extends Person {
    protected String phongBan;
    protected float heSoLuong;
    protected int thamNien;
    protected float luongCoBan;

    public NhanVien(String hoTen, String ngaySinh, String diaChi, String gioiTinh, String phongBan, float hsl, int thamNien, float luongCoBan) {
        super(hoTen, ngaySinh, diaChi, gioiTinh);
        this.phongBan = phongBan;
        this.heSoLuong = heSoLuong;
        this.thamNien = thamNien;
        this.luongCoBan = luongCoBan;
    }

    public NhanVien() {
    }
    
    
    
    public float tinhLuongThucLinh() {
        return luongCoBan * heSoLuong * (1 + (float)thamNien/100);
    }

    @Override
    public String toString() {
        return super.toString() + ", Phong Ban: " + phongBan + ", He So Luong: " + heSoLuong + ", Tham Nien: " + thamNien + ", Luong Co Ban: " + luongCoBan;
    }
    
    
}
