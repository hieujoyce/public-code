.model small
.stack 100
.data
    tb1 db 13, 10, "Nhap msv: $"
    msv db "AT160419"
    strMsv db 100 dup("$")
    tb2 db 13, 10, "MSV sai. Nhap lai.$"
    ten db 13, 10, "Ten: Nguyen Trung Hieu$"
    tb3 db 13, 10, "Nhap n = $"
    tb4 db 13, 10, "n! = $"
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
            lea si, msv
            lea di, [strMsv + 2]
            repe cmpsb
            je next1
            print tb2
            jmp nhap
        next1:
            print ten
            print tb3
            mov ah, 1
            int 21h
            sub al, 48
            mov cx, 0
            mov cl, al
            print tb4
            mov bx, 1
            mov ax, 1
        
        giaithua:
            mul bx
            inc bx
            loop giaithua
            call intToString
        mov ah, 4ch
        int 21h
    main endp
    intToString proc
        mov cx, 0
        mov bx, 10
        chia10:
            mov dx, 0
            div bx
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
            loop hienthi
            ret
    intToString endp
end 