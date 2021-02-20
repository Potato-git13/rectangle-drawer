CFLAGS=-g -Wall -Wextra -pedantic -Wformat=2 -lcurses

# compile and make bin
c: main.c
	mkdir -p bin
	$(CC) -o bin/draw main.c $(CFLAGS)

# run
r: bin/draw
	bin/draw

# compile & run
cr: c r

# run in gdb
rd: bin/draw
	gdb bin/draw

# compile & run in gdb
crd: c rd

# tell makefile that the arguments aren't files
.PHONY: c r cr rd crd
