#
# This Makefile builds a 15-410 kernel
# IMPORTANT: Do not edit this file! This file will be REPLACED periodically
#            by the  update scripts, as well as in the grading process.
# Edit the 'kernel.mk' file instead

MAKE = make
CC = gcc
LD = ld
PRINT = enscript
DOC = doxygen
UPDATE = ./update.pl
CFLAGS = -nostdinc -fno-strict-aliasing -fno-builtin -gstabs+ -Wall -Werror
INCLUDES = -I./inc -I./lib/inc
LDFLAGS = -static -Ttext 100000
LIBS = ./lib
AFS_DIR = /afs/cs.cmu.edu/academic/class/15410-s04/Web/update


include kernel.mk

all: afs

%.o: Makefile %.s
	$(CC) -c -o $(*F).o $(CFLAGS) $(INCLUDES) $(*F).s

%.o: Makefile %.S
	$(CC) -c -o $(*F).o $(CFLAGS) $(INCLUDES) $(*F).S

%.o: Makefile %.c
	$(CC) -c -o $(*F).o $(CFLAGS) $(INCLUDES) $(*F).c

kernel: Makefile kernel.o $(OBJS) 
	$(LD) $(LDFLAGS) -L$(LIBS) -o kernel  \
	$(LIBS)/MultiBoot.o kernel.o $(OBJS)  \
	-llmm -lstdio -lstdlib -lstring -lx86 -ldebug

410test: Makefile 410test.o $(OBJS)
	cd lib; $(MAKE) 
	$(LD) $(LDFLAGS) -L$(LIBS) -o kernel  \
	$(LIBS)/MultiBoot.o 410test.o $(OBJS)  \
	-llmm -lstdio -lstdlib -lstring -lx86 -ldebug
	echo "drive k: file=\"$(PWD)/bootfd.img\" " > ~/.mtoolsrc
	mcopy -o kernel K:/boot/

kernel-install bootfd: Makefile kernel
	echo "drive k: file=\"$(PWD)/bootfd.img\" " > ~/.mtoolsrc
	mcopy -o kernel K:/boot/

# build the kernel in afs, retrieving libraries from afs space.
afs:
	$(UPDATE) afs
	cd lib; $(MAKE)
	$(MAKE) kernel-install

# build the kernel away from afs, retrieving libraries from the web
web:
	$(UPDATE) web
	cd lib; $(MAKE)
	$(MAKE) kernel-install

# build the kernel disconnected. build libraries here.
# building like this should be avoided.
offline:
	$(UPDATE) offline
	cd lib; $(MAKE)
	$(MAKE) kernel-install

update:
	cd lib; $(MAKE)
	$(MAKE) -f md5.mk

html_doc:
	$(DOC) $(AFS_DIR)/proj1.doxygen

print:
	$(PRINT) -2r -p kernel.ps $(SRCS) $(HDRS)

deepclean:
	rm -f *.o *.d *.gdb *~ kernel kernel.log ints.log
	cd lib; $(MAKE) clean
	$(MAKE) -f md5.mk clean

clean:
	rm -f *.o *.d *.gdb *~ kernel kernel.log ints.log
	cd lib; $(MAKE) clean
	$(MAKE) -f md5.mk clean