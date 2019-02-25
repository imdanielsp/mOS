
#include "vga.h"

namespace mOS
{
    uint16_t* const VGA::Address = (uint16_t*) 0xB8000;

    const size_t VGA::Width = 80;

    const size_t VGA::Height = 25;

} // mOS
 