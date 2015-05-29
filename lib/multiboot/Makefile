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

MULTIBOOT_OBJS = multiboot.o base_multiboot_main.o \
base_multiboot_init_mem.o base_multiboot_init_cmdline.o \
base_stack.o	

all: MultiBoot.o

%.o: Makefile %.c
	$(CC) -c -o $(*F).o $(CFLAGS) $(INCLUDES) $(*F).c

%.o: Makefile %.S
	$(CC) -c -o $(*F).o $(CFLAGS) $(INCLUDES) $(*F).S

MultiBoot.o: Makefile $(MULTIBOOT_OBJS)
	$(LD) -r -o MultiBoot.o $(LDFLAGS) $(MULTIBOOT_OBJS)
	mv MultiBoot.o ..

clean:
	rm -f *.o *.d *~
