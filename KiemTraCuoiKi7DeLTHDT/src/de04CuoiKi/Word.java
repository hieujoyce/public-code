package de04CuoiKi;

public class Word {
    static int ids = 1;
    private int id;
    private String en;
    private String vn;

    public Word(String en, String vn) {
        this.id = ids++;
        this.en = en;
        this.vn = vn;
    }

    public Word() {
        this.id = ids++;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getEn() {
        return en;
    }

    public void setEn(String en) {
        this.en = en;
    }

    public String getVn() {
        return vn;
    }

    public void setVn(String vn) {
        this.vn = vn;
    }

    @Override
    public String toString() {
        return "Word{" + "id=" + id + ", en=" + en + ", vn=" + vn + '}';
    }
    
    
    
}
