#
# This is the include file for the various kernel make files.
# You should only have to edit this file to get things to build.
#

#
# List object files that will be linked into the kernel binary
# here. Make will find the .c and .S files corresponding to the
# same-named .o file
#
OBJS = console.o 410_provided.o driver_init.o tick.o  

#
# List here source and header files that will be included
# in the document created by a 'make print' (you should list all of your
# source and header files... TAs use `make print' for grading and can't be
# held responsible if a piece of your code is missing from these lists)
#
SRCS = kernel.c console.c driver_init.c tick.c

HDRS =

#
# If you want to add any flags to gcc, do that here
#
CFLAGS +=
