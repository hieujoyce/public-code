package de1MienNam;

import java.util.Scanner;

public class DiaChi {
    Scanner sc = new Scanner(System.in);
    String to;
    String phuong;
    String quan;
    String thanhPho;
    
    public void nhap() {
        System.out.println("-> Dia chi");
        System.out.printf("Nhap To: ");
        this.to = sc.nextLine();
        System.out.printf("Nhap Phuong: ");
        this.phuong = sc.nextLine();
        System.out.printf("Nhap Quan: ");
        this.quan = sc.nextLine();
        System.out.printf("Nhap Thanh Pho: ");
        this.thanhPho = sc.nextLine();
    }
    
    public String info() {
        return "DiaChi: To " + this.to + ", Phuong: " + this.phuong + ", Quan: " + this.quan + ", Thanh Pho: " + this.thanhPho;
    }
}
