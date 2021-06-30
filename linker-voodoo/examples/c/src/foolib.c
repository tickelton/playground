#include <stdlib.h>
#include "foolib.h"


int foolib_add(int i) {
  return i+foolib_rand();
}

int foolib_rand() {
  return rand();
}
