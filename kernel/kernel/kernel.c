#include <stdio.h>

#include <kernel/tty.h>

void kernel_main()
{
  /* Initialize terminal interface */
  terminal_init();

  terminal_write_string("Hello, kernel world!\n");
}