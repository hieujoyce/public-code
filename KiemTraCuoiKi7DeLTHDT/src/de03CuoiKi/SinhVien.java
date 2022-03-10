package de03CuoiKi;

public class SinhVien {
    protected String maSV;
    protected String hoTen;
    protected String ngaySinh;
    protected String gioiTinh;
    protected float diemTb;

    public SinhVien(String maSV, String hoTen, String ngaySinh, String gioiTinh, float diemTb) {
        this.maSV = maSV;
        this.hoTen = hoTen;
        this.ngaySinh = ngaySinh;
        this.gioiTinh = gioiTinh;
        this.diemTb = diemTb;
    }

    public SinhVien() {
    }

    @Override
    public String toString() {
        return "MaSV: " + maSV + ", Ho Ten: " + hoTen + ", Ngay Sinh: " + ngaySinh + ", Gioi Tinh: " + gioiTinh + ", DiemTb: " + diemTb;
    }
    
    
}
