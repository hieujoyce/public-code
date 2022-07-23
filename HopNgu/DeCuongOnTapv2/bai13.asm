.model small
.stack 100h
.data
    tb1 db 13, 10, "Nhap ten: $"
    ten db "Nguyen Trung Hieu"
    tb2 db 13, 10, "Nhap sai. Nhap lai.$"
    msv db 13, 10, "Msv: AT160419$"
    tb3 db 13, 10, "Nhap ten file: $"
    tb4 db 13, 10, "Nhap noi dung file: $"
    strTen db 100 dup("$")
    fname db 100 dup("$")
    fnoidung db 100 dup("$")
    fhandle dw 100 dup("$")
.code
    print macro str
        mov ah, 9
        lea dx, str
        int 21h
    endm
    scanf macro str
        mov ah, 10
        lea dx, str
        int 21h
    endm
    main proc
        mov ax, @data
        mov ds, ax
        mov es, ax
        nhap:
            print tb1
            scanf strTen
            cld
            mov cx, 17
            lea si, [ten]
            lea di, [strTen + 2]
            repe cmpsb
            je next1
            print tb2
            jmp nhap
        next1:
            print msv
            print tb3
            scanf fname
            print tb4
            scanf fnoidung  
            lea si, [fname + 2]
            mov cx, 0
            mov cl, [fname + 1]
            add si, cx
            mov [si], 0
            
            mov ah, 3ch
            lea dx, [fname + 2]
            mov cx, 0
            int 21h
            mov fhandle, ax
            
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