[org 0x7c00]

mov bx, 0x1000
mov dh, 20

mov ah, 0x02
mov al, dh
mov ch, 0
mov cl, 2
mov dh, 0
mov dl, 0x00
int 0x13

jmp 0x0000:0x1000

times 510-($-$$) db 0
dw 0xaa55
