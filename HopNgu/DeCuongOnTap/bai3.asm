.model small
.stack 100
.data
    tbNhapMsv db "Nhap MSV: $"
    tbKqMsv db 13, 10, "MSV: $"
    tbNhapChuoiSo db 13, 10, "Nhap chuoi so(vd: '12,23,44'): $"
    tbKqNgTo db 13, 10, "So luong so nguyen to la: $"
    ten db 13, 10, "Ten: Nguyen Trung Hieu$"
    str db 100 dup("$")
    strMsv db 100 dup("$")
    dem dw ?
    tmp dw ?
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
        mov bx, 10
        mov dem, 0
        loop1:
        mov dx, [si]
        cmp dl, ","
        je next1
        mul bx
        mov dx, [si]
        mov dh, 0
        sub dl, 48
        add ax, dx
        jmp next2
        next1:
        mov bx, 1
        mov tmp, ax
        chia:
        mov ax, tmp
        mov dx, 0
        inc bx
        div bx
        cmp dl, 0
        jne chia
        cmp bx, tmp
        mov ax, 0
        je tangDem
        jmp next2
        tangDem:
        inc dem
        next2:
        mov bx, 10
        inc si
        loop loop1
        
        mov bx, 1
        mov tmp, ax
        chiav1:
        mov ax, tmp
        mov dx, 0
        inc bx
        div bx
        cmp dl, 0
        jne chiav1
        cmp bx, tmp
        je tangDemv1
        jmp next3
        tangDemv1:
        inc dem
        next3:
        
        mov ah, 9
        lea dx, tbKqNgTo
        int 21h
        mov ax, dem
        call chuyenSoThanhChu
        
        mov ax, 4ch
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