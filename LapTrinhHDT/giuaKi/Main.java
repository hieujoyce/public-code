package giuaKi;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Store st = new Store();
        int choice = 0;
        do {
            System.out.println("============Menu============");
            System.out.println("1.Add book");
            System.out.println("2.Edit book");
            System.out.println("3.Delete book");
            System.out.println("4.Find book");
            System.out.println("5.List book");
            System.out.println("0.Exit");
            System.out.println("============================");
            System.out.printf("Moi nhap lua chon: ");
            choice = sc.nextInt();
            sc.nextLine();
            
            switch(choice) {
                case 1:
                    System.out.println("Ban da chon chuc nang Add book");
                    st.add();
                    break;
                case 2:
                    System.out.println("Ban da chon chuc nang Edit book");
                    st.edit();
                    break;
                case 3:
                    System.out.println("Ban da chon chuc nang Delete book");
                    st.delete();
                    break;
                case 4:
                    System.out.println("Ban da chon chuc nang Find book");
                    st.find();
                    break;
                case 5:
                    System.out.println("Ban da chon chuc nang List book");
                    st.list();
                    break;
                default:
                    System.out.println("Hay nhap 0-5;");
                    break;
            }
        } while(choice != 0);
    }
}
