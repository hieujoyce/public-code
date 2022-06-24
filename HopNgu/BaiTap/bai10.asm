.model small
.stack 100
.data
    tbNhap1 db "Nhap so nguyen duong A: $"
    tbNhap2 db 13, 10, "Nhap so nguyen duong B: $"
    tbKQ1 db 13, 10, "A / B = $"
    tbKQ2 db 13, 10, "A * B = $"
    str1 db 100 dup("$")
    str2 db 100 dup("$")
    num1 dw ?
    num2 dw ?
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
        
        call chuyenChuThanhSo
        mov ah, 0
        mov num1, ax
        
        mov cx, 0
        mov cl, [str2 + 1]
        lea si, [str2 + 2]
        
        call chuyenChuThanhSo
        mov ah, 0
        mov num2, ax
        
        mov ax, num1
        mov bx, num2
        mov cx, 0
        tru:
        sub al, bl
        inc cl
        cmp al, bl
        jl nextTru
        jmp tru
        nextTru:
        
        mov ah, 9
        lea dx, tbKQ1
        int 21h
        
        mov bx, 10
        mov ax, cx
        mov cx, 0
        call chuyenSoThanhChu
        
        mov ax, num1
        mov bx, num1
        mov cx, 0
        mov cx, num2
        dec cx
        cong:
        add ax, bx 
        loop cong
        
        mov bx, ax
        mov ah, 9
        lea dx, tbKQ2
        int 21h
        mov ax, bx
        mov bx, 10
        mov cx, 0
        call chuyenSoThanhChu
        
        
        
        mov ah, 4ch
        int 21h
    main endp
    
    chuyenChuThanhSo proc
        mov bx, 10
        mov ax, 0
        chuyencoso10:
        mul bx
        mov dx, [si]
        sub dl, 48
        add ax, dx
        inc si
        loop chuyencoso10
        ret    
    chuyenChuThanhSo endp
    
    chuyenSoThanhChu proc
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
        
        ret    
    chuyenSoThanhChu endp
end