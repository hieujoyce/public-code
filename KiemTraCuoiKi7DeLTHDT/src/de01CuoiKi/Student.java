package de01CuoiKi;

public class Student extends Person {
    protected String maSV;
    protected String email;
    protected float diemTK;

    public Student(String maSV, String email, float diemTK, String hoTen, String ngaySinh, String diaChi, String gioiTinh) {
        super(hoTen, ngaySinh, diaChi, gioiTinh);
        this.maSV = maSV;
        this.email = email;
        this.diemTK = diemTK;
    }

    public Student() {
    }

    @Override
    public String toString() {
        return super.toString() + "MaSV: " + maSV + ", Email: " + email + ", DiemTK: " + diemTK;
    }   
}
