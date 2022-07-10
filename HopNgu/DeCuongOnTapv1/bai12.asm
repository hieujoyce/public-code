.model small
.stack 100
.data
    tbNhapMsv db "Nhap MSV: $"
    tbKqMsv db 13, 10, "MSV: $"
    tbNhapChuoi db 13, 10, "Nhap 1 chuoi bat ki: $"
    tbNhapKiTu db 13, 10, "Nhap 1 ki tu muon tim: $"
    tbKqChuoi db 13, 10, "Do dai chuoi: $"
    ten db 13, 10, "Ten: Nguyen Trung Hieu$"
    str db 100 dup("$")
    strMsv db 100 dup("$")
.code
    main proc
        mov ax, @data
        mov ds, ax
        
        mov ah, 9
        lea dx, tbNhapMsv
        int 21h
        
        mov ah, 10
        lea dx, strMsv
        int 21h
        
        mov ah, 9
        lea dx, tbKqMsv
        int 21h
        lea dx, [strMsv + 2]
        int 21h
        lea dx, ten
        int 21h
        lea dx, tbNhapChuoi
        int 21h
        
        mov ah, 10
        lea dx, str
        int 21h
               
        mov ah, 9
        lea dx, tbKqChuoi
        int 21h
        
        mov ax, 0
        mov al, [str + 1]
        call chuyenSoThanhChu
               
        mov ah, 4ch
        int 21h
    main endp
    
    chuyenSoThanhChu proc
        mov bx, 10
        mov cx, 0
        chia10:
        mov dx, 0
        div bx
        push dx
        inc cl
        cmp ax, 0
        je hienthi
        jmp chia10
        hienthi:
        pop dx
        add dl, 48
        mov ah, 2
        int 21h
        loop hienthi
        ret
    chuyenSoThanhChu endp
end