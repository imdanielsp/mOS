#include <string.h>

void* memccpy(void* restrict dstPtr, const void* restrict srcPtr, size_t size)
{
  unsigned char* dst = (unsigned char*) dstPtr;
  const unsigned char* src = (const unsigned char*) srcPtr;
  for (size_t i = 0; i < size; i++)
    dst[i] = src[i];
  return dstPtr;
}
