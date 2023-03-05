#include <cstdlib>
#include <emscripten.h>

extern "C" {

  EMSCRIPTEN_KEEPALIVE
  int ValidateValueProvided(const char* value)
  {
    // If the string is null or the first character is the null terminator then the string is empty
    if ((value == NULL) || (value[0] == '\0'))
    {
      return 0;
    }

    // Everything is ok
    return 1;
  }

}
