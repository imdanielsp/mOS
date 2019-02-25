#include "terminal.h"
#include "gdt.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*constructor)();

static constructor start_ctors;
static constructor end_ctors;

/// Initialize the constructors
void initConstructors()
{
    for (constructor* ctors = &start_ctors; *ctors != end_ctors; ctors++)
    {
        (*ctors)();
    }
}

/// Entry point of the kernel
void kernelMain(void* multiboot, unsigned int magicnumber)
{
    mOS::GlobalDescriptorTable gdt;

    mOS::Terminal term;
    term.writeString("Hello kernel world\n");
}

#ifdef __cplusplus
}
#endif