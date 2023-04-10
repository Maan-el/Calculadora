/* #include "reader.h" */

#include "custom_types.h"
#include <stdio.h>
#include <string.h>

static unsigned long int line = 0;

enum token tokenizer(char c) {
  switch (c) {
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
    return NUMBER;
  case '.':
    return DOT;
  case '+':
    return OPERATION_SUM;
  case '-':
    return OPERATION_MINUS;
  case '*':
    return OPERATION_MULT;
  case '/':
    return OPERATION_DIV;
  case ' ':
  case '\t':
    return SPACE;
  case '\n':
    return NEW_LINE;
  default:
    return UNKNOWN;
  }
}

void reader(char *str) {
  char numero[350];

  for (unsigned int i = 0; str[i] != '\0'; i++) {
    switch (tokenizer(str[i])) {
    case NUMBER:
      strcat(numero, &str[i]);
      break;
    case DOT:
      strcat(numero, &str[i]);
      break;
    case OPERATION_SUM:
      break;
    case OPERATION_MINUS:
      break;
    case OPERATION_MULT:
      break;
    case OPERATION_DIV:
      break;
    case SPACE:
      break;
    case NEW_LINE:
      line++;
      break;
    /* TODO add error handling */
    case UNKNOWN:
      fprintf(stderr, "Input não reconhecido:  %c  \( %d ) na linha:  %lu\n",
              str[i], i, line);
      return;
    }
  }
}
