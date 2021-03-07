#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/keios.kernel isodir/boot/keios.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "keios" {
	multiboot /boot/keios.kernel
}
EOF
grub-mkrescue -o keios.iso isodir
