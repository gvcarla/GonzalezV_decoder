/*
  Template file by Lisa Ballesteros

  Main driver to read a sequence of hex numbers from stdin and print
  the fields of a MIPS instruction that are parsed from this initial
  number.

*/

// include the headers for the standard library and the io library
#include <stdlib.h>
#include <stdio.h>

// include the header for mipsInstruction.c so that we know where to find the definitions 
// for the function calls
#include "mipsInstruction.h"

int main() {

//char ch 
  // FILE pointer to use if instructions are read from a file
  FILE *ofp;

  /* declare a structure of type mipsInstruction to hold the
  fields of a decoded instruction */
   mipsInstruction decodedInstruction;

   // declare variable to hold instruction read from file
   unsigned int theInstruction;

  //code from main.c
  if ((ofp = fopen("mipsInstructions.dat","r")) == NULL)
  {
    printf("could not open output file\n");
    exit(0);
  }

   /*
   * WRITE THIS CODE!
   *
   *  Get a 8 digit hex value as input and use this as the
   * insruction to decode.  Either loop at least 4 times, prompting
   * each time for an instruction OR read the input from a file
   * until you reach EOF.
   *
   */

   //number of times the loop will run
   // number of hex values in file mipsInstructions.dat
   int  times = 11;
  
   //counter
   int counter = 0;

  while(counter < times)
  {

    printf("enter hexadecimal number to decode\n");

    //scans instrctions
    unsigned int scan = scanf("%x", &theInstruction);

    //prints the instruction
    fprintf(ofp, "instruction:          %#12x, %d\n", theInstruction, theInstruction); 

    //passes mips structure
    parseMipsInstruction(theInstruction, &decodedInstruction);

    dumpMipsInstruction(&decodedInstruction, ofp);
    

      //from main.c
      char ch;
      while ((ch = getchar()) != '\n' && ch != EOF);
      /* scan non-zero (or true) if scanf was successful */
      if (scan) {
      counter++;
      }
      else {
      printf("Error: expected an integer\n");
    }
  }

  fclose(ofp);

  // declare variable to hold instruction read from file
    
    
  //printf("main: Write me!\n");



    /*
     * WRITE YOUR CODE HERE!!!
     * 1) decode the instruction and fill the mipsInstruction structure
     * 2) display the instruction and decoded fields
     */    // display it as a hex value of 8 digits and a decimal value
    
  //  printf("%#.8x, %d\n", theInstruction,theInstruction);



  return 0;
}
