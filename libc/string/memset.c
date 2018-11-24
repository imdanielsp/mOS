#include <string.h>

void* memset(void* bufPtr, int value, size_t size)
{
  unsigned char* buf = (unsigned char*) bufPtr;
  for (size_t i = 0; i < size; i++)
    buf[i] = (unsigned char) value;
  return bufPtr;
}
