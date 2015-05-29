/* The 15-410 reference kernel.
 * syscall_int.h
 *
 * Prototypes for assembly language wrappers for the
 * system call interface.
 *
 * Adam Chlipala (adamc)
 * Jorge Vittes (jvittes)
 * Zachary Anderson (zra)
 */

#ifndef _SYSCALL_INT_H
#define _SYSCALL_INT_H

#define SYSCALL_INT         0x40
#define FORK_INT            0x41
#define EXEC_INT            0x42
#define EXIT_INT            0x43
#define WAIT_INT            0x44
#define YIELD_INT           0x45
#define DESCHEDULE_INT      0x46
#define MAKE_RUNNABLE_INT   0x47
#define GETPID_INT          0x48
#define BRK_INT             0x49
#define SLEEP_INT           0x4A
#define GETCHAR_INT         0x4B
#define READLINE_INT        0x4C
#define PRINT_INT           0x4D
#define SET_TERM_COLOR_INT  0x4E
#define SET_CURSOR_POS_INT  0x4F
#define MINCLONE_INT        0x50
#define HALT_INT            0x51
#define LS_INT              0x52
#define GET_CURSOR_POS_INT  0x53
#define NEW_CONSOLE_INT     0x54

#define FS_MKFS_INT         0x61
#define FS_OPEN_INT         0x62
#define FS_CREATE_INT       0x63
#define FS_CLOSE_INT        0x64
#define FS_READ_INT         0x65
#define FS_WRITE_INT        0x66
#define FS_SEEK_INT         0x67
#define FS_LINK_INT         0x68
#define FS_SYMLINK_INT      0x69
#define FS_UNLINK_INT       0x6A
#define FS_FILESIZE_INT     0x6B
#define FS_MKDIR_INT        0x6C
#define FS_RMDIR_INT        0x6D
#define FS_CHDIR_INT        0x6E
#define FS_DIRSIZE_INT      0x6F
#define FS_DIRENTRY_INT     0x70
#define FS_SYNC_INT         0x71
#define FS_DUP_INT          0x72

#endif /* _SYSCALL_INT_H */
