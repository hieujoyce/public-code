.model small
.stack 100h
.data
    strNhap db "Hay nhap ki tu bat ki: $"
    strKq db 13, 10, "Ki tu nhan duoc la: $"
    kitu db ?  
.code
    main proc
        mov ax, @data
        mov ds, ax
        
        lea dx, strNhap
        mov ah, 9
        int 21h
        
        mov ah, 1
        int 21h
        
        mov kitu, al
        
        mov ah, 9
        lea dx, strKq
        int 21h
        
        mov dl, kitu
        mov ah, 2
        int 21h
        
        
    main endp
end