.model small
.stack 100
.data
    tbNhap1 db "Nhap so thu nhat: $"
    tbNhap2 db 13, 10, "Nhap so thu hai: $"
    str1 db 100 dup("$")
    str2 db 100 dup("$")
    tbKQ db 13, 10, "S = $"
    num1 dw ?
    num2 dw ?
    sum dw ?
.code
    main proc
        mov ax, @data
        mov ds, ax
        
        mov ah, 9
        lea dx, tbNhap1
        int 21h
        
        mov ah, 10
        lea dx, str1
        int 21h
        
        mov ah, 9
        lea dx, tbNhap2
        int 21h
        
        mov ah, 10
        lea dx, str2
        int 21h
        
        
        mov cx, 0
        mov cl, [str1 + 1]
        lea si, [str1 + 2]
        call chuyenso       
        
        mov num1, ax
        
        mov cx, 0
        mov cl, [str2 + 1]
        lea si, [str2 + 2]
        call chuyenso      
        mov num2, ax
        add ax, num1
        mov sum, ax
        
        mov ah, 9
        lea dx, tbKQ
        int 21h
        
        mov bx, 10
        mov ax, sum
        mov cx, 0
        pushNganXep:
        mov dx, 0
        div bx
        push dx
        inc cl
        cmp ax, 0
        je hienthi
        jmp pushNganXep
        hienthi:
        pop dx
        add dl, 48
        mov ah, 2
        int 21h
        loop hienthi
        
        mov ah, 4ch
        int 21h      
    main endp
    
    chuyenso proc
        mov bx, 10
        mov ax, 0        
        chuyensohe10:
        mul bx
        mov dl, [si]
        sub dl, 48
        add ax, dx
        inc si
        loop chuyensohe10
        ret
    chuyenso endp
        
end
        