#ifndef TREE_H_
#define TREE_H_

#include <inttypes.h>
#include <sys/types.h>

// Tipos de informação que podem estar contido em um node
// Permitem definir se deve continuar descendo a árvore ou retornar o valor
typedef enum token {
  NUMBER = 1,
  OPERATION_SUM = 2,
  OPERATION_MINUS = 3,
  OPERATION_MULT = 4,
  OPERATION_POW = 5,
  OPERATION_DIV = 6,
  // UNKNOWN = 99,
} token_t;

// Estou usando a union e o enum para permitir uma "implementação" de um tipo
// algébrico https://en.wikipedia.org/wiki/Algebraic_data_type nessa linguagem
// anêmica
// O enum simboliza qual valor está contido na union, leia-o antes de acessar o
// valor na union, pois acessar uma variável que não está sendo usada é UB
typedef enum tipo_valor {
  NUM_INT = 0,
  NUM_DOUBLE = 1,
  OPERACAO = 2,
} tipo_valor_t;

typedef struct valor {
  union {
    // Vai ser lento em sistemas 32 bits
    // Não é problema meu >:3c
    int64_t int_val;
    double d_val;
    char opr_val;
  };
  tipo_valor_t tipo;
} valor_t;

typedef struct node {
  struct node *filhos[2];
  valor_t valor;
} node_t;

typedef struct tree {
  enum {
    OK = 0,
    ERR = 1,
  } situacao;
  node_t *raiz;
} tree_t;

static node_t *new_node(void);

void tree_insert(tree_t *tree, const char *num, const token_t token);

#endif // TREE_H_
