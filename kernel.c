/** @file kernel.c
 *  @brief An initial kernel.c
 *
 *  This file contains the kernel's
 *  main() function.
 *
 *  You should add your own comments to
 *  replace this one.
 *
 *  This is where you will eventually setup
 *  your game board and have it run.
 * 
 *  Don't forget to replace author with your name (Harry Q. Bovik gets way
 *  more credit every year than he is due ;)
 *
 *  @author Harry Q. Bovik (hbovik)
 **/

/* -- Includes -- */

/* 410 project 1 header */
#include <410_reqs.h>

/* multiboot header file */
#include <multiboot.h>    /* for boot_info */

/* memory includes. */
#include <lmm.public.h>   /* for lmm_remove_free() */

/* x86 specific includes */
#include <x86/seg.h>      /* for install_user_segs() */
#include <x86/pic.h>      /* for pic_init() */
#include <x86/base_irq.h> /* for base_irq_master/slave */

/*
 * state for kernel memory allocation.
 */
extern lmm_t malloc_lmm;

/*
 * Info about system gathered by the boot loader
 */
extern struct multiboot_info boot_info;

/** @brief Kernel entrypoint.
 *  
 * Your comments here 
 *
 * @return Should not return (typing tutor does not return)
 */

int kernel_main()
{
    /*
     * Tell the kernel memory allocator which memory it can't use.
     * It already knows not to touch kernel image.
     */
    lmm_remove_free( &malloc_lmm, (void*)USER_MEM_START, USER_MEM_SIZE );
    lmm_remove_free( &malloc_lmm, (void*)0, 0x100000 );

    /*
     * Initialize drivers here.
     */
    driver_init();
    
    /*
     * initialize the PIC so that IRQs and
     * exception handlers don't overlap in the IDT.
     */
    pic_init( BASE_IRQ_MASTER_BASE, BASE_IRQ_SLAVE_BASE );


    /* This is all up to you... */

    return -1;
}
