package deSo05;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        ArrayList<NhanVien> listNV = new ArrayList<>();
        
        try {
            FileReader fr = new FileReader("test.txt");
            BufferedReader br = new BufferedReader(fr);
            String s = br.readLine();
            while(s != null) {
                String[] listStr = s.split("\\$");
                NhanVien nv = new NhanVien();
                nv.hoTen = listStr[0];
                nv.ngaySinh = listStr[1];
                nv.diaChi = listStr[2];
                nv.gioiTinh = listStr[3];
                nv.maNhanVien = listStr[4];
                nv.heSoLuong = Float.parseFloat(listStr[5]);
                nv.donVi = listStr[6];
                listNV.add(nv);
                s = br.readLine();
            }
        } catch (Exception e) {
            //
        }
        
        System.out.println("Danh sach nhan vien: ");
        for(NhanVien nv : listNV) {
            System.out.println(nv.toString());
        }
    }
}
