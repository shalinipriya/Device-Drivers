#ifndef KEYHELP_H
#define KEYHELP_H

#define KEY_IDT_ENTRY 0x21
#define KEYBOARD_PORT 0x60

#define CUR_RIGHT 28
#define CUR_LEFT  29
#define CUR_UP    30
#define CUR_DOWN  31

__inline int caps_lock(void);

__inline int shift(void);

int process_scancode(int keypress);

#endif
