#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#include <htmc.h>

FILE *__HTMC_OutputFile = NULL;
uint8_t flags = 0;

static void __HTMC_Checks() {
  if (__HTMC_OutputFile == NULL) __HTMC_OutputFile = stdout;
  else if (!(flags & 0x4)) {fprintf(stderr, "Missing 'htmc_begin' directive\n"); exit(1);}
  else return;
}

void __HTMC_Begin(void) {
  flags |= 0x4;
  __HTMC_Checks();
  fputs("<!DOCTYPE html>\n", __HTMC_OutputFile);
  fputs("<html>\n", __HTMC_OutputFile);
}

void __HTMC_End(void) {
  __HTMC_Checks();
  fputs("</html>", __HTMC_OutputFile);
  flags |= (~0x4);
}

HTMC_Node_t HTML_Node(char *tag, char *id, char *clazz, char *content) {
  HTMC_Node_t node;
  node.tag = tag;
  node.id = id;
  node.clazz = clazz;
  node.content = content;

  // ++elementCount;
  return node;
}

void HTMC_SetOutputFile(FILE *fp) {
  __HTMC_OutputFile = fp;
}

HTMC_Node_t __HTMC_EndNodeList(void) {
  return (HTMC_Node_t) {
    .tag = "_END",
    .content = htmc_empty,
    .clazz = htmc_empty,
    .id = htmc_empty,
  };
}

void __HTMC_Process(HTMC_Node_t node) {
  __HTMC_Checks();
  fprintf(
    __HTMC_OutputFile,
    "<%s id=\"%s\" class=\"%s\">%s</%s>\n",
    node.tag,
    node.id,
    node.clazz,
    node.content,
    node.tag
  );
}

int __HTMC_CMP(HTMC_Node_t a, HTMC_Node_t b) {
  return strcmp(a.tag, b.tag) == 0 ? 1 : 0;
}

void __HTMC_Body(HTMC_Node_t *nodes) {
  size_t i=0;
  while (__HTMC_CMP(nodes[i], __HTMC_EndNodeList()) == 0) {
    __HTMC_Process(nodes[i++]);
  }
}