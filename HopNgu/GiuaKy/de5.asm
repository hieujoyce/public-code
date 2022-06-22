.model small
.stack 100
.data
    str db 100 dup("$")
    tbNhap db 13, 10, "Hay nhap ho va ten sv: $"
    tbKQ db 13, 10, "Ten sinh vien la: $"
    tbDaoNguoc db 13, 10, "Ten sinh vien dao nguoc la: $"
.code
    main proc
        mov ax, @data
        mov ds, ax
        
        mov ah, 9
        lea dx, tbNhap
        int 21h
        
        mov ah, 10
        lea dx, str
        int 21h
        
        mov ah, 9
        lea dx, tbKQ
        int 21h 
        lea dx, [str + 2]
        int 21h
        lea dx, tbDaoNguoc
        int 21h
        
        mov cx, 0
        mov cl, [str + 1]
        lea si, [str + 2]
        
        loop1:
        push [si]
        inc si
        loop loop1
        
        mov cx, 0
        mov cl, [str + 1]
        mov ah, 2
        
        loop2:
        pop dx
        int 21h
        loop loop2   
                  
        mov ah, 4ch
        int 21h    
    main endp
end