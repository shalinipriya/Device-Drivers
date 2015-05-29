/* The 15-410 kernel project
 *
 *     syscall_nums.h
 *
 * #defines for system call numbers
 */

#ifndef SYSCALL_NUMS_H
#define SYSCALL_NUMS_H

#define SYSCALL_FORK            10 /* 0x41 */
#define SYSCALL_EXEC            20 /* 0x42 */
#define SYSCALL_EXIT            30 /* 0x43 */
#define SYSCALL_WAIT            40 /* 0x44 */
#define SYSCALL_YIELD           50 /* 0x45 */
#define SYSCALL_DESCHEDULE      60 /* 0x46 */
#define SYSCALL_MAKE_RUNNABLE   70 /* 0x47 */
#define SYSCALL_GETPID          80 /* 0x48 */
#define SYSCALL_BRK             90 /* 0x49 */
#define SYSCALL_SLEEP          100 /* 0x4A */
#define SYSCALL_GETCHAR        110 /* 0x4B */
#define SYSCALL_READLINE       120 /* 0x4C */
#define SYSCALL_PRINT          130 /* 0x4D */
#define SYSCALL_SET_TERM_COLOR 140 /* 0x4E */
#define SYSCALL_SET_CURSOR_POS 150 /* 0x4F */
#define SYSCALL_MINCLONE       160 /* 0x50 */
#define SYSCALL_HALT           170 /* 0x51 */
#define SYSCALL_LS             180 /* 0x52 */
#define SYSCALL_GET_CURSOR_POS 181 /* 0x53 */
#define SYSCALL_NEW_CONSOLE    182 /* 0x54 */

#define SYSCALL_FS_MKFS       1000 /* 0x61 */
#define SYSCALL_FS_OPEN       1010 /* 0x62 */
#define SYSCALL_FS_CREATE     1020 /* 0x63 */
#define SYSCALL_FS_CLOSE      1030 /* 0x64 */
#define SYSCALL_FS_READ       1040 /* 0x65 */
#define SYSCALL_FS_WRITE      1050 /* 0x66 */
#define SYSCALL_FS_SEEK       1060 /* 0x67 */
#define SYSCALL_FS_LINK       1070 /* 0x68 */
#define SYSCALL_FS_SYMLINK    1080 /* 0x69 */
#define SYSCALL_FS_UNLINK     1090 /* 0x6A */
#define SYSCALL_FS_FILESIZE   1100 /* 0x6B */
#define SYSCALL_FS_MKDIR      1110 /* 0x6C */
#define SYSCALL_FS_RMDIR      1120 /* 0x6D */
#define SYSCALL_FS_CHDIR      1130 /* 0x6E */
#define SYSCALL_FS_DIRSIZE    1140 /* 0x6F */
#define SYSCALL_FS_DIRENTRY   1150 /* 0x70 */
#define SYSCALL_FS_SYNC       1160 /* 0x71 */
#define SYSCALL_FS_DUP        1170 /* 0x72 */

#endif
