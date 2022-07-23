.model small
.stack 100
.data
    tb1 db 13, 10, "Nhap msv: $"
    msv db "AT160419"
    ten db 13, 10, "Ten: Nguyen Trung Hieu$"
    tb2 db 13, 10, "Nhap sai. Nhap lai.$"
    tb3 db 13, 10, "Nhap chuoi 1: $"
    tb4 db 13, 10, "Nhap chuoi 2: $"
    tb5 db 13, 10, "Giong$"
    tb6 db 13, 10, "Khong Giong$"
    strMsv db 100 dup("$")
    str1 db 100 dup("$")
    str2 db 100 dup("$")
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
            scanf strMsv
            cld
            mov cx, 8
            lea si, [msv]
            lea di, [strMsv + 2]
            repe cmpsb
            je next1
            print tb2
            jmp nhap
        next1:
            print tb3
            scanf str1
            print tb4
            scanf str2
            mov al, [str1 + 1]
            mov bl, [str2 + 1]
            cmp al, bl
            jne khongGiong
            cld
            mov cl, [str1 + 1]
            lea si, [str1 + 2]
            lea di, [str2 + 2]
            repe cmpsb
            jne khongGiong
        giong:
            print tb5
            jmp exit
        khongGiong:
            print tb6
        exit:            
            mov ah, 4ch
            int 21h
    main endp
end