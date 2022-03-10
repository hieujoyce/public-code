package de05CuoiKi;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<ThiSinh> listTS = new ArrayList<>();
        String choice = "0";
        do {
            System.out.println(" ========================Men=======================");
            System.out.println("|  1.Nhap thi sinh khoi A                          |");
            System.out.println("|  2.Nhap thi sinh khoi C                          |");
            System.out.println("|  3.Hien thi danh sach thi sinh khoi A            |");
            System.out.println("|  4.Hien thi danh sach thi sinh khoi C            |");
            System.out.println("|  0.Exit                                          |");
            System.out.println(" ==================================================");
            System.out.printf("Moi nhap lua chon: ");
            choice = sc.nextLine();
            switch(choice) {
                case "1":
                    System.out.println("-> Ban da chon chuc nang 1");
                    ThiSinhKhoiA a = new ThiSinhKhoiA();
                    boolean b = a.nhap();
                    if(b) listTS.add(a);
                    break;
                case "2":
                    System.out.println("-> Ban da chon chuc nang 2");
                    ThiSinhKhoiC c = new ThiSinhKhoiC();
                    boolean x = c.nhap();
                    if(x) listTS.add(c);
                    break;
                case "3":
                    System.out.println("-> Ban da chon chuc nang 3");
                    System.out.println("Danh sach thi sinh khoi A tren 20 diem la: ");
                    System.out.println("");
                    System.out.printf("| %-30s| %-12s| %-20s| %-12s| %-12s| %-12s|", "Ho Ten", "NgaySinh", "Dia Chi", "Diem Toan", "Diem Ly", "Diem Hoa");
                    System.out.println("");
                    for(ThiSinh ts : listTS) {
                        if(ts.getKhoi().equals("A") && ts.getTongDiem() > 20) ts.toStrings();
                    }
                    System.out.println("");
                    break;
                case "4":
                    System.out.println("-> Ban da chon chuc nang 4");
                    System.out.println("Danh sach thi sinh khoi C tren 20 diem la: ");
                    System.out.println("");
                    System.out.printf("| %-30s| %-12s| %-20s| %-12s| %-12s| %-12s|", "Ho Ten", "NgaySinh", "Dia Chi", "Diem Van", "Diem Su", "Diem Dia");
                    System.out.println("");
                    for(ThiSinh ts : listTS) {
                        if(ts.getKhoi().equals("C") && ts.getTongDiem() > 20) ts.toStrings();
                    }
                    System.out.println("");
                    break;
                default:
                    System.out.println("Hay nhap lua chon 0-4");
                    break;
            }
        } while(!choice.equals("0"));
    }
}
