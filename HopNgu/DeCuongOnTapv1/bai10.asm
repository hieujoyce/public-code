.model small
.stack 100
.data
    tbNhapMsv db "Nhap MSV: $"
    tbKqMsv db 13, 10, "MSV: $"
    tbNhapChuoi1 db 13, 10, "Nhap chuoi 1: $"
    tbNhapChuoi2 db 13, 10, "Nhap chuoi 2: $"
    tbKqSoSanh db 13, 10, "Ket qua: $"
    tbKqBang db "2 chuoi giong nhau$"
    tbKqKhongBang db "2 chuoi khong giong nhau$"
    ten db 13, 10, "Ten: Nguyen Trung Hieu$"
    str1 db 100 dup("$")
    str2 db 100 dup("$")
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
        lea dx, tbNhapChuoi1
        int 21h
        
        mov ah, 10
        lea dx, str1
        int 21h
        mov ah, 9
        lea dx, tbNhapChuoi2
        int 21h
        mov ah, 10
        lea dx, str2
        int 21h
        mov ah, 9
        lea dx, tbKqSoSanh
        int 21h

        mov al, [str1 + 1]
        mov bl, [str2 + 1]
        soSanhDoDai:
        cmp al, bl
        jne tbKhongBang
        
        mov cx, 0
        mov cl, [str1 + 1]
        mov dx, 0
        sosanh:
        mov si, 0
        lea si, [str1 + 2]
        add si, dx
        mov ax, [si]
        
        mov si, 0
        lea si, [str2 + 2]
        add si, dx
        mov bx, [si]
        cmp al, bl
        jne tbKhongBang
        inc dx
        loop sosanh
        jmp tbBang

        tbKhongBang:
        mov ah, 9
        lea dx, tbKqKhongBang
        int 21h
        jmp exit
        
        tbBang:
        mov ah, 9
        lea dx, tbKqBang
        int 21h
        jmp exit
                
        exit:        
        mov ah, 4ch
        int 21h
    main endp
end