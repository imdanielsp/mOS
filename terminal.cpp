#include "terminal.h"
#include "vga.h"
#include "string.h"

namespace mOS
{
    Terminal::Terminal()
        : m_row(0)
        , m_column(0)
        , m_color(VGA::entryColor(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK))
        , m_buffer(VGA::Address)
    {
        clearTerminal();
    }

    void Terminal::clearTerminal()
    {
        for (size_t y = 0; y < VGA::Height; y++) {
            for (size_t x = 0; x < VGA::Width; x++) {
                const size_t index = y * VGA::Width + x;
                m_buffer[index] = VGA::entry(' ', m_color);
            }
        }
    }

    void Terminal::putChar(char c)
    {
        if (c == '\n') {
            m_row++;
            m_column = 0;
        } else {
            const size_t index =  m_row * VGA::Width + m_column;
            m_buffer[index] = VGA::entry(c, m_color);
        }

        m_column++;
        // If we hit the max width, go a line down
        if (m_column == VGA::Width) {
            m_column = 0;
            m_row++;

            // If there aren't more rows, go up.
            // TODO: Implement scroll; idea, swap lines up
            if (m_row == VGA::Height) {
                m_row = 0;
            }
        }
    }

    void Terminal::write(const char* data, size_t len)
    {
        for (size_t i = 0; i < len; i++) {
            putChar(data[i]);
        }
    }

    void Terminal::writeString(const char* data)
    {
        write(data, strlen(data));
    }
} // mOS
