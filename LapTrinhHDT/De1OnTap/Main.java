package deOnTap;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ChiNhanhNganHang chiNhanh = new ChiNhanhNganHang();
        chiNhanh.nhap();
        int choice = 0;
        do {
            System.out.println(" ====================Menu(" + chiNhanh.tenChiNhanh + ")==================");
            System.out.println("|  1.Them Khach Hang                               |");
            System.out.println("|  2.Them 1 tai khoan cho khach hang               |");
            System.out.println("|  3.In ra thong tin 1 khach hang                  |");
            System.out.println("|  4.Thuc hien gui hoac rut tien                   |");
            System.out.println("|  5.Hien thi tat ca cac giao dich                 |");
            System.out.println("|  6.Hien Thi tk co so du nhieu nhat cua tung kh   |");
            System.out.println("|  7.Sap xep tang dan theo tong so du cua tung kh  |");
            System.out.println("|  8.Hien thi kh co tong luong gd nhieu nhat       |");
            System.out.println("|  0.Exit                                          |");
            System.out.println(" ==================================================");
            System.out.printf("Moi nhap lua chon: ");
            choice = sc.nextInt();
            sc.nextLine();
            
            switch(choice) {
                case 1:
                    System.out.println("-> Ban da chon chuc nang 1");
                    chiNhanh.themKH();
                    break;
                case 2:
                    System.out.println("-> Ban da chon chuc nang 2");
                    chiNhanh.themTKChoKH();
                    break;
                case 3:
                    System.out.println("-> Ban da chon chuc nang 3");
                    chiNhanh.hienThiInfo1KH();
                    break;
                case 4:
                    System.out.println("-> Ban da chon chuc nang 4");
                    chiNhanh.guiRutTien();
                    break;
                case 5:
                    System.out.println("-> Ban da chon chuc nang 5");
                    chiNhanh.hienThiAllGD();
                    break;
                case 6:
                    System.out.println("-> Ban da chon chuc nang 6");
                    chiNhanh.chucNang6();
                    break;
                case 7:
                    System.out.println("-> Ban da chon chuc nang 7");
                    chiNhanh.chucNang7();
                    break;
                case 8:
                    System.out.println("-> Ban da chon chuc nang 8");
                    chiNhanh.chucNang8();
                    break;
                default:
                    System.out.println("Hay nhap lua chon 0-6");
                    break;
            }
        } while(choice != 0);
    }
}
