# HTMC
Hypertext Markup C.<br/>
Use C instead of HTML, only requires:
```c
#include <htmc.h>
```

## Practical Example
```c
#include <htmc.h>

// This should be on its own file, take in mind:
// each htmc file goes to a separate and isolated Compilation Unit

htmc_begin
  body(
    h1("Hello HTMC",N,N),
    p("Lorem ipsum",N,N)
  );
htmc_end
```

### Have in Mind
1. This is an unfinished project.
2. Has missing capabilities (currently implemented: h1, h2 and p tags, header isn't impl yet)
3. May be compatibility issues with other platforms

### TODO:
  1. Fix possible memory errors
  2. Implement a tool to auto build HTMC
  3. Add more capabilities