.model small
.stack 100
.data
    str db 100 dup("$")
    tbNhap db "Hay nhap vao ma sv: $"
    tbKQ db 13, 10, "Ma sinh vien la: $"
    tbMsvSpace db 13, 10, "Ket qua msv khoang cach la: $"
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
        lea dx, tbMsvSpace
        int 21h
        
        mov cx, 0
        mov cl, [str + 1]
        lea si, [str + 2]
        mov ah, 2
        loop1:
        mov dx, [si]
        int 21h
        mov dl, " "
        int 21h
        inc si
        loop loop1     
             
                  
        mov ah, 4ch
        int 21h    
    main endp
end