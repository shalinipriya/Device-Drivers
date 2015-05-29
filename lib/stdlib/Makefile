# This is a make file that builds the library for
# kernel/lib/stdlib
#
#
CC = gcc
AR = ar
CFLAGS = -nostdinc -fno-strict-aliasing -fno-builtin -gstabs+ -Wall -Werror
LD = ld
LDFLAGS = -static

INCLUDES    = -I../inc

STDLIB_OBJS = atol.o environ.o getenv.o panic.o strtol.o strtoul.o \
ctype.c

all: libstdlib.a

%.o: Makefile %.c
	$(CC) -c -o $(*F).o $(CFLAGS) $(INCLUDES) $(*F).c

libstdlib.a: Makefile $(STDLIB_OBJS)
	$(AR) rc libstdlib.a $(STDLIB_OBJS)
	mv libstdlib.a ..

clean:
	rm -f *.o *.d *.a *~
