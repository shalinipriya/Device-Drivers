# This is a make file that builds the library for
# kernel/lib/kerndebug
#
#
CC = gcc
AR = ar
CFLAGS = -nostdinc -fno-strict-aliasing -fno-builtin -gstabs+ -Wall -Werror
LD = ld
LDFLAGS = -static

INCLUDES    = -I../inc -I../inc/x86

DEBUG_OBJS = kerndebug.o

all: libdebug.a

%.o: Makefile %.S
	$(CC) -c -o $(*F).o $(CFLAGS) $(INCLUDES) $(*F).S

libdebug.a: Makefile $(DEBUG_OBJS)
	$(AR) rc libdebug.a $(DEBUG_OBJS)
	mv libdebug.a ..

clean:
	rm -f *.o *.d *.a *~
