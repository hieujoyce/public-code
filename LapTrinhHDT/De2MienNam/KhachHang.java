package de2MienNam;

public class KhachHang {
    int maKH;
    String tenKH;
    int namSinh;
    DiaChi diaChi;
    float tongTienMuaHang;

    public KhachHang(int maKH, String tenKH, int namSinh, DiaChi diaChi) {
        this.maKH = maKH;
        this.tenKH = tenKH;
        this.namSinh = namSinh;
        this.diaChi = diaChi;
        this.tongTienMuaHang = 0;
    }

    public void setTongTienMuaHang(float tongTienMuaHang) {
        this.tongTienMuaHang += tongTienMuaHang;
    }

    public String getTenKH() {
        return tenKH;
    }

    public void setTenKH(String tenKH) {
        this.tenKH = tenKH;
    }

    public int getNamSinh() {
        return namSinh;
    }

    public void setNamSinh(int namSinh) {
        this.namSinh = namSinh;
    }
    
    public void info() {
        System.out.printf("MaKH: %d, Ten: %s, NamSinh: %d, DiaChi: %s", this.maKH, this.tenKH, this.namSinh, this.diaChi.info());
        System.out.println("");
    }
}
