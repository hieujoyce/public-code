.model small
.stack 100
.data
    tb1 db 13, 10, "Nhap msv: $"
    msv db "AT160419"
    tb2 db 13, 10, "Nhap sai. Nhap lai.$"
    tb3 db 13, 10, "Nhap chuoi so: $"
    ten db 13, 10, "Ten: Nguyen Trung Hieu$"
    tb4 db 13, 10, "So luong so am la: $"
    tb5 db 13, 10, "So luong so duong la: $"
    strMsv db 100 dup("$")
    so10 dw 10
    so5 dw 5
    str1 db 100 dup("$")
    dem1 dw 0
    dem2 dw 0
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
            print ten
            print tb3
            scanf str1
            print tb4
            lea si, [str1 + 2]
        lap:
            mov dx, [si]
            cmp dl, ","
            je tangDem1
            cmp dl, "$"
            je next2
            cmp dl, "-"
            je tangDem2
            inc si
            jmp lap
        tangDem1:
            inc dem1
            inc si
            jmp lap
        tangDem2:
            inc dem2
            inc si
            jmp lap    
        next2:
            mov ax, dem2
            call intToStr
            print tb5
            mov ax, dem1
            sub ax, dem2
            call intToStr    
        mov ah, 4ch
        int 21h
    main endp
    intToStr proc
        mov cx, 0
        chia10:
            mov dx, 0
            div so10
            push dx
            inc cx
            cmp ax, 0
            je hienthi
            jmp chia10
        hienthi:
            pop dx
            add dl, 48
            mov ah, 2
            int 21h
        ret
    intToStr endp
end