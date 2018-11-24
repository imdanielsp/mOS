#include <string.h>

char* strcat(char* __restrict dstPtr, const char* __restrict srcPtr)
{
  char* dst = dstPtr;
  const char* src = srcPtr;

  // Find end of dst
  int i = 0;
  while(dst[i] != '\0') i++;

  /* Copies src to (dst + i), that is after the last character after the null
  terminator */
  strcpy(dst + i, src);

  return dst;
}