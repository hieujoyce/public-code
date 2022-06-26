.model small
.stack 100
.data
    tbNhapMsv db "Nhap MSV: $"
    tbKqMsv db 13, 10, "MSV: $"
    tbNhapChuoi db 13, 10, "Nhap 1 chuoi bat ki: $"
    tbNhapKiTu db 13, 10, "Nhap 1 ki tu muon tim: $"
    tbKqChuoi db 13, 10, "Ket qua: $"
    tbKqTimThay db "Ki tu tim thay o vi tri $"
    tbKqKhongTimThay db "Khong tim thay ki tu $"
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
        lea dx, tbNhapKiTu
        int 21h
        mov ah, 1
        int 21h
        mov bx, 0
        mov bl, al
        mov ah, 9
        lea dx, tbKqChuoi
        int 21h
        
        mov al, bl
        mov cx, 0
        mov cl, [str + 1]
        lea si, [str + 2]
        mov bx, 1
        loop1:
        mov dx, [si]
        cmp al, dl
        je tbTimThay
        inc si
        inc bx
        loop loop1
        jmp tbKhongTimThay
        
        tbTimThay:
        mov ah, 9
        lea dx, tbKqTimThay
        int 21h
        mov ax, bx
        call chuyenSoThanhChu
        jmp exit
        
        tbKhongTimThay:
        mov ah, 9
        lea dx, tbKqKhongTimThay
        int 21h
        
        exit:
               
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