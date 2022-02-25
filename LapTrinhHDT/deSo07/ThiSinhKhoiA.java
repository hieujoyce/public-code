package deSo07;

import java.util.Scanner;

public class ThiSinhKhoiA extends ThiSinh {
    protected float diemToan;
    protected float diemHoa;
    protected float diemLy;

    public ThiSinhKhoiA() {
    }

    public ThiSinhKhoiA(float diemToan, float diemHoa, float diemLy, String hoTen, String ngaySinh, String diaChi) {
        super(hoTen, ngaySinh, diaChi);
        this.diemToan = diemToan;
        this.diemHoa = diemHoa;
        this.diemLy = diemLy;
    }

    @Override
    public String toString() {
        return super.toString() + ", diemToan=" + diemToan + ", diemHoa=" + diemHoa + ", diemLy=" + diemLy;
    }

    
    
    @Override
    public void nhap() {
        super.nhap();
        Scanner sc = new Scanner(System.in);
        System.out.printf("Nhap diem Toan: ");
        diemToan = sc.nextFloat();
        System.out.printf("Nhap diem Hoa: ");
        diemHoa = sc.nextFloat();
        System.out.printf("Nhap diem Ly: ");
        diemLy = sc.nextFloat();
        sc.nextLine();
    }

    @Override
    float getTongDiem() {
        return diemHoa + diemLy + diemToan;
    }
    
    
}
