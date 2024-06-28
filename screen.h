#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define LEN 35
#define BRE 75

struct Screen {
  bool arr[LEN][BRE];
};

struct Screen init();
void draw(struct Screen *);
struct Screen clone(struct Screen *);
