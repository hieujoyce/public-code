.model small
.stack 100
.data
    tbNhapMsv db "Nhap MSV: $"
    tbKqMsv db 13, 10, "MSV: $"
    tbNhapChuoi db 13, 10, "Nhap 1 chuoi bat ki: $"
    tbKqChuoi db 13, 10, "Ket qua: $"
    ten db 13, 10, "Ten: Nguyen Trung Hieu$"
    str db 100 dup("$")
    strMsv db 100 dup("$")
.code
    main proc
        mov ax, @data
        mov ds, ax
        
        mov ah, 9
        lea dx, tbNhapMsv
        int 21h
        
        mov ah, 10
        lea dx, strMsv
        int 21h
        
        mov ah, 9
        lea dx, tbKqMsv
        int 21h
        lea dx, [strMsv + 2]
        int 21h
        lea dx, ten
        int 21h
        lea dx, tbNhapChuoi
        int 21h
        
        mov ah, 10
        lea dx, str
        int 21h
               
        mov ah, 9
        lea dx, tbKqChuoi
        int 21h
        
        mov cx, 0
        mov cl, [str + 1]
        lea si, [str + 2]
        hienthi:
        mov dx, [si]
        cmp dl, "A"
        jl next
        cmp dl, "Z"
        ja next
        add dl, 32
        next:
        mov ah, 2
        int 21h
        inc si
        
        loop hienthi
               
        mov ah, 4ch
        int 21h
    main endp
end