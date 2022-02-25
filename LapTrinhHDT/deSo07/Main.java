package deSo07;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    @SuppressWarnings("empty-statement")
    public static void main(String[] args) {
        int select = 1;
        ArrayList<ThiSinh> listThiSinh = new ArrayList<>();
        Scanner sc = new Scanner(System.in);
        do {
            System.out.println("=====Nhap thi sinh=====");
            String khoi;
            System.out.printf("Nhap khoi(A/C): ");
            khoi = sc.nextLine();
            ThiSinh ts;
            if(khoi.equals("A")) {
                ts = new ThiSinhKhoiA();
                ts.nhap();
            } else {
                ts = new ThiSinhKhoiC();
                ts.nhap();
            }
            listThiSinh.add(ts);
            System.out.printf("Ban muon nhap tiep khong? (1: tiep, 0: thoat): ");
            select = sc.nextInt();
            sc.nextLine();
        } while(select == 1);
        
        System.out.println("Thong tin cac thi sinh trung tuyen la (> 20): ");
        
        for(ThiSinh ts : listThiSinh) {
            if(ts.getTongDiem() > 20) {
                System.out.println(ts.toString());
            };
        }
        
    }
}
