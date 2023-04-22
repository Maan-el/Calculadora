#ifndef HELPER_H_
#define HELPER_H_

#include <stdio.h>
#include <stdlib.h>

inline void clear_stdin(void) {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
    continue;
  }
}

#endif // HELPER_H_
