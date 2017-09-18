#include "file_utils.h"
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <sys/stat.h>


int read_file( char* filename, char **buffer ){
    //Create pointer to filename
   FILE *inputFile;
   
   //Code Provided by Professor Woodring to get File Size
   struct stat st;
   stat(filename, &st);
   int size = st.st_size;

   
   //Open File for Reading
   inputFile = fopen(filename,"r");

   if(inputFile == NULL){
       fprintf(stderr, "Prolbem openining File\n");
       return 0;
   }
   //point buffer to a new array of characaters
   char *myInput;
   myInput = malloc(size  * sizeof(char));

   //Wiki Code for fgetc()
   int c; // note: int, not char, required to handle EOF
   int i=0;
   while ((c = fgetc(inputFile)) != EOF) { // standard C I/O file reading loop
    char convertFromInt = (char) c;
    myInput[i] = convertFromInt;
    i++;
   }

   *buffer = myInput;
   //returns size of array
   return i;
}
int write_file( char* filename, char *buffer, int size){
   
   FILE *outputFile;

   //Open up file to wrtie to 
   outputFile = fopen(filename,"w");

   for(int i = 0; i<size;i++){
        fputc( (int) buffer[i], outputFile);
   }
   
   fclose(outputFile);

   return 0;
}



