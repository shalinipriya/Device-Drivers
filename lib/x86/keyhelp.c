/**
 * The 15-410 reference kernel.
 *
 * @author Steve Muckle <smuckle@andrew.cmu.edu>
 *
 * Edited by zra for the 2003-2004 season.
 *
 * Edited by mpa for spring 2004
 *
 * Functions for turning keyboard scancodes
 * into chars.
 */
/*@{*/

#include <keyhelp.h>
#include <stdio.h>

#define LSHIFT_KEY_ON      0x01
#define RSHIFT_KEY_ON      0x02
#define LCONTROL_KEY_ON    0x04
#define RCONTROL_KEY_ON    0x08
#define LALT_KEY_ON        0x10
#define RALT_KEY_ON        0x20
#define CAPS_LOCK_ON       0x40
#define EXTENDED_KEY_PRESS 0x80

/**
 *  key_state flags:
 *  Bit 1: Left Shift key.
 *  Bit 2: Right Shift key.
 *  Bit 3: Left Control key.
 *  Bit 4: Right Control key.
 *  Bit 5: Left Alt key.
 *  Bit 6: Right Alt key.
 *  Bit 7: Caps lock on.
 *  Bit 8: Extended key press (0xE0 extension).
 */
static int key_state = 0;

/**
 * Queries status of shift key.
 *
 * @return 1 if shift is down. 0 o/w.
 */
__inline int 
shift() {
  if ((LSHIFT_KEY_ON | RSHIFT_KEY_ON)& key_state) return 1;
  else return 0;
}

/**
 * Queries status of caps lock.
 *
 * @return 1 if caps lock is on. 0 o/w.
 */
__inline int 
caps_lock() {
  if (CAPS_LOCK_ON & key_state) return 1;
  else return 0;
}


/**
 * This function performs the mapping
 * from simple scancodes to chars.
 *
 * @param scancode a simple scancode.
 *
 * @return the corresponding character.
 */
