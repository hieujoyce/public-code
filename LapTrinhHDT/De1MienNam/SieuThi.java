package de1MienNam;

import java.util.ArrayList;
import java.util.Scanner;

public class SieuThi {
    ArrayList<SanPham> listSanPham = new ArrayList<>();
    ArrayList<KhachHang> listKhachHang = new ArrayList<>();
    ArrayList<HoaDon> listHoaDon = new ArrayList<>();
    Scanner sc = new Scanner(System.in);
    
    public SanPham checkMaSanPham(int maSP) {
        for(int i = 0; i < listSanPham.size(); i++) {
            if(listSanPham.get(i).maSP == maSP) return listSanPham.get(i);
        }
        return null;
    }
    
    public KhachHang checkMaKhackHang(int maKH) {
        for(int i = 0; i < listKhachHang.size(); i++) {
            if(listKhachHang.get(i).maKH == maKH) return listKhachHang.get(i);
        }
        return null;
    }
    
    public void nhapSanPham() {
        System.out.printf("Nhap ma San Pham: ");
        int maSP = sc.nextInt();
        sc.nextLine();
        SanPham sp = checkMaSanPham(maSP);
        if(sp == null) {
            System.out.printf("Nhap ten San Pham: ");
            String tenSP = sc.nextLine();
            System.out.printf("Nhap don Gia San Pham: ");
            float donGia = sc.nextFloat();
            sc.nextLine();
            System.out.printf("Nhap ngay san xuat: ");
            String ngaySanXuat = sc.nextLine();
            System.out.printf("Nhap so luong San Pham: ");
            int soLuong = sc.nextInt();
            sc.nextLine();
            SanPham newSP = new SanPham(maSP, tenSP, donGia, ngaySanXuat, soLuong);
            listSanPham.add(newSP);
        } else {
            System.out.printf("Nhap so luong San Pham: ");
            int soLuong = sc.nextInt();
            sc.nextLine();
            sp.themSoLuong(soLuong);
        }
    }
    
    public void inAllSanPham() {
        for(int i = 0; i < listSanPham.size(); i++) {
            listSanPham.get(i).info();
        }
    }
    
    public void dangKiKhachHang() {
        System.out.printf("Nhap ma Khach Hang: ");
        int maKH = sc.nextInt();
        sc.nextLine();
        System.out.printf("Nhap ten Khach Hang: ");
        String tenKH = sc.nextLine();
        System.out.printf("Nhap nam sinh Khach Hang: ");
        int namSinh = sc.nextInt();
        sc.nextLine();
        DiaChi diaChi = new DiaChi();
        diaChi.nhap();
        KhachHang newKh = new KhachHang(maKH, tenKH, namSinh, diaChi);
        listKhachHang.add(newKh);
    }
    
    public void suaInForKhachHang() {
        System.out.printf("Nhap ma Khach Hang muon sua: ");
        int maKH = sc.nextInt();
        sc.nextLine();
        KhachHang kh = checkMaKhackHang(maKH);
        if(kh == null) {
            System.out.println("-> Khong co Ma KH nay!!");
            return;
        }
        System.out.printf("Nhap ten Khach Hang: ");
        String tenKH = sc.nextLine();
        System.out.printf("Nhap nam sinh Khach Hang: ");
        int namSinh = sc.nextInt();
        sc.nextLine();
        kh.setTenKH(tenKH);
        kh.setNamSinh(namSinh);
    }
    
    public KhachHang dangNhapKhachHang() {
        System.out.printf("Dang nhap voi ma Khach Hang: ");
        int maKH = sc.nextInt();
        sc.nextLine();
        KhachHang kh = checkMaKhackHang(maKH);
        while (kh == null) {
            System.out.println("Dang nhap sai. -> Moi dang nhap lai.");
            System.out.printf("Dang nhap voi ma Khach Hang: ");
            maKH = sc.nextInt();
            sc.nextLine();
            kh = checkMaKhackHang(maKH);
        }
        return kh;
    }
    
    public void khachHangMuaHang() {
        KhachHang kh = dangNhapKhachHang();
        HoaDon newHD = new HoaDon(kh);
        int choice = -1;
        do {
            this.inAllSanPham();
            System.out.printf("Nhap maSP muon mua hoac an 0 de thoat Mua Hang: ");
            choice = sc.nextInt();
            sc.nextLine();
            if(choice == 0) break;
            SanPham sp = checkMaSanPham(choice);
            if(sp == null) {
                System.out.println("Hay nhap dung maSP");
                break;
            }
            System.out.printf("Nhap so luong mua: ");
            int soLuongMua = sc.nextInt();
            if(soLuongMua > sp.soLuong) {
                System.out.println("So luong SP nay khong du");
                break;
            }
            sp.giamSoLuong(soLuongMua);
            newHD.add(sp, soLuongMua);
        } while (choice != 0);
        if(!newHD.listHDTungSP.isEmpty()) {
            listHoaDon.add(newHD);
            newHD.info();
            newHD.kh.setTongTienMuaHang(newHD.tinhTongTienHoaDon());
        }
    }
    
    public void inAllHoaDon() {
        for(int i = 0; i < listHoaDon.size(); i++) {
            listHoaDon.get(i).info();
        }
    }
    
    public void inAllKhachHang() {
        for(int i = 0; i < listKhachHang.size(); i++) {
            listKhachHang.get(i).info();
        }
    }
    
    public void inAllKhachHangSapXep() {
        listKhachHang.sort((n, m) -> (int)(n.tongTienMuaHang - m.tongTienMuaHang) );
        for(int i = 0; i < listKhachHang.size(); i++) {
            System.out.printf("Ten: %s, Tong Tien: %.1f",listKhachHang.get(i).tenKH, listKhachHang.get(i).tongTienMuaHang);
            System.out.println("");
        }
    }   
}
