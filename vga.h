#ifndef ARCH_I386_VGA_H
#define ARCH_I386_VGA_H

#include <stdint.h>
#include <stddef.h>

namespace mOS
{
    enum VGAColor {
        VGA_COLOR_BLACK = 0,
        VGA_COLOR_BLUE = 1,
        VGA_COLOR_GREEN = 2,
        VGA_COLOR_CYAN = 3,
        VGA_COLOR_RED = 4,
        VGA_COLOR_MAGENTA = 5,
        VGA_COLOR_BROWN = 6,
        VGA_COLOR_LIGHT_GREY = 7,
        VGA_COLOR_DARK_GREY = 8,
        VGA_COLOR_LIGHT_BLUE = 9,
        VGA_COLOR_LIGHT_GREEN = 10,
        VGA_COLOR_LIGHT_CYAN = 11,
        VGA_COLOR_LIGHT_RED = 12,
        VGA_COLOR_LIGHT_MAGENTA = 13,
        VGA_COLOR_LIGHT_BROWN = 14,
        VGA_COLOR_WHITE = 15,
    };

    class VGA
    {
      public:
        ~VGA() = default;

        static uint16_t* const Address;
        static const size_t Width;
        static const size_t Height;

        static inline uint8_t entryColor(enum VGAColor fg, enum VGAColor bg)
        {
            return fg | bg << 4;
        }

        static inline uint16_t entry(unsigned char uc, uint8_t color)
        {
            return static_cast<uint16_t>(uc) | static_cast<uint16_t>(color) << 8;
        }
      private:
        // Make this 
        VGA();
        VGA(const VGA&);
        VGA(const VGA&&);
        VGA& operator=(const VGA&);

    };
} // mOS

#endif