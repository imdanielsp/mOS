# Tell the bootloader that this is a kernel
.set MAGIC, 0x1badb002
.set FLAGS, (1 << 0 | 1 << 1)
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
    .long MAGIC
    .long FLAGS
    .long CHECKSUM

# Kernel entry point
.section .text
.extern kernelMain
.global loader
loader:
    mov $kernel_stack, %esp
    push %eax
    push %ebx
    call kernelMain

# Halt the kernel incase that kernelMain returns (unlikely)
_stop:
    cli
    hlt
    jmp _stop

# Set up the stack for C++ programs
.section .bss
.space 2*1024*1024; # 2 MiB
kernel_stack:
