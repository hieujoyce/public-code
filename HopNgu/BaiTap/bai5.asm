.model small
.stack 100h
.data
    strGM db 13, 10, "Good morning! $"
    strGA db 13, 10, "Good afternoon! $"
    strGE db 13, 10, "Good everning! $"
    strNhap db 13, 10, "Hay nhap 1 ki tu(S, s, T, t, C, c): $"
    strNhapSai db 13, 10, "Ban hay nhap sai ki tu, vui long nhap lai.$"
.code
    main proc
        mov ax, @data
        mov ds, ax
        
        nhap:
        mov ah, 9
        lea dx, strNhap
        int 21h
        
        mov ah, 1
        int 21h
        
        cmp al, "S"
        je chaoBuoiSang
        cmp al, "s"
        je chaoBuoiSang
        
        cmp al, "T"
        je chaoBuoiSang
        cmp al, "t"
        je chaoBuoiSang
        
        cmp al, "C"
        je chaoBuoiSang
        cmp al, "c"
        je chaoBuoiSang         
                 
        jmp nhapSai
        
        chaoBuoiSang:
        mov ah, 9
        lea dx, strGM
        int 21h
        jmp thoat
        
        chaoBuoiChieu:
        mov ah, 9
        lea dx, strGA
        int 21h
        jmp thoat
        
        chaoBuoiToi:
        mov ah, 9
        lea dx, strGE
        int 21h
        jmp thoat
        
        nhapSai:
        mov ah, 9
        lea dx, strNhapSai
        int 21h
        jmp nhap
        
        thoat:
        mov ah, 4CH
        int 21h
        
            
    main endp
end