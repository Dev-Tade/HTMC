# HTMC
Hypertext Markup C.<br/>
Use C instead of HTML, only requires:
```c
#include <htmc.h>
```

## Practical Example
```c
#include "htmc.h"
// Link the file ./build/libhtmc.a
// -L<PATH TO LIBHTMC> -lhtmc

void _index(/* params if you wish */) { // 'index' is a builtin in C.
  htmc_begin; // If this directive is missing the program will crash.

  body(
    h1("Hello HTMC"), // Just the contents.
    _p("Lorem ipsum", "myid", "myclass") // Or params (ID and CLASS) via _<tag> 
  ); // DO NOT PUT A ',' AFTER LAST ELEMENT!!!

  htmc_end; // Finish HTML generation
}

/*
  When you call '_index(...)' it will generate the respective HTML and output it in stdout.
  Additionally can use 'HTMC_SetOutputFile(FILE *out)' to use another file for the generated HTML instead of stdout.
*/
```

### Have in Mind
1. This generates HTML at runtime
2. This is an unfinished project.
3. Has missing capabilities (currently implemented: body, h1, h2, h3 and p tags, header isn't implemented yet)
4. May be compatibility issues with other platforms

### TODO:
  1. Add more tags
  2. Add support for other params (eg: src)