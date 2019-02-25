#ifndef _KERNEL_TTY_H
#define _KERNEL_TTY_H

#include <stdint.h>
#include <stddef.h>

namespace mOS
{
    class Terminal
    {
      public:
        /// Default constructor
        Terminal();

        ~Terminal() = default;

        /// Non-copyable
        Terminal(const Terminal&) = delete;

        /// Non-movable
        Terminal(const Terminal&&) = delete;

        /// Non-assignable
        Terminal& operator=(const Terminal&) = delete;

        /// Writes a character to the terminal
        /// @param[in] c the character to 
        void putChar(char c);

        /// Writes a string buffer in to the terminal
        /// @param[in] data the buffer
        /// @param[in] len the size of the buffer
        void write(const char* data, size_t len);

        /// Writes string to the terminal
        /// @param[in] data is the string
        void writeString(const char* data);

      private:
        void clearTerminal();

        static uint16_t* const VGAAddress;

        size_t m_row;
        size_t m_column;
        uint8_t m_color;
        uint16_t* m_buffer;
    };
} // mOS Namespace

#endif