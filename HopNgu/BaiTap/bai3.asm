.model small
.stack 100h
.data
    strNhap db "Hay nhap ki tu bat ki: $"
    strKq1 db 13, 10, "Ki tu ke truoc la: $"
    strKq2 db 13, 10, "Ki tu ke sau la: $"
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
        lea dx, strKq1
        int 21h
                
        mov dl, kitu
        sub dl, 1        
        mov ah, 2
        int 21h
        
        mov ah, 9
        lea dx, strKq2
        int 21h
        
        mov dl, kitu
        add dl, 1
        mov ah, 2
        int 21h
        
        mov ah, 4CH
        int 21h 
    main endp
end