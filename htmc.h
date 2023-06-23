#ifndef HTMC_H
#define HTMC_H

#include <stdio.h>

typedef unsigned long long ull;

typedef struct _htmc_element_
{
  char *content;
  char *clazz;
  char *tag;
  char *id;
} HTMC_Element_t;

extern ull elementCount;
// extern FILE* outputFile;

void __htmc_begin(char *fPath);
int  __htmc_end(void);

void __body(ull, ...);
void __header(ull, ...);

HTMC_Element_t __register_element(
  char *tag,
  char* id,
  char *clazz,
  char* content
);

#define N "\'\'"
#define htmc_begin int main(int argc, char **argv) {__htmc_begin(argv[0]);
#define htmc_end return __htmc_end();}

#define header(...) __header(elementCount, __VA_ARGS__)
#define body(...) __body(elementCount, __VA_ARGS__)

#define p(text, clazz, id) __register_element("p", id, clazz, text)
#define h1(text, clazz, id) __register_element("h1", id, clazz, text)
#define h2(text, clazz, id) __register_element("h2", id, clazz, text)

#endif