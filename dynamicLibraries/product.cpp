#include <cstdlib>
#include <cstring>
#include <emscripten.h>

extern "C" {

  // Functions that are part of validate_core.cpp:
  extern int ValidateValueProvided(const char* value, const char* error_message);

  // Function that will be imported from JavaScript
  extern void UpdateHostAboutError(const char* error_message);

  EMSCRIPTEN_KEEPALIVE
  int ValidateName(char* name, int maximum_length)
  {
    // Validation 1: A name must be provided
    if (ValidateValueProvided(name, "A Product Name must be provided.") == 0)
    {
      return 0;
    }

    // Validation 2: A name must not exceed the specified length
    if (strlen(name) > maximum_length)
    {
      UpdateHostAboutError("The Product Name is too long.");
      return 0;
    }

    // Everything is ok (no issues with the name)
    return 1;
  }

}
