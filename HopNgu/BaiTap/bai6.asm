.model small
.stack 100h
.data
    strNhap db 13, 10, "Nhap 1 ki tu thuong bat ki: $"
    strKQ db 13, 10, "Ket qua: $"
.code
    mov ax, @data
    mov ds, ax
    
    mov ah, 9
    lea dx, strNhap
    int 21h
    
    mov ah, 1
    int 21h ;al
    mov cx, 0
    mov cl, "z"
    sub cl, al
    add cl, 1
    
    mov bl, al
    
    mov ah, 9
    lea dx, strKQ
    int 21h
    
    mov dx, 0
    mov dl, bl
    lap:
    mov dl, bl    
    mov ah, 2
    int 21h
    mov dl, " "
    int 21h
    inc bl
    
    loop lap
    mov ah, 4CH
    int 21h    
end
