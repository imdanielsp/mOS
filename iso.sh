#!/bin/sh

. ./build.sh

mkdir -p isodir/boot/grub

cp kernel.bin isodir/boot/kernel.bin

cat > isodir/boot/grub/grub.cfg << EOF
menuentry "mOS" {
    multiboot /boot/kernel.bin
}
EOF

grub-mkrescue -o mOS.iso isodir
