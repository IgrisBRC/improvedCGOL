
#include "screen.h"
#include <string.h>

struct Screen init() {
  struct Screen scrn;

  for (uint8_t i = 0; i < LEN; i++) {
    memset(&scrn.arr[i], 0, BRE);
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
    memcpy(scrn_new.arr[i], scrn->arr[i], BRE);
  }

  return scrn_new;
}
