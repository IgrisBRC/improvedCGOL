
#include "screen.h"
#include <stdint.h>

struct Screen init() {
  struct Screen scrn;

  for (uint8_t i = 0; i < LEN; i++) {
    for (uint8_t j = 0; j < BRE; j++) {
      scrn.arr[i][j] = 0;
    }
  }

  return scrn;
}

void draw(struct Screen *scrn) {

  for (uint8_t i = 0; i < LEN; i++) {
    for (uint8_t j = 0; j < BRE; j++) {
      if (scrn->arr[i][j]) {
        printf("# ");
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }
}

struct Screen clone(struct Screen *scrn) {
  struct Screen scrn_new;

  for (uint8_t i = 0; i < LEN; i++) {
    for (uint8_t j = 0; j < LEN; j++) {
      scrn_new.arr[i][j] = scrn->arr[i][j];
    }
  }

  return scrn_new;
}
