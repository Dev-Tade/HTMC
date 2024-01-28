#include <htmc.h>

#define TAG(__tag) (HTMC_Node_t){.tag=__tag, .id=id, .clazz=clazz, .content=content}

HTMC_Node_t _p(HTMC_NODE_CLIST) {
  return TAG("p");
}

HTMC_Node_t _h1(HTMC_NODE_CLIST) {
  return TAG("h1");
}

HTMC_Node_t _h2(HTMC_NODE_CLIST) {
  return TAG("h2");
}

HTMC_Node_t _h3(HTMC_NODE_CLIST) {
  return TAG("h3");
}