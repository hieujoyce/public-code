package de03CuoiKi;

public class SinhVienATTT extends SinhVien {
    protected float hocPhi;

    public SinhVienATTT(float hocPhi, String maSV, String hoTen, String ngaySinh, String gioiTinh, float diemTb) {
        super(maSV, hoTen, ngaySinh, gioiTinh, diemTb);
        this.hocPhi = hocPhi;
    }

    public SinhVienATTT() {
    }

    @Override
    public String toString() {
        return super.toString() + ", Hoc Phi: " + hocPhi;
    }
    
}
