package de05CuoiKi;

import java.util.Scanner;

public class ThiSinhKhoiA extends ThiSinh{
    protected float diemToan;
    protected float diemLy;
    protected float diemHoa;
    
    @Override
    public boolean nhap() {
        super.nhap(); //To change body of generated methods, choose Tools | Templates.
        Scanner sc = new Scanner(System.in);
        
        try {
            System.out.printf("Nhap diem Toan: ");
            diemToan = sc.nextFloat();
            while(diemToan < 0 || diemToan > 10) {
                System.out.println("Hay nhap diem Toan trong khoang [0, 10]");
                System.out.printf("Nhap lai diem Toan: ");
                diemToan = sc.nextFloat();
            }
            
            System.out.printf("Nhap diem Hoa: ");
            diemHoa = sc.nextFloat();
            while(diemHoa < 0 || diemHoa > 10) {
                System.out.println("Hay nhap diem Hoa trong khoang [0, 10]");
                System.out.printf("Nhap lai diem Hoa: ");
                diemHoa = sc.nextFloat();
            }
            
            System.out.printf("Nhap diem Ly: ");
            diemLy = sc.nextFloat();
            while(diemLy < 0 || diemLy > 10) {
                System.out.println("Hay nhap diem Ly trong khoang [0, 10]");
                System.out.printf("Nhap lai diem Ly: ");
                diemLy = sc.nextFloat();
            }
            
        } catch (Exception e) {
            System.out.println("Lỗi: lỗi định dạng input");
            return false;
        }
        return true;
    }

    public ThiSinhKhoiA(float diemToan, float diemLy, float diemHoa) {
        this.diemToan = diemToan;
        this.diemLy = diemLy;
        this.diemHoa = diemHoa;
    }

    public ThiSinhKhoiA() {
    }

    @Override
    public void toStrings() {
        //return "Ho Ten: " + hoTen + ", Ngay Sinh: " + ngaySinh + ", DiaChi: " + diaChi + ", Diem Toan: " + diemToan + ", Diem Ly: " + diemLy + ", Diem Hoa: " + diemHoa;
        System.out.printf("| %-30s| %-12s| %-20s| %-12.2f| %-12.2f| %-12.2f|", hoTen, ngaySinh, diaChi, diemToan, diemLy, diemHoa);
        System.out.println("");
    }

    @Override
    String getKhoi() {
        return "A";
    }

    @Override
    float getTongDiem() {
        return diemHoa + diemLy + diemToan;
    }
}
