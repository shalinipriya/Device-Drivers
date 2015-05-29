# This is a make file that builds the library for
# kernel/lib/processor
#
#
CC = gcc
AR = ar
CFLAGS = -nostdinc -fno-strict-aliasing -fno-builtin -g -Wall -Werror
LD = ld
LDFLAGS = -static

INCLUDES    = -I../inc -I../inc/x86

X86_OBJS = base_cpu_init.o base_cpu_load.o base_fpu_init.o  \
base_gdt.o base_gdt_init.o base_gdt_load.o base_idt.o       \
base_idt_load.o base_irq.o base_irq_default_handler.o       \
base_irq_init.o base_irq_inittab.o base_irq_softint.o       \
base_irq_softint_handler.o base_trap.o                      \
base_trap_default_handler.o base_trap_ignore_handler.o      \
base_trap_init.o base_trap_inittab.o base_tss.o             \
base_tss_init.o base_tss_load.o gate_init.o pic.o seg.o     \
trap_dump.o trap_dump_panic.o proc_reg.o keyhelp.o          \
sound.o

all: libx86.a

%.o: Makefile %.c
	$(CC) -c -o $(*F).o $(CFLAGS) $(INCLUDES) $(*F).c

%.o: Makefile %.S
	$(CC) -c -o $(*F).o $(CFLAGS) $(INCLUDES) -DASSEMBLER $(*F).S

libx86.a: Makefile $(X86_OBJS)
	$(AR) rc libx86.a $(X86_OBJS)
	mv libx86.a ..

clean:
	rm -f *.o *.d *.a
