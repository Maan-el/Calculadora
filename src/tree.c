#include "tree.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

static node_t *new_node(void) {
  node_t *node = NULL;
  // Uma falha do calloc ocorrerá somente se acabar a memória disponível ou
  // ocorrer uma falha da biblioteca do sistema.
  // Em ambos os casos, chamar a função novamente me parece uma ideia decente
  while (node == NULL) {
    node = calloc(1, sizeof(node_t));
  }
  node->left = NULL;
  node->right = NULL;
  return node;
}

// Essa função recebe a árvore de operações, o token com a operação e uma string
// _opcional_, que será o valor do número, caso contrário é ignorada
void tree_insert(tree_t *tree, const char num[], const token_t token) {
  uint64_t len = 0;
  node_t no;

  switch (token) {
  case NUMBER:
    // TODO Fazer um wrapper para conseguir compatibilidade com plataformas
    // 32-bits
    len = strlen(num);
    if (atol(num) != 0 || (num[0] == '0' && len == 1)) {
      no.valor.int_val = atol(num);
      no.valor.tipo = INT;
      break;
    } else {
      no.valor.int_val = atof(num);
      no.valor.tipo = DOUBLE;
      break;
    }
  case SUM:
    no.valor.tipo = OPERACAO;
    no.valor.opr_val = token;
    break;
  case MINUS:
    no.valor.tipo = OPERACAO;
    no.valor.opr_val = token;
    break;
  case MULT:
    no.valor.tipo = OPERACAO;
    no.valor.opr_val = token;
    break;
  case DIV:
    no.valor.tipo = OPERACAO;
    no.valor.opr_val = token;
    break;
  case POW:
    no.valor.tipo = OPERACAO;
    no.valor.opr_val = token;
    break;
  default:
    break;
  }
}
