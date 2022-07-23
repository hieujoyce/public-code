.model small
.stack 100
.data
    tb1 db 13, 10, "Nhap msv: $"
    msv db "AT160419"
    ten db 13, 10, "Ten: Nguyen Trung Hieu$"
    tb2 db 13, 10, "Nhap sai. Nhap lai.$"
    tb3 db 13, 10, "Nhap chuoi bat ki: $"
    tb4 db 13, 10, "Chuoi dao nguoc la: $"
    strMsv db 100 dup("$")
    str1 db 100 dup("$")
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
            mov cx, 0
            mov cl, [str1 + 1]
            lea si, [str1 + 2]
        pushNganXep:
            mov dx, [si]
            push dx
            inc si
            loop pushNganXep            
            mov cx, 0
            mov cl, [str1 + 1]
            mov ah, 2
        hienthi:
            pop dx
            int 21h
            loop hienthi
        mov ah, 4ch
        int 21h
    main endp
end