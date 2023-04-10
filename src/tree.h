#ifndef TREE_H_
#define TREE_H_

#include "custom_types.h"

typedef struct node {
  struct node *pai;
  struct node *filhos[2];
  valor_t valor;
  /* int chave; */
} node_t;

typedef struct tree {
  node_t *raiz;
} tree_t;

tree_t create();

static node_t *new_node();

void insert(tree_t *tree);

#endif // TREE_H_
