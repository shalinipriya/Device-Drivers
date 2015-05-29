/** @file 410test.c
 *  @brief A test file for your drivers.
 */

/* -- Includes -- */

/* libc includes. */
#include <stdio.h> /* for lprintf_kern() */

/* multiboot header file */
#include <multiboot.h> /* for boot_info */

/* memory includes. */
#include <lmm.public.h> /* for lmm_remove_free() */

/* x86 specific includes */
#include <x86/seg.h> /* for install_user_segs() */
#include <x86/pic.h> /* for pic_init() */
#include <x86/base_irq.h> /* for base_irq_master/slave */
#include <kerndebug.h>
#include <timer_defines.h>

/* driver includes */
#include <410_reqs.h>
#include <console.h>

/*
 * state for kernel memory allocation.
 */
extern lmm_t malloc_lmm;

/*
 * Info about system gathered by the boot loader
 */
extern struct multiboot_info boot_info;

/* --- Kernel entrypoint --- */
int
kernel_main()
{
    /*
     * Tell the kernel memory allocator which memory it can't use.
     * It already knows not to touch kernel image.
     */
    lmm_remove_free( &malloc_lmm, (void*)USER_MEM_START, USER_MEM_SIZE );
    lmm_remove_free( &malloc_lmm, (void*)0, 0x100000 );

    if(driver_init() < 0) {
      return 0;
    }

    /*
     * initialize the PIC so that IRQs and
     * exception handlers don't overlap in the IDT.
     */
    pic_init( BASE_IRQ_MASTER_BASE, BASE_IRQ_SLAVE_BASE );

    clear_console();

    show_cursor();

    set_term_color(FGND_GREEN | BGND_BLACK);

    set_cursor(12, 34);

    putbytes("Hello World!\n", 12);

    while(1) {
    }

    return 0;
}
