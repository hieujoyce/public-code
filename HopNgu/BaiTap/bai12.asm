.model small
.stack 100
.data
    tbNhap db "Nhap 1 ky tu: $"
    tbKQ1 db 13, 10, "Ma ASCII dang Hex: $"
    tbKQ2 db 13, 10, "Ma ASCII dang Dec: $"
    tbKQ3 db 13, 10, "Ma ASCII dang Bin: $"
    num dw ?
.code
    main proc
        mov ax, @data
        mov ds, ax
        
        mov ah, 9
        lea dx, tbNhap
        int 21h
        
        mov ah, 1
        int 21h
        
        mov ah, 0
        mov num, ax
        call chuyenhe16
        call chuyenhe10
        call chuyenhe2
        
        mov ah, 4ch
        int 21h
    main endp
    
    chuyenhe16 proc
        mov ah, 9
        lea dx, tbKQ1
        int 21h
        mov ax, num
        mov bx, 16
        mov cx, 0
        chia16:
        mov dx, 0
        div bx
        push dx
        inc cx
        cmp ax, 0
        je hienthi16
        jmp chia16
        hienthi16:
        pop dx
        mov ah, 2
        cmp dl, 9
        ja hienthi16v1
        add dl, 48
        int 21h
        jmp next16
        hienthi16v1:
        add dl, 55
        int 21h
        jmp next16
        next16:
        loop hienthi16
        
        mov dl, "h"
        int 21h
        ret
    chuyenhe16 endp
    
    chuyenhe10 proc
        mov ah, 9
        lea dx, tbKQ2
        int 21h
        
        mov ax, num
        mov bx, 10
        mov cx, 0
        chia10:
        mov dx, 0
        div bx
        push dx
        inc cx
        cmp ax, 0
        je hienthi10
        jmp chia10
        
        hienthi10:
        pop dx
        add dl, 48
        mov ah, 2
        int 21h
        loop hienthi10
        
        
        ret
    chuyenhe10 endp
    
    chuyenhe2 proc
        mov ah, 9
        lea dx, tbKQ3
        int 21h
        
        mov ax, num
        mov bx, 2
        mov cx, 0
        
        chia2:
        mov dx, 0
        div bx
        push dx
        inc cx
        cmp ax, 0
        je hienthi2
        jmp chia2
        hienthi2:
        pop dx
        add dl, 48
        mov ah, 2
        int 21h
        loop hienthi2
        
        mov ah, 2
        mov dl, "b"
        int 21h
        ret
    chuyenhe2 endp
end