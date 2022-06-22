.model small
.stack 100
.data
    str db 100 dup("$")
    str2 db 100 dup("$")
    tbNhap db "Hay nhap vao ma sv: $"
    tbNhapChuoi db 13, 10, "Hay nhap chuoi bat ki: $"
    tbKQ db 13, 10, "Ma sinh vien la: $"
    tbKQChuoi db 13, 10, "Chuoi sau khi in hoa la: $"
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
        lea dx, tbNhapChuoi
        int 21h
        
        mov ah, 10
        lea dx, str2
        int 21h
        
        mov ah, 9
        lea dx, tbKQChuoi
        int 21h
        
        mov cx, 0
        mov cl, [str2 + 1]
        lea si, [str2 + 2]
        mov ah, 2
        loop1:
        mov dx, [si]
        cmp [si], "a"
        jl next
        cmp [si], "z"
        ja next
        sub dl, 32 
        next:
        int 21h
        inc si
        loop loop1
                  
        mov ah, 4ch
        int 21h    
    main endp
end