```
Include the example that you want in `main.c' as follows:
  #define UV_MANGO_IMPL // {header name}_IMPL
  #include "uv_mango.h"

Then in main function call the function
  uv_mango(); // {header name}();

Run `build.sh' to build the example

Dependencies:
- raylib (tested with v4.5) `brew install raylib'
```
