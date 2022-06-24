.model small
.stack 100h
.data
    tbNhap1 db "Nhap so nhi phan 16 bit A: $"
    tbNhap2 db 13, 10, "Nhap so nhi phan 16 bit B: $"
    tbKQ1 db 13, 10, "A + B = $"
    tbKQ2 db 13, 10, "A - B = $"
    tbKQ3 db 13, 10, "A and B = $"
    tbKQ4 db 13, 10, "A or B = $"
    str1 db 100 dup("$")
    str2 db 100 dup("$")
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
        
        call cong
        call tru
        
        mov ah, 4ch
        int 21h
    main endp
    
    cong proc
        mov ah, 9
        lea dx, tbKQ1
        int 21h
        mov cx, 16
        mov ax, 0
        loopCong:
        lea si, [str1 + 2]
        add si, cx
        dec si
        
        mov dx, 0
        mov dl, [si]
        sub dl, 48
        add ax, dx
        
        lea si, [str2 + 2]
        add si, cx
        dec si
        
        mov dx, 0
        mov dl, [si]
        sub dl, 48
        add ax, dx
        
        cmp ax, 2
        je nextCong1 
        mov dx, ax
        add dl, 48
        push dx
        mov ax, 0
        jmp nextCong2
        nextCong1:
        mov dl, 1
        add dl, 48
        push dx
        mov ax, 1
        nextCong2:
        loop loopCong
        mov cx, 0
        mov cl, 16
        mov ah, 2
        nextCong3:
        pop dx
        int 21h
        loop nextCong3
               
        ret
    cong endp
    
    tru proc
        mov ah, 9
        lea dx, tbKQ2
        int 21h
        mov cx, 16
        mov ax, 2
        loopTru:
        lea si, [str1 + 2]
        add si, cx
        dec si
        
        mov dx, 0
        mov dl, [si]
        sub dl, 48
        add ax, dx
        
        lea si, [str2 + 2]
        add si, cx
        dec si
        
        mov dx, 0
        mov dl, [si]
        sub dl, 48
        sub ax, dx
        
        cmp ax, 1
        je nextTru1
        cmp ax, 0
        je nextTru1 
        mov dx, ax
        add dl, 46
        push dx
        mov ax, 2
        jmp nextTru2
        nextTru1:
        mov dl, 1
        add dl, 48
        push dx
        mov ax, 1
        nextTru2:
        loop loopTru
        
        mov cx, 0
        mov cl, 16
        mov ah, 2
        nextTru3:
        pop dx
        int 21h
        loop nextTru3
               
        ret
    tru endp
end