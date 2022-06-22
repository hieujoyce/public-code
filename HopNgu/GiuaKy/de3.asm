.model small
.stack 100
.data
    str db 100 dup("$")
    tbNhap db "Hay nhap vao ma sv: $"
    tbKQ db 13, 10, "Ma sinh vien la: $"
    tbHe16 db 13, 10, "He so 16 cua 3 so cuoi MSV la: $"
.code
    main proc
        mov ax, @data
        mov ds, ax
        
        mov ah, 9
        lea dx, tbNhap
        int 21h
        
        mov ah, 10
        lea dx, str
        int 21h
        
        mov ah, 9
        lea dx, tbKQ
        int 21h 
        lea dx, [str + 2]
        int 21h
        
        mov cx, 0
        mov cl, 3
        lea si, [str + 7]
        mov ax, 0
        mov bx, 10
        
        chuyensohe10:
        mul bx
        mov dl, [si]
        sub dl, 48
        add ax, dx
        inc si
        loop chuyensohe10
        
        mov bx, 16
        mov cx, 0
        mov cl, 16
        mov si, 0
        chuyensohe16:
        mov dx, 0
        div bx
        push dx
        inc si
        cmp ax, 0
        jne chuyensohe16
        
        mov ah, 9
        lea dx, tbHe16
        int 21h
               
        mov ah, 2
        mov cx, 16
        sub cx, si
        hienthi1:
        mov dl, 48
        int 21h
        loop hienthi1
  
        mov cx, si        
        hienthi2:
        pop dx
        cmp dl, 10
        je print_a
        cmp dl, 11
        je print_b
        cmp dl, 12
        je print_c
        cmp dl, 13
        je print_d
        cmp dl, 14
        je print_e
        cmp dl, 15
        je print_f
        
        add dl, 48
        jmp print
        
        print_a:
        mov dl, "A"
        jmp print
        print_b:
        mov dl, "B"
        jmp print
        print_c:
        mov dl, "C"
        jmp print
        print_d:
        mov dl, "D"
        jmp print
        print_e:
        mov dl, "E"
        jmp print 
        print_f:
        mov dl, "F"
        jmp print
        
        print:
        int 21h
        loop hienthi2     
             
                  
        mov ah, 4ch
        int 21h    
    main endp
end