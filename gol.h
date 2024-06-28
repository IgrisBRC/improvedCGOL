#pragma once

#include "screen.h"
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

uint8_t neighbours(struct Screen *, int, int);
void game_of_life(struct Screen *, struct Screen *);
void play(struct Screen *);
