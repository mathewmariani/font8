/*
 * Copyright (c) 2021 Mathew Mariani
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include <stdio.h>

#define STBI_ONLY_PNG
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define PACK_COLOR(r, g, b)                \
  ((r << 24) + (g << 16) + (b << 8) + 255)

static void print_cell(FILE *file, int *grid, int cx, int cy) {
  for (int y = 0; y < 8; ++y) {
  	int b = 0b00000000;
    for (int x = 7; x >= 0; --x) {
      int i = (x + (cx * 8)) + 128 * (y + (cy * 8));
      b |= *(grid + i) << x;
    }
    fprintf(file, "0x%02x, ", b);
  }
}

int main(int argc, char** argv) {
  const char *input = argv[1];
  const char *output = argv[2];

  int w, h, comp;
  unsigned char *pixels = stbi_load(input, &w, &h, &comp, STBI_rgb);

  int b[128 * 64];
  int j = 0;
  for (int i = 0; i < (w * h) * 3; i += 3, j++) {
    int rgb = PACK_COLOR(
      *(pixels + i + 0),
      *(pixels + i + 1),
      *(pixels + i + 2));

    *(b + j) = (rgb == 0x000000ff) ? 1 : 0;
  }

  FILE *file = fopen(output, "w");
  fprintf(file, "const unsigned char font_h[] = {\n");
  for (int y = 0; y < 8; ++y) {
    for (int x = 0; x < 16; ++x) {
      fprintf(file, "  ");
      print_cell(file, b, x, y);
      fprintf(file, "\n");
    }
  }
  fprintf(file, "};\n");
  fclose(file);

  return 0;
}