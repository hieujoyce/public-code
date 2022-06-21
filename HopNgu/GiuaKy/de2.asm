.model small
.stack 100
.data
    str db 100 dup("$")
    tbNhap db "Hay nhap vao ma sv: $"
    tbKQ db 13, 10, "Ma sinh vien la: $"
    tbHe2 db 13, 10, "He so 2 cua 3 so cuoi MSV la: $"
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
        
        mov cx, 0
        mov cl, 3
        lea si, [str + 7]
        mov ax, 0
        mov bx, 10
        
        chuyensohe10:
        mul bx
        mov dl, [si]
        sub dl, 48
        add ax, dx
        inc si
        loop chuyensohe10
        
        mov bx, 2
        mov cx, 0
        mov cl, 16
        mov si, 0
        chuyensohe2:
        mov dx, 0
        div bx
        push dx
        inc si
        cmp ax, 0
        jne chuyensohe2
        
        mov ah, 9
        lea dx, tbHe2
        int 21h
               
        mov ah, 2
        mov cx, 16
        sub cx, si
        hienthi1:
        mov dl, 48
        int 21h
        loop hienthi1
  
        mov cx, si        
        hienthi2:
        pop dx
        add dl, 48
        int 21h
        loop hienthi2     
                  
        mov ah, 4ch
        int 21h    
    main endp
end