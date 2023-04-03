#ifndef TREE_H_
#define TREE_H_

#include <stdint.h>
/* #include <stdarg.h> */
/* typedef struct va_list ; */

enum val_valido { NUM_INT, NUM_DOUBLE, OPERACAO };

typedef struct valor {
  union {
    int64_t int_val;
    double d_val;
    char op_val;
  };
  enum val_valido valido;
} valor_t;

typedef struct node {
  node *pai;
  node *filhos[2];
  valor_t valor;
  /* int chave; */
} node_t;

typedef struct tree {
  node_t *raiz;
} tree_t;

tree_t create();

void insert(tree_t *tree);

#endif // TREE_H_
