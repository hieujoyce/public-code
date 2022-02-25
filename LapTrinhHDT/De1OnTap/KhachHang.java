package deOnTap;

import java.util.ArrayList;
import java.util.Scanner;

public class KhachHang {
    String maKhachHang;
    String tenKhachHang;
    DiaChi diaChi;
    ArrayList<TaiKhoanNganHang> listTKNH = new ArrayList<>();
    Scanner sc = new Scanner(System.in);
    
    public void nhap() {
        System.out.println("-> Khai bao Khach Hang:");
        System.out.printf("Nhap Ma Khach Hang: ");
        this.maKhachHang = sc.nextLine();
        System.out.printf("Nhap Ten Khach Hang: ");
        this.tenKhachHang = sc.nextLine();
        this.diaChi = new DiaChi();
        this.diaChi.nhap();
    }
    
    public void hienThi() {
        System.out.println("-> Thong tin Khach Hang: ");
        System.out.println("Ma KH: " + this.maKhachHang);
        System.out.println("Ten KH: " + this.tenKhachHang);
        System.out.println("Dia Chi: " + this.diaChi.toString());
        if(this.listTKNH.size() == 0) {
            System.out.println("Kh nay chua co tai khoan nao");
        } else {
            System.out.println("Dach sach cac tk cua kh: ");
            for(int i = 0; i < this.listTKNH.size(); i++) {
                System.out.println("    +) " + this.listTKNH.get(i).soTK);
            }
        }
        System.out.println("Tong SoDu: " + this.getTongSoDu());
    }
    
    public void hienThiDanhSachTK() {
        System.out.println("Dach sach cac tai khoan(soTK): ");
        for(int i = 0; i < this.listTKNH.size(); i++) {
            System.out.println("    +) " + this.listTKNH.get(i).soTK);
        }
    }
    
    public TaiKhoanNganHang findTKMaxSoDu() {
        int index = 0;
        int maxSoDu = this.listTKNH.get(index).getSoDu();
        for(int i = 0; i < this.listTKNH.size(); i++) {
            if (this.listTKNH.get(i).getSoDu() > maxSoDu) {
                maxSoDu = this.listTKNH.get(i).getSoDu();
                index = i;
            }
        }
        return this.listTKNH.get(index);
    }
    
    public int getTongSoDu() {
        int tongSoDu = 0;
        for(int i = 0; i < this.listTKNH.size(); i++) {
            tongSoDu += this.listTKNH.get(i).getSoDu();
        }
        return tongSoDu;
    }
    
    public int getTongGD() {
        int tongGD = 0;
        for(int i = 0; i < this.listTKNH.size(); i++) {
            TaiKhoanNganHang tk = this.listTKNH.get(i);
            tongGD += tk.listGD.size();
        }
        return tongGD;
    }
}
