package de2OnTap;

import java.util.ArrayList;
import java.util.Scanner;

public class QuanLySach {
    ArrayList<TaiLieu> listTaiLieu = new ArrayList<>();
    
    public void nhapThongTinSach() {
        Sach s = new Sach();
        s.nhap();
        this.listTaiLieu.add(s);
    }
    
    public void nhapThongTinTapChi() {
        TapChi tc = new TapChi();
        tc.nhap();
        this.listTaiLieu.add(tc);
    }
    
    public void nhapThongTinBao() {
        Bao b = new Bao();
        b.nhap();
        this.listTaiLieu.add(b);
    }
    
    public void nhapThongTin() {
        Scanner sc = new Scanner(System.in);
        int choice = 0;
        do {
            System.out.println("============================");
            System.out.println("Chon loai tai lieu muon nhap: ");
            System.out.println("1.Sach");
            System.out.println("2.Tap Chi");
            System.out.println("3.Bao");
            System.out.println("0.Quay lai");
            System.out.println("============================");
            System.out.printf("Moi nhap lua chon: ");
            choice = sc.nextInt();
            sc.nextLine();
            
            switch(choice) {
                case 1:
                    System.out.println("Ban da chon chuc nang nhap Sach");
                    this.nhapThongTinSach();
                    break;
                case 2:
                    System.out.println("Ban da chon chuc nang nhap Tap Chi");
                    this.nhapThongTinTapChi();
                    break;
                case 3:
                    System.out.println("Ban da chon chuc nang nhap Bao");
                    this.nhapThongTinBao();
                    break;
                default:
                    System.out.println("Hay nhap 0-3;");
                    break;
            }
        } while(choice != 0);
    }
    
    public void hienThiTaiLieu() {
        for(int i = 0; i < listTaiLieu.size(); i++) {
            System.out.println((i + 1) + ") " + listTaiLieu.get(i).toString());
        }
    }
    
    public void timKiemTaiLieu() {
        Scanner sc = new Scanner(System.in);
        int choice = 0;
        do {
            System.out.println("============================");
            System.out.println("Chon loai tai lieu muon tim kiem: ");
            System.out.println("1.Sach");
            System.out.println("2.Tap Chi");
            System.out.println("3.Bao");
            System.out.println("0.Quay lai");
            System.out.println("============================");
            System.out.printf("Moi nhap lua chon: ");
            choice = sc.nextInt();
            sc.nextLine();
            int dem = 1;
            
            switch(choice) {
                case 1:
                    System.out.println("Ban da chon chuc nang tim kiem Sach");
                    dem = 1;
                    for(TaiLieu tl : listTaiLieu){
                        if(tl instanceof Sach){
                            System.out.println((dem++) + ") " + tl.toString());
                        }
                    }
                    break;
                case 2:
                    System.out.println("Ban da chon chuc nang tim kiem Tap Chi");
                    dem = 1;
                    for(TaiLieu tl : listTaiLieu){
                        if(tl instanceof TapChi){
                            System.out.println((dem++) + ") " + tl.toString());
                        }
                    }
                    break;
                case 3:
                    System.out.println("Ban da chon chuc nang tim kiem Bao");
                    dem = 1;
                    for(TaiLieu tl : listTaiLieu){
                        if(tl instanceof Bao){
                            System.out.println((dem++) + ") " + tl.toString());
                        }
                    }
                    break;
                default:
                    System.out.println("Hay nhap 0-3;");
                    break;
            }
        } while(choice != 0);
    }
}
