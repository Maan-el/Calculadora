#ifndef CUSTOM_TYPES_H_
#define CUSTOM_TYPES_H_

#include <stdint.h>

enum token {
  NUMBER,
  OPERATION_SUM,
  OPERATION_MINUS,
  OPERATION_MULT,
  OPERATION_DIV,
  DOT,
  SPACE,
  NEW_LINE,
  UNKNOWN
};

// Estou usando a union e o enum para permitir uma "implementação" de um tipo
// algébrico https://en.wikipedia.org/wiki/Algebraic_data_type nessa linguagem
// anêmica
// O enum simboliza qual valor está contido na union, leia-o antes de acessar o
// valor na union, pois acessar uma variável que não está sendo usada é UB
enum val_valido { NUM_INT, NUM_DOUBLE, OPERACAO, ERROR };

typedef struct valor {
  union {
    // Vai ser lento em sistemas 32 bits
    // Não é problema meu >:3c
    int64_t int_val;
    double d_val;
    char op_val;
  };
  enum val_valido valido;
} valor_t;

#endif // CUST_TYPES_H_
