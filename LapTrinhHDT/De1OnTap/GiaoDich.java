package deOnTap;

import java.time.LocalDateTime;

public class GiaoDich {
    static int maGiaoDich = 0;
    int maGD;
    LocalDateTime thoiGianGD;
    int soTienGD;
    String loaiGD;

    public GiaoDich(LocalDateTime thoiGianGD, int soTienGD, String loaiGD) {
        GiaoDich.maGiaoDich++;
        this.maGD = GiaoDich.maGiaoDich;
        this.thoiGianGD = thoiGianGD;
        this.soTienGD = soTienGD;
        this.loaiGD = loaiGD;
    }
    
    public String toString() {
        return "MaGD: " + this.maGD + ", TG: " + this.thoiGianGD  + ", SoTienGD: " + this.soTienGD + ", LoaiGD: " + this.loaiGD;
    }
}
    
