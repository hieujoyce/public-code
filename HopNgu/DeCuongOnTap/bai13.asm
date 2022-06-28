.model small
.stack 100
.data
    tbTenSV db 13, 10, "Ten SV: $"
    tbNhapTenSV db "Nhap ten sinh vien: $"
    tbNhapTenFile db 13, 10, "Nhap ten file: $"
    tbNhapNdFile db 13, 10, "Nhap noi dung file: $"
    fnoidung db 100 dup("$")
    fname db 100 dup("$")
    msv db 13, 10, "MSV: AT160419$"
    tenSv db 100 dup("$")
    fhandle dw ?
.code 
    main proc
        mov ax, @data
        mov ds, ax
        mov ah, 9
        lea dx, tbNhapTenSV
        int 21h
        mov ah, 10
        lea dx, tenSv
        int 21h
        mov ah, 9
        lea dx, tbTenSV
        int 21h
        lea dx, [tenSv + 2]
        int 21h
        lea dx, msv
        int 21h 
        lea dx, tbNhapTenFile
        int 21h
        
        mov ah, 10
        lea dx, fname
        int 21h
        
        lea si, [fname + 2]
        mov cx, 0
        mov cl, [fname + 1]
        loop1:
        inc si
        loop loop1
        mov [si], 0
               
        mov ah, 3ch
        lea dx, [fname + 2]
        mov cl, 0
        int 21h
        mov fhandle, ax
        
        mov ah, 9
        lea dx, tbNhapNdFile
        int 21h
        mov ah, 10
        lea dx, fnoidung
        int 21h
        
        mov ah, 40h
        mov bx, fhandle
        lea dx, [fnoidung + 2]
        mov cx, 0
        mov cl, [fnoidung + 1]
        int 21h
        
        mov ah, 3eh
        mov bx, fhandle
        int 21h
        
        
        mov ah, 4ch
        int 21h
    main endp
end