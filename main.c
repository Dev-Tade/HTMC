#include <htmc.h>

// TODO: Handle cases were compilation doesnt have the extension bc causes a crash rn

htmc_begin

  body(
    h1("Hello World",N,N),
    p("Lorem ipsum dolor sit amet consectetur adipisicing elit.",N,N)
  );

htmc_end