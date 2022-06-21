.model small
.stack 100h
.data
    strNhap db 13, 10, "Hay nhap 1 chuoi bat ki $"
    strKetQua db 13, 10, "Do dai cua chuoi la: $"
.code
    main proc
        mov ax, @data
        mov ds, ax
        
        mov ah, 9
        lea dx, strNhap
        int 21h
        mov bx, 0
        
        nhap1kitu:
        mov ah, 1
        int 21h
        cmp al, 13
        je inketqua
        inc bx
        jmp nhap1kitu
        
        
        inketqua:
        mov ah, 9
        lea dx, strKetQua
        int 21h
        
        
        
        mov ah, 4CH
        int 21h
    main endp
end