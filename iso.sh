#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/mOS.kernel isodir/boot/mOS.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "mOS" {
	multiboot /boot/mOS.kernel
}
EOF
grub-mkrescue -o mOS.iso isodir