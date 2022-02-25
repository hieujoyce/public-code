package deOnTap;

import java.util.ArrayList;
import java.util.Scanner;

public class TaiKhoanNganHang {
    String soTK;
    private int soDu;
    ArrayList<GiaoDich> listGD = new ArrayList<>();
    Scanner sc = new Scanner(System.in);
    
    public TaiKhoanNganHang() {
        this.soDu = 0;
    }

    public int getSoDu() {
        return soDu;
    }

    public void setSoDu(int soDu) {
        this.soDu = soDu;
    }
    
    public void nhap() {
        System.out.println("-> Khai bao tai khoan ngan hang: ");
        System.out.printf("Nhap so Tai Khoan: ");
        this.soTK = sc.nextLine();
    }
    
    public String toSring() {
        return "SoTK: " + this.soTK + ", SoDu: " + this.soDu;
    }
    
    public void hienThiAllGD() {
        for(int i = 0; i < this.listGD.size(); i++) {
            System.out.println("    +) " + this.listGD.get(i).toString());
        }
    }
}
