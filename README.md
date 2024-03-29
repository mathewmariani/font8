# font8
A *tiny* 8x8 monochrome bitmap font encoder.

## Building
The project can be built using the provided makefile.

## Usage
font8 will create a monochrome bitmap font using the black pixels from an input image and produce an encoded output as a c header.

```
./font8 res/font8.png fonts/font8.h
```

## Render
To visualize the font, a simple console renderer is included in `src/render.c`

```
$ make render
$ ./render 65
1c 3e 63 63 7f 7f 63 00

  xxx   
 xxxxx  
xx   xx 
xx   xx 
xxxxxxx 
xxxxxxx 
xx   xx
```

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

## License
This project is free software; you can redistribute it and/or modify it under
the terms of the MIT license. See [LICENSE](LICENSE) for details.