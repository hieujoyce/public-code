.model small
.stack 100
.data
    tb1 db 13, 10, "Nhap ten: $"
    ten db "Nguyen Trung Hieu"
    tb2 db 13, 10, "Nhap sai. Nhap lai.$"
    tb3 db 13, 10, "Nhap ten file muon doc du lieu: $"
    tb4 db 13, 10, "Noi dung: $"
    strTen db 100 dup("$")
    fname db 100 dup("$")
    fnoidung db 100 dup("$")
    fhandle dw ?
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
            print tb3
            scanf fname
            mov cx, 0
            mov cl, [fname + 1]
            lea si, [fname + 2]
            add si, cx
            mov [si], 0          
            print tb4
            mov ah, 3dh
            lea dx, [fname + 2]
            mov al, 0
            int 21h
            mov fhandle, ax
            mov ah, 3fh
            mov bx, fhandle
            lea dx, fnoidung
            mov cx, 99
            int 21h
            print fnoidung
        mov ah, 4ch
        int 21h
    main endp
end