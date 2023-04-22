#include "tree.h"
#include <stdarg.h>
#include <stdlib.h>
#include <sys/cdefs.h>

// Essa função recebe a árvore de operações, o token com a operação e uma string
// _opcional_, que será o valor do número, caso contrário é ignorada
__attribute_nonnull__((1, 2)) void tree_insert(tree_t *tree, const char *num,
                                               const token_t token) {

  switch (token) {
  case NUMBER:

  case OPERATION_SUM:
  case OPERATION_MINUS:
  case OPERATION_MULT:
  case OPERATION_DIV:
  case OPERATION_POW:
  default:
    break;
  }
}

static inline void insert(tree_t *tree, const tipo_valor_t tipo,
                          const char val[]) {
  switch (tipo) {
  case NUM_INT:
  case NUM_DOUBLE:
  case OPERACAO:
  }
}

static node_t *new_node(void) {
  node_t *node = NULL;
  // Uma falha do calloc ocorrerá somente se acabar a memória disponível ou
  // ocorrer uma falha da biblioteca do sistema.
  // Em ambos os casos, chamar a função novamente me parece uma ideia decente
  while (node == NULL) {
    node = calloc(1, sizeof(node_t));
  }
  node->filhos[0] = NULL;
  node->filhos[1] = NULL;
  return node;
}
