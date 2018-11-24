#include <string.h>
#include <stddef.h>

void* memchr(const void* ptr, int ch, size_t max)
{
  unsigned char* iter = (unsigned char*) ptr;
  unsigned char c = (unsigned char) ch;
  for (size_t i = 0; i < max; i++)
    if (iter[i] == c)
      return iter + i;
  return NULL;
}