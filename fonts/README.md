## Encoding
Every glyph is encoded as 8 bytes in row-major order. The character `A` is encoded as `0x1c, 0x3e, 0x63, 0x63, 0x7f, 0x7f, 0x63, 0x00`.

```
0x1c => 0011 1000 => ..xxx...
0x3e => 0111 1100 => .xxxxx..
0x63 => 1100 0110 => xx...xx.
0x63 => 1100 0110 => xx...xx.
0x7f => 1111 1110 => xxxxxxx.
0x7f => 1111 1110 => xxxxxxx.
0x63 => 1100 0110 => xx...xx.
0x00 => 0000 0000 => ........
```

The nth pixel in a row, of a specific glyph, can be accessed using a right-shift operation by n.

```
                     . . x x x . . .
                     | | | | | | | |
(0x1c >> 0) & 1 == 0-+ | | | | | | |
(0x1c >> 1) & 1 == 0---+ | | | | | |
(0x1c >> 2) & 1 == 1-----+ | | | | |
(0x1c >> 3) & 1 == 1-------+ | | | |
(0x1c >> 4) & 1 == 0---------+ | | |
(0x1c >> 5) & 1 == 0-----------+ | |
(0x1c >> 6) & 1 == 0-------------+ |
(0x1c >> 7) & 1 == 0---------------+
```

## Contributors

Font | Author
-----|--------
[`font8`](font8.h?raw=1) | Mathew Mariani <mat.mariani@hotmail.com>
[`font`](font.h?raw=1) | Mathew Mariani <mat.mariani@hotmail.com>