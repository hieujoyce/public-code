.model small
.stack 100
.data
    tbNhapMsv db "Nhap MSV: $"
    tbKqMsv db 13, 10, "MSV: $"
    tbNhapN db 13, 10, "Nhap n ( 0<n<9 ): $"
    tbKqNGiaiThua db 13, 10, "n! = $"
    ten db 13, 10, "Ten: Nguyen Trung Hieu$"
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
        lea dx, tbNhapN
        int 21h
        mov ah, 1
        int 21h
        
        sub al, 48
        mov cx, 0
        mov cl, al
        
        mov ah, 9
        lea dx, tbKqNGiaiThua
        int 21h
        
        mov ax, 1
        mov bx, 1
        giaithua:
        mul bx
        inc bx
        loop giaithua
        
        call chuyenSoThanhChu
        
        mov ah, 4ch
        int 21h
    main endp
    
    chuyenSoThanhChu proc
        mov cx, 0
        mov bx, 10
        chia10:
        mov dx, 0
        div bx
        push dx
        inc cx
        cmp ax, 0
        je hienthi
        jmp chia10
        hienthi:
        pop dx
        add dl, 48
        mov ah, 2
        int 21h
        loop hienthi
        ret
    chuyenSoThanhChu endp
end