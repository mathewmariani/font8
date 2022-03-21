#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
  int j = atoi(argv[1]);

  #include "font8.h"
  printf("%02x %02x %02x %02x %02x %02x %02x %02x\n\n"
    , *(font_h + 0 + j * 8)
    , *(font_h + 1 + j * 8)
    , *(font_h + 2 + j * 8)
    , *(font_h + 3 + j * 8)
    , *(font_h + 4 + j * 8)
    , *(font_h + 5 + j * 8)
    , *(font_h + 6 + j * 8)
    , *(font_h + 7 + j * 8));

  for (int i = 0; i < 8; ++i) {
    printf("%c%c%c%c%c%c%c%c\n"
      , (*(font_h + i + j * 8) >> 0) & 1 ? 'x' : ' '
      , (*(font_h + i + j * 8) >> 1) & 1 ? 'x' : ' '
      , (*(font_h + i + j * 8) >> 2) & 1 ? 'x' : ' '
      , (*(font_h + i + j * 8) >> 3) & 1 ? 'x' : ' '
      , (*(font_h + i + j * 8) >> 4) & 1 ? 'x' : ' '
      , (*(font_h + i + j * 8) >> 5) & 1 ? 'x' : ' '
      , (*(font_h + i + j * 8) >> 6) & 1 ? 'x' : ' '
      , (*(font_h + i + j * 8) >> 7) & 1 ? 'x' : ' ');
  }

  for (int y = 0; y < 8; ++y) {
    for (int x = 0; x < 8; ++x) {
      printf("%c", (*(font_h + y + j * 8) >> x) & 1 ? 'x' : ' ');
    }
    printf("\n");
  }

  return 0;
}