int 
scan_to_ascii(int scancode) {
  if (scancode == 0xE1) 
    /* Pause key. */
    return '?';
    
  switch(scancode) {
  case 0x1:
    /* Escape key. */
    return 0x1B;
  case 0x2:
    /* 1 or ! */
    if(shift()) return '!';
    else return '1';
  case 0x3:
    /* 2 or @ */
    if (shift()) return '@';
    else return '2';
  case 0x4:
    /* 3 or # */
    if (shift()) return '#';
    else return '3';
  case 0x5:
    /* 4 or $ */
    if (shift()) return '$';
    else return '4';
  case 0x6:
    /* 5 or % */
    if (shift()) return '%';
    else return '5';
  case 0x7:
    /* 6 or ^ */
    if (shift()) return '^';
    else return '6';
  case 0x8:
    /* 7 or & */
    if (shift()) return '&';
    else return '7';
  case 0x9:
    /* 8 or * */
    if (shift()) return '*';
    else return '8';
  case 0xA:
    /* 9 or ( */
    if (shift()) return '(';
    else return '9';
  case 0xB:
    /* 0 or ) */
    if (shift()) return ')';
    else return '0';
  case 0xC:
    /* - or _ */
    if (shift()) return '_';
    else return '-';
  case 0xD:
    /* = or + */
    if (shift()) return '+';
    else return '=';
  case 0xE:
    /* Backspace key. */
    return 0x8;
  case 0xF:
    /* Tab key. */
    return '\t';
  case 0x10:
    /* q or Q. */
    if ((shift() || caps_lock()) && !(shift() && caps_lock()))  return 'Q';
    else return 'q';
  case 0x11:
    /* w or W. */
    if ((shift() || caps_lock()) && !(shift() && caps_lock())) return 'W';
    else return 'w';
  case 0x12:
    /* e or E. */
    if ((shift() || caps_lock()) && !(shift() && caps_lock())) return 'E';
    else return 'e';
  case 0x13:
    /* r or R. */
    if ((shift() || caps_lock()) && !(shift() && caps_lock())) return 'R';
    else return 'r';
  case 0x14:
    /* t or T. */
    if ((shift() || caps_lock()) && !(shift() && caps_lock())) return 'T';
    else return 't';
  case 0x15:
    /* y or Y. */
    if ((shift() || caps_lock()) && !(shift() && caps_lock())) return 'Y';
    else return 'y';
  case 0x16:
    /* u or U. */
    if ((shift() || caps_lock()) && !(shift() && caps_lock())) return 'U';
    else return 'u';
  case 0x17:
    /* i or I. */
    if ((shift() || caps_lock()) && !(shift() && caps_lock())) return 'I';
    else return 'i';
  case 0x18:
    /* o or O. */
    if ((shift() || caps_lock()) && !(shift() && caps_lock())) return 'O';
    else return 'o';
  case 0x19:
    /* p or P. */
    if ((shift() || caps_lock()) && !(shift() && caps_lock())) return 'P';
    else return 'p';
  case 0x1A:
    /* [ or {. */
    if (shift()) return '{';
    else return '[';
  case 0x1B:
    /* ] or }. */
    if (shift()) return '}';
    else return ']';
  case 0x1C:
    /* Enter key. */
    return '\n';
  case 0x1D:
    /* Left control key, should not be processed
       in here. */
    return '?';
  case 0x1E:
    /* a or A. */
    if ((shift() || caps_lock()) && !(shift() && caps_lock())) return 'A';
    else return 'a';
  case 0x1F:
    /* s or S. */
    if ((shift() || caps_lock()) && !(shift() && caps_lock())) return 'S';
    else return 's';
  case 0x20:
    /* d or D. */
    if ((shift() || caps_lock()) && !(shift() && caps_lock())) return 'D';
    else return 'd';
  case 0x21:
    /* f or F. */
    if ((shift() || caps_lock()) && !(shift() && caps_lock())) return 'F';
    else return 'f';
  case 0x22:
    /* g or G. */
    if ((shift() || caps_lock()) && !(shift() && caps_lock())) return 'G';
    else return 'g';
  case 0x23:
    /* h or H. */
    if ((shift() || caps_lock()) && !(shift() && caps_lock())) return 'H';
    else return 'h';
  case 0x24:
    /* j or J. */
    if ((shift() || caps_lock()) && !(shift() && caps_lock())) return 'J';
    else return 'j';
  case 0x25:
    /* k or K. */
    if ((shift() || caps_lock()) && !(shift() && caps_lock())) return 'K';
    else return 'k';
  case 0x26:
    /* l or L. */
    if ((shift() || caps_lock()) && !(shift() && caps_lock())) return 'L';
    else return 'l';
  case 0x27:
    /* ; or :. */
    if (shift()) return ':';
    else return ';';
  case 0x28:
    /* ' or " */
    if (shift()) return '\"';
    else return '\'';
  case 0x29:
    if (shift()) return '~';
    else return '`';
  case 0x2A:
    /* Left shift key, should not be processed in here. */
    return '?';
  case 0x2B:
    /* \ or |. */
    if (shift()) return '|';
    else return '\\';
  case 0x2C:
    /* z or Z. */ 
    if ((shift() || caps_lock()) && !(shift() && caps_lock())) return 'Z';
    else return 'z';
  case 0x2D:
    /* x or X. */
    if ((shift() || caps_lock()) && !(shift() && caps_lock())) return 'X';
    else return 'x';
  case 0x2E:
    /* c or C. */
    if ((shift() || caps_lock()) && !(shift() && caps_lock())) return 'C';
    else return 'c';
  case 0x2F:
    /* v or V. */
    if ((shift() || caps_lock()) && !(shift() && caps_lock())) return 'V';
    else return 'v';
  case 0x30:
    /* b or B. */
    if ((shift() || caps_lock()) && !(shift() && caps_lock())) return 'B';
    else return 'b';
  case 0x31:
    /* n or N. */
    if ((shift() || caps_lock())  && !(shift() && caps_lock()))return 'N';
    else return 'n';
  case 0x32:
    /* m or M. */
    if ((shift() || caps_lock())  && !(shift() && caps_lock()))return 'M';
    else return 'm';
  case 0x33:
    /* , or <. */
    if (shift()) return '<';
    else return ',';
  case 0x34:
    /* . or >. */
    if (shift()) return '>';
    else return '.';
  case 0x35:
    /* / or ? */
    if (shift()) return '?';
    else return '/';
  case 0x36:
    /* Right shift key, should not be processed in here. */
    return '?';
  case 0x37:
    /* Print screen key. */
    return '?';
  case 0x38:
    /* Left alt key, should not be processed in here. */
    return '?';
  case 0x39:
    /* Space bar. */
    return ' ';
  case 0x3A:
    /* Caps lock, should not be processed in here. */
    return '?';
  case 0x3B:
    /* F1 key. */
    return '?';
  case 0x3C:
    /* F2 key. */
    return '?';
  case 0x3D:
    /* F3 key. */
    return '?';
  case 0x3E:
    /* F4 key. */
    return '?';  
  case 0x3F:
    /* F5 key. */
    return '?';
  case 0x40:
    /* F6 key. */
    return '?';  
  case 0x41:
    /* F7 key. */
    return '?';
  case 0x42:
    /* F8 key. */
    return '?';
  case 0x43:
    /* F9 key. */
    return '?';
  case 0x44:
    /* F10 key. */
    return '?';
    /*  case 0x48: */
  case 0x57:
    /* UP */
    return CUR_UP;
  case 0x47:
    /*  case 0x4b: */
    /* LEFT */
    return CUR_LEFT;
    /* case 0x4d: */
  case 0x48:
    /* RIGHT */
    return CUR_RIGHT;
    /* case 0x50: */
  case 0x4b:
    /* DOWN */
    return CUR_DOWN;
    /*  case 0x57: */
    /* F11 key. */
    /* return '?'; */
  case 0x58:
    /* F12 key. */
    return '?';
  default:
    return '?';
  }
  return '?';
}

