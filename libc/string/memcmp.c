#include <string.h>

int memcmp(const void* aPtr, const void* bPtr, size_t size)
{
  const unsigned char* a = (const unsigned char*) aPtr;
  const unsigned char* b = (const unsigned char*) bPtr;
  for (size_t i = 0; i < size; i++) {
    if (a[i] < b[i])
      return -1;
    else if (b[i] < a[i])
      return 1;
  }
  return 0;
}
