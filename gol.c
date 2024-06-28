
#include "gol.h"
#include "screen.h"
#include <stdlib.h>
#include <unistd.h>

uint8_t neighbours(struct Screen *scrn, int y, int x) {
  uint8_t n = 0;

  for (int i = y - 1; i <= y + 1; i++) {
    for (int j = x - 1; j <= x + 1; j++) {
      if (i < 0 || i >= LEN || j < 0 || j >= BRE || (i == y && j == x)) {
        continue;
      }

      if (scrn->arr[i][j]) {
        n += 1;
      }
    }
  }

  return n;
}

void game_of_life(struct Screen *scrn1, struct Screen *scrn2) {
  for (int i = 0; i < LEN; i++) {
    for (int j = 0; j < BRE; j++) {
      int n = neighbours(scrn1, i, j);

      if (n < 2 || n > 3) {
        scrn2->arr[i][j] = 0;
      } else if (n == 3) {
        scrn2->arr[i][j] = 1;
      }
    }
  }
}

void play(struct Screen *scrn) {
  struct Screen alt = clone(scrn);

  for (;;) {
    *scrn = clone(&alt);

    system("clear");
    draw(scrn);
    usleep(100000);
    game_of_life(scrn, &alt);
  }
}