/**
 * Processes some special scancodes for
 * Control and Alt.
 *
 * @param keypress the extended scancode.
 * @param 0 if released. non-zero if pressed.
 *
 * @return -1 if we recognized the press.
 *         '?' otherwise.
 */
int 
extended_scan_to_ascii(int keypress, int pressed) {
  key_state &= ~EXTENDED_KEY_PRESS;
  if (keypress == 0x1D) {
    /* Right control key. */
    if (pressed) key_state |= RCONTROL_KEY_ON;
    else key_state &= ~RCONTROL_KEY_ON;
    return -1;
  } else if (keypress == 0x38) {
    /* Right alt key. */
    if (pressed) key_state |= RALT_KEY_ON;
    else key_state &= ~RALT_KEY_ON;
    return -1;
  }
  if (!pressed) return -1;
  return '?';
}

/**
 * Converts keyboard scan codes into ascii chars
 * by calling scan_to_ascii and extended_scan_to_ascii.
 * Keeps track of shift, caps lock etc.
 *
 * @param keypress the scancode.
 *
 * @return the corresponding character.
 */
int process_scancode(int keypress) {
  int pressed = !(keypress & 0x80);
  keypress &= 0x7F;
  
  if (key_state & EXTENDED_KEY_PRESS)
    return extended_scan_to_ascii(keypress, pressed);

  if (keypress == 0x2A) {
    /* Shift key. */
    if (pressed)
      key_state |= LSHIFT_KEY_ON;
    else
      key_state &= ~LSHIFT_KEY_ON;
    return -1;
  } else if (keypress == 0x36) {
    /* Shift key. */
    if (pressed)
      key_state |= RSHIFT_KEY_ON;
    else
      key_state &= ~RSHIFT_KEY_ON;
    return -1;
  } else if (keypress == 0x1D) {
    /* Left control key. */
    if (pressed) key_state |= LCONTROL_KEY_ON;
    else key_state &= ~LCONTROL_KEY_ON;
    return -1;
  } else if (keypress == 0x38) {
    /* Left alt key. */
    if (pressed) key_state |= LALT_KEY_ON;
    else key_state &= ~LALT_KEY_ON;
    return -1;
  } else if (keypress == 0x3A) {
    /* Caps lock. */
    if (pressed) {
      if (key_state & CAPS_LOCK_ON)
	key_state &= ~CAPS_LOCK_ON;
      else key_state |= CAPS_LOCK_ON;
    }
    return -1;
  } else if (keypress == 0xE0) {
    /* Extended key code. Set extended marker. */
    key_state |= EXTENDED_KEY_PRESS;
    return -1;
  } else {
    /* It's just a normal key. If it's a release,
       we don't care about it. */
    if (!pressed) return -1;
    else return scan_to_ascii(keypress);
  }
   
  /* Should never be here! */
  return -1;
}

/*@}*/
