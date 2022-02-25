package deSo05;

public class NhanVien extends Person {
    protected String maNhanVien;
    protected float heSoLuong;
    protected String donVi;

    public NhanVien(String maNhanVien, float heSoLuong, String donVi, String hoTen, String ngaySinh, String diaChi, String gioiTinh) {
        super(hoTen, ngaySinh, diaChi, gioiTinh);
        this.maNhanVien = maNhanVien;
        this.heSoLuong = heSoLuong;
        this.donVi = donVi;
    }

    public NhanVien() {
    }

    @Override
    public String toString() {
        return super.toString() + ", maNhanVien=" + maNhanVien + ", heSoLuong=" + heSoLuong + ", donVi=" + donVi;
    }
    
}
