# Declare constants for the multiboot header.
.set ALIGN,     1<<0              # align loaded modules on page boundaries
.set MEMINFO,   1<<1              # provide memory map
.set FLAGS,     ALIGN | MEMINFO   # this is the Multiboot 'flag' field
.set MAGIC,     0x1BADB002        # 'magic number' lets bootloader find the header
.set CHECKSUM,  -(MAGIC + FLAGS)  # checksum of above, to prove we are multibot

# Declare a header as in the Multiboot Standard
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

# Reserve a stack for the initial thread.
.section .bss
.align 16
stack_bottom:
.skip 16384 # 16KiB
stack_top:

# Kernel entry point
.section .text
.global _start
.type _start, @function
_start:
    mov $stack_top, %esp

    # Call the global constructors
    call _init

    # Transfer control to the main kernel
    call kernel_main

    # Hang if kernel_main unexpectedly returns.
    cli
1:  hlt
    jmp 1b

/*
Set the size of the _start symbol to the current location '.' minus its start.
This is useful when debugging or when you implement call tracing.
*/
.size _start, . - _start
