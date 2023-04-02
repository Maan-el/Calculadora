#include "helper.h"

int main(int argc, char *argv[]) {
  if (argc == 1) {
    repl_mode();
  } else {
    user_input();
  }

  return 0;
}
