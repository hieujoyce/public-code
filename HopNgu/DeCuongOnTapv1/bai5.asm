.model small
.stack 100
.data
    tbNhapMsv db "Nhap MSV: $"
    tbKqMsv db 13, 10, "MSV: $"
    tbKqSoDuong db 13, 10, "So luong so duong: $"
    tbKqSoAm db 13, 10, "So luong so am: $"
    tbNhapChuoiSo db 13, 10, "Nhap chuoi so(vd: '12,23,44'): $"
    ten db 13, 10, "Ten: Nguyen Trung Hieu$"
    str db 100 dup("$")
    dem1 dw ?
    dem2 dw ?
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
        lea dx, tbNhapChuoiSo
        int 21h
         
        mov ah, 10
        lea dx, str
        int 21h
        
        mov cx, 0
        mov cl, [str + 1]
        lea si, [str + 2]
        mov ax, 0
        mov dem1, 0
        mov dem2, 0
        loop1:
        mov dx, [si]
        cmp dl, "-"
        jne next2
        inc ax
        jmp next4
        next2:
        cmp dl, ","
        je next1
        jmp next4
        next1:
        cmp al, 0
        je tangDem1
        jmp tangDem2
        tangDem1:
        inc dem1
        jmp next3
        tangDem2:
        inc dem2
        jmp next3
        next3:
        mov ax, 0
        
        next4:
        inc si
        loop loop1
        
        cmp al, 0
        je tangDem1a
        jmp tangDem2a
        tangDem1a:
        inc dem1
        jmp next5
        tangDem2a:
        inc dem2
        next5:
        
        mov ah, 9
        lea dx, tbKqSoDuong
        int 21h
        mov ax, dem1
        call chuyenSoThanhChu
        
        mov ah, 9
        lea dx, tbKqSoAm
        int 21h
        mov ax, dem2
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