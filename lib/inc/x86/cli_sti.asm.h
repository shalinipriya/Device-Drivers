/* The 15-410 kernel project
 *
 *   cli_sti.asm.h
 *
 * This file should be #included in all assembly language source
 * files that use the cli or sti instruction. This is so that
 * profiling the preemptiveness of the kernel is possible
 * even when interrupts are enabled or disabled within
 * functions written in assembly language.
 *
 */

#ifndef _CLI_STI_ASM_H
#define _CLI_STI_ASM_H

#define cli cli;\
            pushl %ebx;\
            movl $0x3badd00d, %ebx;\
            xchg %bx, %bx;\
            popl %ebx

#define sti pushl %ebx;\
            movl $0x4badd00d, %ebx;\
            xchg %bx, %bx;\
            popl %ebx;\
            sti

#endif /* _CLI_STI_ASM_H */
