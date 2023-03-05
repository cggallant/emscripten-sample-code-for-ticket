#include <cstdlib>
#include <emscripten.h>

extern "C" {

  // Function that will be imported from JavaScript
  extern void UpdateHostAboutError(const char* error_message);

  EMSCRIPTEN_KEEPALIVE
  int ValidateValueProvided(const char* value, const char* error_message)
  {
    // If the string is null or the first character is the null terminator then the string is empty
    if ((value == NULL) || (value[0] == '\0'))
    {
      UpdateHostAboutError(error_message);
      return 0;
    }

    // Everything is ok
    return 1;
  }

}
