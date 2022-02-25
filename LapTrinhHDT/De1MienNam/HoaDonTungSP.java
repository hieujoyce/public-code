package de1MienNam;

public class HoaDonTungSP {
    SanPham sp;
    int soLuongMua;
    float tongTien1SP;

    public HoaDonTungSP(SanPham sp, int soLuongMua) {
        this.sp = sp;
        this.soLuongMua = soLuongMua;
        this.tongTien1SP = this.sp.donGia * soLuongMua;
    }
    
    public void info() {
        System.out.printf("TenSP: %s, soLuong: %d, TongTien: %.1f", this.sp.nameSP, this.soLuongMua, this.tongTien1SP);
        System.out.println("");
    }
}
