#include <string.h>

char* strncat(char* __restrict dstPtr, const char* __restrict srcPtr, size_t n)
{
  char* dst = dstPtr;
  const char* src = srcPtr;
  // Find end of dst
  int i = 0;
  while(dst[i] != '\0') i++;

  /* Copies n chars of src to (dst + i), that is after the last character after
  the null terminator */
  strncpy(dst + i, src, n);
  return dst;
}