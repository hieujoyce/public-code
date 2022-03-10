/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package de07CuoiKi;

/**
 *
 * @author Laptop88
 */
public class GiangVien extends NhanVien {
    static int ids = 1;
    protected String maGiangVien;
    protected String diaChi;
    protected String gioiTinh;
    protected String khoa;

    public GiangVien(String maGiangVien, String diaChi, String gioiTinh, String khoa, String hoTen) {
        super(hoTen);
        this.id = ids++;
        this.maGiangVien = maGiangVien;
        this.diaChi = diaChi;
        this.gioiTinh = gioiTinh;
        this.khoa = khoa;
    }

    public GiangVien() {
        this.id = ids++;
    }

    public String getMaGiangVien() {
        return maGiangVien;
    }

    public void setMaGiangVien(String maGiangVien) {
        this.maGiangVien = maGiangVien;
    }

    public String getDiaChi() {
        return diaChi;
    }

    public void setDiaChi(String diaChi) {
        this.diaChi = diaChi;
    }

    public String getGioiTinh() {
        return gioiTinh;
    }

    public void setGioiTinh(String gioiTinh) {
        this.gioiTinh = gioiTinh;
    }

    public String getKhoa() {
        return khoa;
    }

    public void setKhoa(String khoa) {
        this.khoa = khoa;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getHoTen() {
        return hoTen;
    }

    public void setHoTen(String hoTen) {
        this.hoTen = hoTen;
    }
    
    

    @Override
    public String toString() {
        return super.toString() + ", maGiangVien: " + maGiangVien + ", diaChi: " + diaChi + ", gioiTinh: " + gioiTinh + ", khoa: " + khoa;
    }
    
    
}
