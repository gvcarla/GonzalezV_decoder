/*
  mipsInstruction.c

 Template file for Mips Instruction Decoder Lab
 Author: Lisa Ballesteros, January, 2010
 Lab06 Carla Gonzalez-Vazquez
*/

#include <stdlib.h>
#include <stdio.h>
#include "mipsInstruction.h"

/**
 ** Decodes all possible fields of an instruction, in parameter instructionRegister.
 ** Fills the corresponding fields of the mipsInstruction structure pointed to
 ** by the parameter instruction.
 ** uses right and left shift to decode the hexadecimal instruction
 **/
void parseMipsInstruction(unsigned int instructionRegister, mipsInstruction *instruction) 
{
  
	instruction->op = instructionRegister >> 26;
	instruction->rs = instructionRegister << 6 >> 27;
	instruction->rt = instructionRegister << 11 >> 27;
	instruction->rd = instructionRegister << 16 >> 27;
	instruction->shamt = instructionRegister << 21 >> 27;
	instruction->funct = instructionRegister << 26 >> 26;
	instruction->target = instructionRegister << 6 >> 6;
	instruction->immedOrAddress = instructionRegister << 16 >> 16;

  

  // WRITE CODE FOR DECODING INSTRUCTION HERE
  //printf("parseMipsInstruction: write me!\n");

  return;

}

/* function to print the fields of a parsed MIPS instruction 
  will print to the output file output.txt
  */


void dumpMipsInstruction(mipsInstruction *instruction, FILE *ofp) {


  fprintf(ofp, "op: 	 	   %#12X	%d\n", instruction->op, instruction->op);

  fprintf(ofp, "rs: 	 	   %#12X	%d\n", instruction->rs, instruction->rs);

  fprintf(ofp, "rt: 	 	    %#12X	%d\n", instruction->rt, instruction->rt);

  fprintf(ofp, "rd: 	 	    %#12X	%d\n", instruction->rd, instruction->rd);

  fprintf(ofp, "shamt: 		%#12X	%d\n", instruction->shamt, instruction->shamt);

  fprintf(ofp, "funct: 		%#12X	%d\n", instruction->funct, instruction->funct);

  fprintf(ofp, "tar: 		  %#12X 	%d\n", instruction->target, instruction->target);

  fprintf(ofp, "imm/add: 	%#12X 	%d\n", instruction->immedOrAddress, instruction->immedOrAddress);

  //printf("dumpMipsInstruction: write me!\n");
}
