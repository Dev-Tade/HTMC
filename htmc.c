#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

#include <htmc.h>

ull elementCount;
FILE* outputFile = NULL;

// htmc_helpers fwd decl
char *htmc_helper_trimExtension(char *fPath);
void  htmc_helper_appendHtmlExt(char *fPath);

static inline void __htmc_begw(void)
{
  fprintf(outputFile, "<!DOCTYPE html>\n<html>\n");
}

static inline void __htmc_endw(void)
{
  fprintf(outputFile, "</html>");
}

void __htmc_begin(char *fPath)
{
  char *newExt = htmc_helper_trimExtension(fPath);
  htmc_helper_appendHtmlExt(newExt);

  outputFile = fopen(newExt, "w+");
  free(newExt);

  elementCount = 0;
  __htmc_begw();
}

int __htmc_end(void)
{
  __htmc_endw;
  return fclose(outputFile);
}

HTMC_Element_t __register_element(
  char *tag,
  char* id,
  char *clazz,
  char* content
){
  HTMC_Element_t element;
  element.tag = tag;
  element.id = id;
  element.clazz = clazz;
  element.content = content;

  ++elementCount;
  return element;
}

void __process_element(HTMC_Element_t element)
{
  if (!strcmp(element.tag, "p"))
  {
    fprintf(outputFile, "<p id=%s class=%s>%s</p>\n", element.id, element.clazz, element.content);
  } else if (!strcmp(element.tag, "h1"))
  {
    fprintf(outputFile, "<h1 id=%s class=%s>%s</h1>\n", element.id, element.clazz, element.content);
  } else if (!strcmp(element.tag, "h2"))
  {
    fprintf(outputFile, "<h2 id=%s class=%s>%s</h2>\n", element.id, element.clazz, element.content);
  }
}

void __body(ull ec, ...)
{
  va_list elements;
  va_start(elements, ec);
  fprintf(outputFile, "<body>\n");

  for (ull i=0; i<ec; ++i)
  {
    HTMC_Element_t element = va_arg(elements, HTMC_Element_t);
    fprintf(stdout, "eN: %llu | tag: %s | id: %s | class: %s | content: %s\n", i, element.tag, element.id, element.clazz, element.content);
    __process_element(element); // this one crashes
  }

  fprintf(outputFile, "</body>\n");
  va_end(elements);
}