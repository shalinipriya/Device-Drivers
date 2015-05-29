# This is a make file that builds the library for
# kernel/lib/stdio
#
#
CC = gcc
AR = ar
CFLAGS = -nostdinc -fno-strict-aliasing -fno-builtin -gstabs+ -Wall -Werror
LD = ld
LDFLAGS = -static

INCLUDES    = -I../inc -I../../inc

STDIO_OBJS = doprnt.o doscan.o printf.o putchar.o puts.o sprintf.o \
             sscanf.o

all: libstdio.a

%.o: Makefile %.c
	$(CC) -c -o $(*F).o $(CFLAGS) $(INCLUDES) $(*F).c

libstdio.a: Makefile $(STDIO_OBJS)
	$(AR) rc libstdio.a $(STDIO_OBJS)
	mv libstdio.a ..

clean:
	rm -f *.o *.d *.a *~
