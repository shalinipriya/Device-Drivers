# This is a Makefile for building the libraries in
# the subdirectories of $(KERNEL_HOME)/lib
# Zachary Anderson(zra)

MAKE = make

all: liblmm.a libx86.a libstdio.a libstdlib.a libstring.a MultiBoot.o \
     libdebug.a

liblmm.a: ./lmm/*.c ./lmm/Makefile ./lmm/*.h ./inc/*.h
	cd lmm; $(MAKE)

libx86.a: ./x86/*.c ./x86/Makefile ./x86/*.S \
           ./x86/*.h ./inc/*.h ./inc/x86/*.h
	cd x86; $(MAKE)

libstdio.a: ./stdio/*.c ./stdio/Makefile ./stdio/*.h ./inc/stdio.h
	cd stdio; $(MAKE)

libstdlib.a: ./stdlib/*.c ./stdlib/Makefile ./inc/stdlib.h
	cd stdlib; $(MAKE)

libstring.a: ./string/*.c ./string/Makefile ./string/*.S \
             ./inc/string.h
	cd string; $(MAKE)

MultiBoot.o: ./multiboot/*.c ./multiboot/Makefile ./multiboot/*.h \
             ./multiboot/*.S ./inc/*.h
	cd multiboot; $(MAKE)

libdebug.a: ./kerndebug/*.S ./kerndebug/Makefile ./inc/*.h \
            ./inc/x86/*.h
	cd kerndebug; $(MAKE)

clean:
	rm -f *.a *.o
	cd lmm; $(MAKE) clean
	cd x86; $(MAKE) clean
	cd stdio; $(MAKE) clean
	cd stdlib; $(MAKE) clean
	cd string; $(MAKE) clean
	cd multiboot; $(MAKE) clean
	cd kerndebug; $(MAKE) clean
