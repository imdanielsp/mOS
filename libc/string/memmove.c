#include <string.h>

void* memmove(void* dstPtr, const void* srcPtr, size_t size)
{
  unsigned char* dst = (unsigned char*) dstPtr;
  const unsigned char* src = (const unsigned char*) srcPtr;
  if (dst < src) {
    for (size_t i = 0; i < size; i++)
      dst[i] = src[i];
  } else {
    for (size_t i = size; i != 0; i--)
      dst[i-1] = src[i-1];
  }
  return dstPtr;
}
