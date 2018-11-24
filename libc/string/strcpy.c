#include <string.h>

char* strcpy(char* __restrict dstPtr, const char* __restrict srcPtr)
{
  char* dst = dstPtr;
  const char* src = srcPtr;
  size_t i = 0;
  while(src[i] != '\0') {
    dst[i] = src[i];
    i++;
  }
  return dst;
}