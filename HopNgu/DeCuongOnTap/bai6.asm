.model small
.stack 100
.data
    tbNhapMsv db "Nhap MSV: $"
    tbKqMsv db 13, 10, "MSV: $"
    tbNhapSo db 13, 10, "Nhap 1 so bat ki: $"
    tbKq1 db 13, 10, "He 16: $"
    tbKq2 db 13, 10, "He 2: $"
    ten db 13, 10, "Ten: Nguyen Trung Hieu$"
    str db 100 dup("$")
    strMsv db 100 dup("$")
    num dw ?
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
        lea dx, tbNhapSo
        int 21h
        
        mov ah, 10
        lea dx, str
        int 21h 
        
        mov cx, 0
        mov cl, [str + 1]
        lea si, [str + 2]
        call chuyenso
        mov num, ax
        call chuyenhe16
        mov ax, num
        call chuyenhe2
        mov ax, 4ch
        int 21h        
    main endp
    
    chuyenso proc
        mov bx, 10
        mov ax, 0        
        chuyensohe10:
        mul bx
        mov dl, [si]
        sub dl, 48
        add ax, dx
        inc si
        loop chuyensohe10
        ret
    chuyenso endp
    
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
    
    chuyenhe2 proc
        mov ah, 9
        lea dx, tbKQ2
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