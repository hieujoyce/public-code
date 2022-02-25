package giuaKi;

public class Book {
    private int ID;
    private String name;
    private double price;

    public int getID() {
        return ID;
    }

    public void setID(int ID) {
        this.ID = ID;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }
    
    public void hienThiSach() {
        System.out.println("ID: " + this.ID + ", Name: " + this.name + ", Price: " + this.price);
    }
}
