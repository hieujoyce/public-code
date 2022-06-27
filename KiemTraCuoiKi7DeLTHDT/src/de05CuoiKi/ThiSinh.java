package de05CuoiKi;

import java.util.Scanner;

public abstract class ThiSinh {
    protected String hoTen;
    protected String ngaySinh;
    protected String diaChi;
    
    abstract String getKhoi();
    abstract float getTongDiem();

    public ThiSinh(String hoTen, String ngaySinh, String diaChi) {
        this.hoTen = hoTen;
        this.ngaySinh = ngaySinh;
        this.diaChi = diaChi;
    }

    public ThiSinh() {
    }

   
    abstract void toStrings();
    
    public boolean nhap() {
        String regexNgaySinh = "^([0-2][0-9]||3[0-1])/(0[0-9]||1[0-2])/([0-9][0-9])?[0-9][0-9]$";
        //if(!txtNgaySinh.getText().matches(regexNgaySinh)) return "Ngày sinh không hợp lệ (VD: 06/06/2001).";
        Scanner sc = new Scanner(System.in);
        System.out.printf("Nhap Họ Tên: ");
        hoTen = sc.nextLine();
        System.out.printf("Nhập ngày sinh: ");
        ngaySinh = sc.nextLine();
        while(!ngaySinh.matches(regexNgaySinh)) {
            System.out.println("Ngày sinh không hợp lệ (VD: 01/01/2001)");
            System.out.printf("Nhập lại ngày sinh: ");
            ngaySinh = sc.nextLine();
        }
        System.out.printf("Nhập địa chỉ: ");
        diaChi = sc.nextLine();
        return true;
    }
    
    
}
