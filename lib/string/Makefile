# This is a make file that builds the library for
# kernel/lib/string
#
#
CC = gcc
AR = ar
CFLAGS = -nostdinc -fno-strict-aliasing -fno-builtin -gstabs+ -Wall -Werror
LD = ld
LDFLAGS = -static

INCLUDES    = -I../inc

STRING_OBJS = bcmp.o bcopy.o bzero.o memchr.o memcmp.o memset.o \
              rindex.o strcasecmp.o strcat.o strchr.o strcmp.o  \
              strcpy.o strcspn.o strdup.o strlen.o strncat.o    \
              strncmp.o strncpy.o strpbrk.o strrchr.o strsep.o  \
              strspn.o strstr.o strtok.o strtok_r.o 

all: libstring.a

%.o: Makefile %.c
	$(CC) -c -o $(*F).o $(CFLAGS) $(INCLUDES) $(*F).c

%.o: Makefile %.S
	$(CC) -c -o $(*F).o $(CFLAGS) $(INCLUDES) $(*F).S

libstring.a: Makefile $(STRING_OBJS)
	$(AR) rc libstring.a $(STRING_OBJS)
	mv libstring.a ..

clean:
	rm -f *.o *.d *.a *~
