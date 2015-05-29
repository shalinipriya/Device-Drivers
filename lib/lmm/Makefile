# This is a make file that builds a library for
# kernel/lib/lmm
#
#
CC = gcc
AR = ar
CFLAGS = -nostdinc -fno-strict-aliasing -fno-builtin -gstabs+ -Wall -Werror
LD = ld
LDFLAGS = -static

INCLUDES    = -I../inc

LMM_OBJS = lmm_add_free.o lmm_add_region.o lmm_alloc.o lmm_alloc_aligned.o \
           lmm_alloc_gen.o lmm_alloc_page.o lmm_avail.o lmm_avail_in.o     \
           lmm_dump.o lmm_find_free.o lmm_free.o lmm_free_page.o           \
           lmm_init.o lmm_remove_free.o lmm_stats.o phys_lmm_add.o         \
           phys_lmm_init.o phys_mem_max.o phys_mem_min.o phys_mem_va.o     \
           linear_base_va.o lmm.malloc.o malloc.o mallocf.o smalloc.o      \
           smallocf.o

all: liblmm.a

%.o: Makefile %.c
	$(CC) -c -o $(*F).o $(CFLAGS) $(INCLUDES) $(*F).c

liblmm.a: Makefile $(LMM_OBJS)
	$(AR) rc liblmm.a $(LMM_OBJS)
	mv liblmm.a ..

clean:
	rm -f *.o *.d *.a *~
