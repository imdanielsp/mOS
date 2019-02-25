CC = g++
CC_FLAGS = -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore
AS = as
AS_FLAGS = --32
LD = ld
LD_FLAGS = -melf_i386

OBJECTS = loader.o kernel.o terminal.o vga.o strlen.o

%.o: %.cpp
	$(CC) $(CC_FLAGS) -o $@ -c $<

%.o: %.s
	$(AS) $(AS_FLAGS) -o $@ $<

kernel.bin: linker.ld $(OBJECTS)
	$(LD) $(LD_FLAGS) -T $< -o $@ $(OBJECTS)

install: kernel.bin
	sh iso.sh

run: install
	qemu-system-i386 -cdrom mOS.iso

clean:
	rm -f $(OBJECTS)
	rm -f isodir/boot/kernel.bin
