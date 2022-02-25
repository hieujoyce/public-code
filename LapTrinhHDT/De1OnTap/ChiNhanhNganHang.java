package deOnTap;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.Scanner;

public class ChiNhanhNganHang {
    String maChiNhanh;
    String tenChiNhanh;
    DiaChi diaChi;
    ArrayList<KhachHang> listKhachHang = new ArrayList<>();
    Scanner sc = new Scanner(System.in);
    
    
    public void nhap() {
        System.out.println("-> Khai bao chi nhanh Ngan Hang:");
        System.out.printf("Nhap Ma chi nhanh: ");
        this.maChiNhanh = sc.nextLine();
        System.out.printf("Nhap Ten chi nhanh: ");
        this.tenChiNhanh = sc.nextLine();
        this.diaChi = new DiaChi();
        this.diaChi.nhap();
    }
    
    public void hienThiDanhSachKH() {
        System.out.println("Dach sach Khach Hang(maKH): ");
        for(int i = 0; i < this.listKhachHang.size(); i++) {
            System.out.println("    +) " + this.listKhachHang.get(i).maKhachHang);
        }
    }
    
    public KhachHang checkMaKhackHang(String maKH) {
        for(int i = 0; i < listKhachHang.size(); i++) {
            if(this.listKhachHang.get(i).maKhachHang.equals(maKH)) return this.listKhachHang.get(i);
        }
        return null;
    }
    
    public TaiKhoanNganHang checkTaiKhoan(KhachHang kh, String soTK) {
        for(int i = 0; i < kh.listTKNH.size(); i++) {
            if(kh.listTKNH.get(i).soTK.equals(soTK)) return kh.listTKNH.get(i);
        }
        return null;
    }
    
    public void themKH() {
        KhachHang newKh = new KhachHang();
        newKh.nhap();
        this.listKhachHang.add(newKh);
        System.out.println("-> Da them KH");
    }
    
    public void themTKChoKH() {
        this.hienThiDanhSachKH();
        System.out.printf("Nhap Ma KH muon them tk: ");
        String maKH = sc.nextLine();
        KhachHang kh = checkMaKhackHang(maKH);
        if(kh == null) {
            System.out.println("-> Khong tim thay KH co maKH nay!!");
            return;
        }
        TaiKhoanNganHang newTK = new TaiKhoanNganHang();
        newTK.nhap();
        kh.listTKNH.add(newTK);
        System.out.println("-> Da them Tk");
    }
    
    public void hienThiInfo1KH() {
        this.hienThiDanhSachKH();
        System.out.printf("Nhap Ma KH muon hien thi: ");
        String maKH = sc.nextLine();
        KhachHang kh = checkMaKhackHang(maKH);
        if(kh == null) {
            System.out.println("-> Khong tim thay KH co maKH nay!!");
            return;
        }
        kh.hienThi();
    }
    
    public void guiRutTien() {
        this.hienThiDanhSachKH();
        System.out.printf("Nhap Ma KH muon hien thi: ");
        String maKH = sc.nextLine();
        KhachHang kh = checkMaKhackHang(maKH);
        if(kh == null) {
            System.out.println("-> Khong tim thay KH co maKH nay!!");
            return;
        }
        kh.hienThiDanhSachTK();
        System.out.printf("Nhap so tai khoan muon thuc hien giao dich: ");
        String soTK = sc.nextLine();
        TaiKhoanNganHang tk = checkTaiKhoan(kh, soTK);
        if(tk == null) {
            System.out.println("-> Khong tim thay soTH nay!!");
            return;
        }
        System.out.printf("Nhap loai giao dich('W': rut, 'D': gui): ");
        String loaiGD = sc.nextLine();
        while(!loaiGD.equals("W") && !loaiGD.equals("D")) {
            System.out.println("->Ban da nhap sai cu phap. Hay nhap lai");
            System.out.printf("Nhap loai giao dich('W': rut, 'D': gui): ");
            loaiGD = sc.nextLine();
        }
        System.out.printf("Nhap so tien giao dich: ");
        int soTienGD = sc.nextInt();
        sc.nextLine();
        if(loaiGD.equals("D")) {
            tk.setSoDu(tk.getSoDu() + soTienGD);
            tk.listGD.add(new GiaoDich(LocalDateTime.now(), soTienGD, loaiGD));
        } else {
            if(tk.getSoDu() - soTienGD < 0) {
                System.out.println("-> So du trong tai khoan khong du!!!");
                return;
            } else {
                tk.setSoDu(tk.getSoDu() - soTienGD);
                tk.listGD.add(new GiaoDich(LocalDateTime.now(), soTienGD, loaiGD));
            }
        }
    }
    
    
    public void hienThiAllGD() {
        System.out.println("-> Tat ca cac giao dich: ");
        for(int i = 0; i < this.listKhachHang.size(); i++) {
            KhachHang kh = this.listKhachHang.get(i);
            for(int j = 0; j < kh.listTKNH.size(); j++) {
                kh.listTKNH.get(j).hienThiAllGD();
            }
        }
    }
    
    public void chucNang6() {
        System.out.println("-> TK co so du nhieu nhat cua moi kh la: ");
        for(int i = 0; i < this.listKhachHang.size(); i++) {
            KhachHang kh = this.listKhachHang.get(i);
            TaiKhoanNganHang tk = kh.findTKMaxSoDu();
            System.out.println("    +) MaKH: "+ kh.maKhachHang + ", SoTK: " + tk.toSring());
        }
    }
    
    public void chucNang7() {
        ArrayList<KhachHang> newList = new ArrayList<>(this.listKhachHang);
        newList.sort((n, m) -> (int)(n.getTongSoDu() - m.getTongSoDu()));
        for(int i = 0; i < newList.size(); i++) {
            newList.get(i).hienThi();
        }
    }
    
    public void chucNang8() {
        int index = 0;
        int maxGD = this.listKhachHang.get(index).getTongGD();
        for(int i = 0; i < this.listKhachHang.size(); i++) {
            KhachHang kh = this.listKhachHang.get(i);
            if(kh.getTongGD() > maxGD) {
                index = i;
                maxGD = kh.getTongGD();
            }
        }
        System.out.println("-> KH co tong GD nhieu nhat la: " + this.listKhachHang.get(index).maKhachHang + "(MaKH) co " + maxGD + " GD.");
    }
}
