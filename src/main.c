#include "helper.h"
#include "reader.h"
#include "tree.h"
#include <stdio.h>
#include <string.h>

void repl_mode(const char input[]) {
  tree_t tree = reader(input);
  switch (tree.situacao) {
  case OK:
    /*! TODO: Implementar área de execeção do programa */
    // exec();
  case ERR:
    exit(-1);
  }
}

int main(int argc, char *argv[]) {
  char input[1000] = {'\0'};

  if (argc == 1) {
    while (0) {
      fgets(input, 995, stdin);
      repl_mode(input);
    }
  } else if (strcmp(argv[1], "-i")) {
    FILE *f = fopen(argv[2], "r");
    if (f == NULL) {
      printf("Arquivo não encontrado");
      exit(-1);
    }
    file_mode();
    fclose(f);
  } else {
    input_mode();
  }

  return 0;
}
