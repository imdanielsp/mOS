#ifndef _KERNEL_GDT_H
#define _KERNEL_GDT_H

#include <stdint.h>
#include "utils.h"

namespace mOS
{
    class GlobalDescriptorTable
    {
      public:
        class SegmentDescriptor
        {
          public:
            SegmentDescriptor(uint32_t base, uint32_t limit, uint8_t type);

            ~SegmentDescriptor() = default;

            NON_COPYABLE(SegmentDescriptor);

            uint32_t getBase();

            uint32_t getLimit();

          private:
            uint16_t limitLow;
            uint16_t baseLow;
            uint8_t baseHigh;
            uint8_t type;
            uint8_t flagsLimitHigh;
            uint8_t baseVhi;

        } __attribute__((packed));

        /// Default const
        GlobalDescriptorTable();

        /// Default dest
        ~GlobalDescriptorTable() = default;

        NON_COPYABLE(GlobalDescriptorTable);

        uint16_t getCodeSegmentSelector() const;
        uint16_t getDataSegmentSelector() const;

      private:
        SegmentDescriptor nullSegmentSelector;
        SegmentDescriptor unusedSegmentSelector;
        SegmentDescriptor codeSegmentSelector;
        SegmentDescriptor dataSegmentSelector;
    };
} // mOS


#endif