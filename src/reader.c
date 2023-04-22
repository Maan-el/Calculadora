#include "tree.h"
#include <ctype.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

static inline void clear_string(char *str) {
  str = memset(str, '\0', sizeof(*str));
} // Garantindo que a string é nula

tree_t __attribute__((__pure__)) reader(const char str[]) {
  char numero[500] = {'\0'};
  uint32_t line = 1;
  tree_t tree = {.situacao = OK}, err_tree = {.situacao = ERR};

  for (size_t i = 0; str[i] != '\0'; i++) {
    switch (str[i]) {
    case '.':
    case '0' ... '9': // gnu extension
      strcat(numero, &str[i]);
      while (isalnum(str[i + 1]) || str[i + 1] == '.') {
        strcat(numero, &str[i + 1]);
        i++;
      }
      tree_insert(&tree, numero, NUMBER);
      clear_string(numero);
      break;
    case '+':
      tree_insert(&tree, 0, OPERATION_SUM);
      break;
    case '-':
      tree_insert(&tree, 0, OPERATION_MINUS);
      break;
    case '*':
      tree_insert(&tree, 0, OPERATION_MULT);
      break;
    case '/':
      tree_insert(&tree, 0, OPERATION_DIV);
      break;
    case '^':
      tree_insert(&tree, 0, OPERATION_POW);
      break;
    case '\n':
      line++;
      break;
    case ' ':
    case '\t':
      break;
    default:
      printf("(linha:%d letra:%zu) Caracter desconhecido: %c", line, i, str[i]);
      // free_tree(&tree);
      return err_tree;
    }
  }
  return tree;
}
