#include "tree.h"
#include <stdlib.h>

tree_t create() {
  tree_t tree;
  tree.raiz = new_node();

  return tree;
}

static node_t *new_node() {
  node_t *node = calloc(1, sizeof(node_t));
  if (node != NULL) {
    node->filhos[0] = NULL;
    node->filhos[1] = NULL;
  }
  return node;
}
