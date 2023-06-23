#include <stdlib.h>
#include <string.h>
#include <htmc.h>

// TODO: these functions allocate && reallocate memory, its late my mind can't
//       properly think if the calculations r correct, i may fix it later. 
char *htmc_helper_trimExtension(char *fPath)
{
  ull counter=0, len=strlen(fPath);

  for (ull i=len; i>0; --i)
  {
    if (fPath[i] == '.') break;
    else ++counter;
  }

  ull nsize = (len-counter)+1;
  char *newstr = (char *)malloc(nsize);
  if (newstr == NULL)
  {
    fprintf(stderr, "trimExtension: Unable to allocate memory\n");
    exit(1);
  }

  strncpy(newstr, fPath, nsize-1);
  newstr[nsize] = '\0';

  return newstr;
}

void htmc_helper_appendHtmlExt(char *fPath)
{
  ull len = strlen(fPath);
  char *newExt = (char *)realloc(fPath, len+6);
  if (newExt == NULL)
  {
    fprintf(stderr, "appendHtmlExt: Unable to allocate memory\n");
    exit(1);
  }
  fPath = newExt;

  strncat(fPath, ".html", len+6);
  fPath[len+5] = '\0';
}