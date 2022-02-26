package de07CuoiKi;

public class NhanVien {
    protected int id;
    protected String hoTen;

    public NhanVien(String hoTen) {
        this.hoTen = hoTen;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getHoTen() {
        return hoTen;
    }

    public void setHoTen(String hoTen) {
        this.hoTen = hoTen;
    }
    

    public NhanVien() {
    }

    @Override
    public String toString() {
        return "id: " + id + ", hoTen: " + hoTen;
    }
    
    
}
