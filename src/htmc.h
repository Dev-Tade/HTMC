#ifndef HTMC_H
#define HTMC_H

#include <stdio.h>

typedef struct {
  char *content;
  char *clazz;
  char *tag;
  char *id;
} HTMC_Node_t;

void HTMC_SetOutputFile(FILE *fp);

HTMC_Node_t HTML_Node(char *tag, char *id, char *clazz, char *content);
HTMC_Node_t __HTMC_EndNodeList(void);

void __HTMC_Begin(void);
void __HTMC_End(void);
void __HTMC_Body(HTMC_Node_t *nodes);

#define HTMC_NODE_CLIST char *content, char *id, char *clazz
#define htmc_empty ""

#define htmc_begin __HTMC_Begin()
#define htmc_end __HTMC_End()
#define body(...) __HTMC_Body((HTMC_Node_t[]){__VA_ARGS__, __HTMC_EndNodeList()})

HTMC_Node_t _p(HTMC_NODE_CLIST);
HTMC_Node_t _h1(HTMC_NODE_CLIST);
HTMC_Node_t _h2(HTMC_NODE_CLIST);
HTMC_Node_t _h3(HTMC_NODE_CLIST);

#define p(contents) _p(contents, htmc_empty, htmc_empty)
#define h1(contents) _h1(contents, htmc_empty, htmc_empty)
#define h2(contents) _h2(contents, htmc_empty, htmc_empty)
#define h3(contents) _h3(contents, htmc_empty, htmc_empty)

#endif