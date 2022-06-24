.model small
.stack 100
.data
    tbNhap db "Nhap 1 chuoi bat ki: $"
    tbKQ db 13, 10, "Ket qua: $"
    str db 100 dup("$")
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
        
        mov cx, 0
        mov cl, [str + 1]
        lea si, [str + 2]
        
        mov ah, 2
        loop1:
        mov dx, [si]
        cmp dl, "a"
        jl next
        cmp dl, "z"
        ja next
        sub dl, 32
        
        next:
        int 21h
        inc si
        loop loop1
        
        mov dl, " "
        int 21h
        mov dl, "-"
        int 21h
        mov dl, " "
        int 21h
        
        mov cx, 0
        mov cl, [str + 1]
        lea si, [str + 2]
        
        mov ah, 2
        loop2:
        mov dx, [si]
        cmp dl, "A"
        jl next1
        cmp dl, "Z"
        ja next1
        add dl, 32
        
        next1:
        int 21h
        inc si
        loop loop2
                
    main endp
end