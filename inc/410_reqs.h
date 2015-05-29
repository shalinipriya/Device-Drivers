/**
 * @file 410_reqs.h
 * @brief DO NOT CHANGE OR MOVE THIS FILE! 
 *
 * Functions, structures, and headers provided by the 410 course staff for 
 * use in the construction of project 1.
 *
 * This file contains headers, structures, and functions that are specific
 * to 15-410 project 1, Spring 2004. Any functions specified in this header
 * are provided by the user, and must conform to the signature and invariants
 * denoted in this header. User should place other function declarations,
 * constant declarations, etc. in separate headers.
 *
 * Read this file!
 *
 * @author Mark T. Tomczak (mtomczak)
 * @bug None known, but there is a reason this file can be replaced by 
 *      update.pl ;)
 **/

#ifndef __410_PROVIDED_H__
#define __410_PROVIDED_H__

/** @brief Maximum length of a single typing tutor string
 **/

#define TYPING_MAX_LEN 80

/** @brief Null-terminated array of strings, for use in the typing tutor
 *
 *  You cannot change the strings provided in this array, but you can augment
 *  the array with your own data in your program. It is up to you how to
 *  do this
 **/
extern const char TYPING_STRINGS[][TYPING_MAX_LEN]; 

/** @brief size of the above array, in bytes
 **/
extern const int TYPING_SIZE;
/*** FUNCTION DEFINITIONS ***/

/** @brief The kernel initialization function
 *
 *   Installs the timer and keyboard interrupt handler, and initializes all
 *   three handlers (console, keyboard, and timer). This is located
 *   in driver_init.c; you are responsible for filling in the body of the
 *   code. NOTE: driver_init should initialize ONLY the handlers; do the rest
 *   of the typing tutor initialization elsewhere.
 *   
 *   @return A negative error code on error, or 0 on success
 **/
int driver_init(void);

/** @brief A tick function called by the tick handler
 *
 *  Function that should be called by your timer interrupt 
 *  for each timer interrupt caught. This function is defined in tick.c; 
 *  you are responsible for filling in the body of the code. 
 *
 *  IMPORTANT NOTE: this function should NOT handle timer interrupts; it is
 *                  intended as a hook to allow timer interrupts to trigger
 *                  other events. In other words, timer interrupts should be
 *                  caught and handled (pic reset, etc.) even if the
 *                  tick function body is empty. During the grading of your
 *                  console implementation, tick() will be replaced with
 *                  grading code, so be certain that your console code works
 *                  even if tick is empty!
 *  
 *  @param numTicks the total number of ticks the timer interrupt has handled
 *
 *  @return Void
 **/

void tick(unsigned int numTicks);

/** @brief Returns the next character in the keyboard buffer
 *
 *  This function does not block if there are no characters in the keyboard
 *  buffer
 *
 *  @return The next character in the keyboard buffer, or -1 if the keyboard
 *          buffer is currently empty
 **/
char readchar(void);

#endif /* __410_PROVIDED_H__ */
