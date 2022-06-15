.model small
.stack 100h
.data
    strNhap db "Nhap vao ten cua ban: $"
    strChao db 13, 10, "Xin chao $"
    str db 100 dup("$")
.code
    main proc
        mov ax, @data
        mov ds, ax
        
        lea dx, strNhap
        mov ah, 9
        int 21h
        
        lea dx, str
        mov ah, 10
        int 21h
        
        mov ah, 9
        lea dx, strChao,
        int 21h
        lea dx, str + 2
        int 21h
        
        mov ah, 4CH
        int 21h        
    main endp
end