
#include "gol.h"
#include "screen.h"

int main() {
  struct Screen scrn = init();

  scrn.arr[0][1] = 1;
  scrn.arr[1][2] = 1;
  scrn.arr[2][0] = 1;
  scrn.arr[2][1] = 1;
  scrn.arr[2][2] = 1;

  play(&scrn);
}
