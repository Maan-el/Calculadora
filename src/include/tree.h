#ifndef TREE_H_
#define TREE_H_

#include <stdint.h>

// Tipos de informação que podem estar contido em um node
// Permitem definir se deve continuar descendo a árvore ou retornar o valor
typedef enum token {
  NUMBER = 1,
  SUM = 2,
  MINUS = 3,
  MULT = 4,
  POW = 5,
  DIV = 6,
  // UNKNOWN = 99,
} token_t;

typedef enum tipo_valor {
  INT = 0,
  DOUBLE = 1,
  OPERACAO = 2,
} tipo_valor_t;

// Estou usando a union e o enum para permitir uma "implementação" de um tipo
// algébrico https://en.wikipedia.org/wiki/Algebraic_data_type nessa linguagem
// anêmica
// Esse tipo, em específico: https://en.wikipedia.org/wiki/Tagged_union
// O enum simboliza qual valor está contido na union, leia-o antes de acessar o
// valor na union, pois acessar uma variável que não está sendo usada é UB
typedef struct valor {
  union {
    // Vai ser lento em sistemas 32 bits
    // Não é problema meu >:3c
    int64_t int_val;
    double d_val;
    token_t opr_val;
  };
  tipo_valor_t tipo;
} valor_t;

typedef struct node {
  struct node *left;
  struct node *right;
  valor_t valor;
  // uint32_t key;
} node_t;

typedef struct tree {
  union {
    node_t *raiz;
    char *err;
  };
  enum {
    OK = 0,
    ERR = 1,
  } situacao;
} tree_t;

static node_t *new_node(void);

void tree_insert(tree_t *tree, const char *num, const token_t token);

#endif // TREE_H_
