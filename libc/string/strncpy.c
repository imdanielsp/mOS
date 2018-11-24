#include <string.h>

char* strncpy(char* __restrict dstPtr, const char* __restrict srcPtr, size_t n)
{
  char* dst = dstPtr;
  const char* src = srcPtr;
  for (size_t i = 0; i < n; i++)
    dst[i] = src[i];
  return dst;
}
