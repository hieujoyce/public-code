package de2OnTap;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        QuanLySach store = new QuanLySach();
        int choice = 0;
        do {
            System.out.println("============Menu============");
            System.out.println("1.Nhap thong tin ve cac tai lieu");
            System.out.println("2.Hien thi thong tin cac tai lieu");
            System.out.println("3.Tim kiem tai lieu theo loai");
            System.out.println("0.Exit");
            System.out.println("============================");
            System.out.printf("Moi nhap lua chon: ");
            choice = sc.nextInt();
            sc.nextLine();
            
            switch(choice) {
                case 1:
                    System.out.println("Ban da chon chuc nang Add book");
                    store.nhapThongTin();
                    break;
                case 2:
                    System.out.println("Ban da chon chuc nang Edit book");
                    store.hienThiTaiLieu();
                    break;
                case 3:
                    System.out.println("Ban da chon chuc nang Delete book");
                    store.timKiemTaiLieu();
                    break;
                default:
                    System.out.println("Hay nhap 0-3;");
                    break;
            }
        } while(choice != 0);
    }
}
