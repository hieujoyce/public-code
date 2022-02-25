package giuaKi;

import java.util.ArrayList;
import java.util.Scanner;

public class Store {
    public int totalItems;
    private int Max_Items;
    ArrayList<Book> listItems = new ArrayList<>();
    static int id = 0;
    Scanner sc = new Scanner(System.in);
    
    public Store() {
        this.totalItems = 0;
        this.Max_Items = 10;
    }
    
    public void add() {
        if(this.totalItems == this.Max_Items) {
            System.out.println("Da vuot qua so book quy dinh");
            return;
        }
        Book a = new Book();
        a.setID(id);
        System.out.printf("Nhap name of book: ");
        a.setName(sc.next());
        sc.nextLine();
        System.out.printf("Nhap price of book: ");
        a.setPrice(sc.nextDouble());
        sc.nextLine();
        this.listItems.add(a);
        id++;
        System.out.println("Da them xong a book");
        this.totalItems++;
    }
    
    public void edit() {
        int idBook;
        System.out.printf("Nhap id sach muon edit: ");
        idBook = sc.nextInt();
        sc.nextLine();
        int viTri = this.checkIdBook(idBook);
        if(viTri == -1) {
            System.out.println("Trong Store khong co id nay");
        } else {
            System.out.println("Nhap name of book muon sua: ");
            this.listItems.get(viTri).setName(sc.next());
            sc.nextLine();
            System.out.println("Nhap price of book: ");
            this.listItems.get(viTri).setPrice(sc.nextDouble());
            sc.nextLine();
            System.out.println("Da sua xong a book");
        }
    }
    
    public void delete() {
        int idBook;
        System.out.printf("Nhap id sach muon delete: ");
        idBook = sc.nextInt();
        sc.nextLine();
        int viTri = this.checkIdBook(idBook);
        if(viTri == -1) {
            System.out.println("Trong Store khong co id nay");
        } else {
            this.listItems.remove(viTri);
            System.out.println("Da xoa xong a book");
        }
        this.totalItems--;
    }
    
    public void find() {
        String nameBook;
        System.out.println("Nhap name sach muon tim: ");
        nameBook = sc.next();
        sc.nextLine();
        boolean check = false;
        for(int i = 0; i < this.listItems.size(); i++) {
            if(this.listItems.get(i).getName().equals(nameBook)) {
                System.out.printf("Sach tim thay: ");
                this.listItems.get(i).hienThiSach();
                check = true;
            }
        }
        if(check == false) {
            System.out.println("Khong tim thay sach co name la " + nameBook);
        }
    }
    
    public void list() {
        for(int i = 0; i < this.listItems.size(); i++) {
            System.out.printf("Thong tin sach thu " + (i + 1) + ": ");
            this.listItems.get(i).hienThiSach();
        }
    }
    
    public int checkIdBook(int id) {
        for(int i = 0; i < this.listItems.size(); i++) {
            if(this.listItems.get(i).getID() == id) {
                return i;
            }
        }
        return -1;
    }
}
