package deOnTap;

import java.util.Scanner;

public class DiaChi {

    Scanner sc = new Scanner(System.in);
    String thon;
    String xaPhuong;
    String quanHuyen;
    String tinhThanhPho;
    
    public void nhap() {
        System.out.println("->Nhap Dia chi");
        System.out.printf("Nhap Thon: ");
        this.thon = sc.nextLine();
        System.out.printf("Nhap Xa/Phuong: ");
        this.xaPhuong = sc.nextLine();
        System.out.printf("Nhap Quan/Huyen: ");
        this.quanHuyen = sc.nextLine();
        System.out.printf("Nhap Tinh/Thanh Pho: ");
        this.tinhThanhPho = sc.nextLine();
    }
    
    public String toString() {
        return this.thon + ", " + this.xaPhuong + ", " + this.quanHuyen + ", " + this.tinhThanhPho + ".";
    }
}
