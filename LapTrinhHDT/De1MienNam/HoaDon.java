package de1MienNam;

import java.util.ArrayList;

public class HoaDon {
    KhachHang kh;
    ArrayList<HoaDonTungSP> listHDTungSP = new ArrayList<>();
    
    public void add(SanPham maSP, int soLuongMua) {
        HoaDonTungSP a = new HoaDonTungSP(maSP, soLuongMua);
        listHDTungSP.add(a);
    }

    public HoaDon(KhachHang kh) {
        this.kh = kh;
    }
    
    public float tinhTongTienHoaDon() {
        float result = 0;
        for(int i = 0; i < listHDTungSP.size(); i++) {
            result += listHDTungSP.get(i).tongTien1SP;
        }
        return result;
    }
    
    public void info() {
        System.out.println("=========Thong tin Hoa Don=========");
        System.out.println("Ten KH: " + this.kh.tenKH);
        for(int i = 0; i < listHDTungSP.size(); i++) {
            listHDTungSP.get(i).info();
        }
        System.out.printf("-> Tong tien Hoa Don: %.1f", tinhTongTienHoaDon());
        System.out.println("");
    }
}
