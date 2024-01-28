#include <string.h>
#include "./src/htmc.h"

void _index();

int main(int argc, char **argv) {
  _index();
}

void _index() {
  htmc_begin;

  body(
    h1("HTMC 1.1"),
    h2("Hello World"),
    h3("I Hate HTML"),
    p("Supports body, h1..3 and p tags")
  );

  htmc_end;
}