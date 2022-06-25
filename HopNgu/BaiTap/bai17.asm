.model small
.stack 100
.data
    tbNhap db "Nhap chuoi bat ki: $"
    tbKQ db 13, 10, "Chuoi dao nguoc la: $"
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
        
        mov cx, 0
        mov cl, [str + 1]
        lea si, [str + 2]
        pushNganXep:
        mov dx, 0
        mov dx, [si]
        push dx
        inc si
        loop pushNganXep
        
        mov ah, 9
        lea dx, tbKQ
        int 21h
        
        mov cx, 0
        mov cl, [str + 1]
        hienthi:
        pop dx
        mov ah, 2
        int 21h
        loop hienthi
        
        mov ah, 4ch
        int 21h
    main endp
end
    