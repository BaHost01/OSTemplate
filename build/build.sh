#!/bin/bash
cd ..

echo "[XMPL] Build..."

nasm -f bin boot/boot.asm -o boot.bin

clang -ffreestanding -c kernel/kernel.c -o kernel.o
clang -ffreestanding -c kernel/syscalls.c -o syscalls.o
clang -ffreestanding -c kernel/isr.c -o isr.o
clang -ffreestanding -c lua/lua_embed.c -o lua_embed.o

ld -T kernel/linker.ld -o kernel.bin kernel.o syscalls.o isr.o lua_embed.o --oformat binary

dd if=/dev/zero of=image/xmpl.img bs=512 count=2880
mkfs.fat image/xmpl.img

dd if=boot.bin of=image/xmpl.img conv=notrunc
dd if=kernel.bin of=image/xmpl.img seek=1 conv=notrunc

echo "[XMPL] Run..."
qemu-system-x86_64 -drive format=raw,file=image/xmpl.img
