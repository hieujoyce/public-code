.model small
.stack 100
.data
    str db 100 dup("$")
    tbNhap db "Hay nhap vao ma sv: $"
    tbKQ db 13, 10, "Ma sinh vien la: $"
    tbInThuong db 13, 10, "MSV sau khi doi la: $"
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
        lea dx, tbInThuong
        int 21h
        
        mov cx, 0
        mov cl, 2
        lea si, [str + 2]
        
        loop1:
        cmp [si], "A"
        jl next
        cmp [si], "Z"
        ja next
        mov dx, [si]
        add dl, 32
        mov ah, 2
        int 21h 
        next:
        inc si
        loop loop1
        
        mov ah, 9
        lea dx, si
        int 21h     
             
                  
        mov ah, 4ch
        int 21h    
    main endp
end