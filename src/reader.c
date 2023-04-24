#include "tree.h"
#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

tree_t reader(const char str[]) {
  // char numero[500] = {};  /* C23 */
  char numero[500] = {'\0'};
  uint32_t line = 1, key = 1;
  tree_t tree;

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
      memset(numero, '\0', strlen(numero));
      break;
    case '+':
      tree_insert(&tree, 0, SUM);
      break;
    case '-':
      tree_insert(&tree, 0, MINUS);
      break;
    case '*':
      tree_insert(&tree, 0, MULT);
      break;
    case '/':
      tree_insert(&tree, 0, DIV);
      break;
    case '^':
      tree_insert(&tree, 0, POW);
      break;
    case '\n':
      line++;
      break;
    case ' ':
    case '\t':
      break;
    default:
      printf("(linha:%d letra:%zu) Caracter desconhecido: %c", line, i, str[i]);
      // TODO free_tree(&tree.raiz);
      tree.situacao = ERR;
      return tree;
    }
  }
  tree.situacao = OK;
  return tree;
}

node_t aaa() { return (node_t){.left = NULL, .right = NULL, .valor = 0}; }

struct {
  int a;
  int b;
} foo() {
  typeof(foo()) st = {.a = 2, .b = 3};
  return st;
}

void bar() { typeof(foo()) z = foo(); }
