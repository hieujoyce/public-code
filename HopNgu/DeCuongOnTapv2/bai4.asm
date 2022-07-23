.model small
.stack 100
.data
    tb1 db 13, 10, "Nhap msv: $"
    msv db "AT160419"
    tb2 db 13, 10, "Nhap sai. Nhap lai.$"
    tb3 db 13, 10, "Nhap chuoi so: $"
    ten db 13, 10, "Ten: Nguyen Trung Hieu$"
    tb4 db 13, 10, "So luong so chia het cho 5 la: $"
    strMsv db 100 dup("$")
    so10 dw 10
    so5 dw 5
    str1 db 100 dup("$")
    dem dw 0
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
            mov ax, 0
        lap:
            mov dx, [si]
            cmp dl, ","
            je kiemTra
            mul so10
            mov dx, [si]
            mov dh, 0
            sub dl, 48
            add ax, dx
            jmp next2
        kiemTra:
            mov dx, 0
            div so5
            cmp dx, 0
            jne next3
            inc dem
            mov ax, 0
        next3:
            mov ax, 0    
        next2:
            inc si    
            loop lap
            mov ax, dem
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