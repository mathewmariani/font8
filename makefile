font8: src/font8.c
	gcc -o font8 src/font8.c -Ilibs

render: src/render.c
	gcc -o render src/render.c -Ifonts