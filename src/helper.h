#ifndef HELPER_H_
#define HELPER_H_

#include <stdio.h>
#include <stdlib.h>

#define foo() (NULL)

inline void check_allocation(void *ptr) {
  if (ptr == NULL) {
    printf("Falha em alocar memória");
    abort();
  }
}

inline void clear_stdin(void) {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
    continue;
  }
}

#endif // HELPER_H_
