#
# Makefile for MIPS Instruction Decoder
#
#

# set the compiler to use and the flags to use
#-Wall asks that the compiler report a number of warnings
# especially those that are easily fixed (e.g. wrong format type, etc)
CC=gcc -Wall -g
# The names of your .o files, compiled from your .c files

DRIVER=driver.o
MIPSI=mipsInstruction.o

OFILES=$(DRIVER) $(MIPSI)

driver:	$(OFILES)
	$(CC) -o parseInstruction $(OFILES)

clean::
	/bin/rm -f parseInstruction $(DRIVER) $(MIPSI)

mipsInstruction.o:	mipsInstruction.h
driver.o:	mipsInstruction.h
