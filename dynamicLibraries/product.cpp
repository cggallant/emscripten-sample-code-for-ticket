#include <cstdlib>
#include <cstring>
#include <emscripten.h>

extern "C" {

  // Functions that are part of validate_core.cpp:
  extern int ValidateValueProvided(const char* value);

  EMSCRIPTEN_KEEPALIVE
  int ValidateName(char* name, int maximum_length)
  {
    // Validation 1: A name must be provided
    if (ValidateValueProvided(name) == 0)
    {
      return 0;
    }

    // Validation 2: A name must not exceed the specified length
    if (strlen(name) > maximum_length)
    {
      return 0;
    }

    // Everything is ok (no issues with the name)
    return 1;
  }

}
