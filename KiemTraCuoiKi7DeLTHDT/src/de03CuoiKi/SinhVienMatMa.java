package de03CuoiKi;

public class SinhVienMatMa extends SinhVien {
    protected String donVi;
    protected float luong;

    public SinhVienMatMa(String donVi, float luong, String maSV, String hoTen, String ngaySinh, String gioiTinh, float diemTb) {
        super(maSV, hoTen, ngaySinh, gioiTinh, diemTb);
        this.donVi = donVi;
        this.luong = luong;
    }

    public SinhVienMatMa() {
    }

    @Override
    public String toString() {
        return super.toString() + ", DonVi: " + donVi + ", Luong: " + luong;
    }
    
    
}
