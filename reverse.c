#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"

int main(int argc,char** argv){

    if(argc<3){
        fprintf(stderr,"Not Enough Parameters\n");
        return 1;
    }

    printf("Reading File: %s\n", argv[1]);
    char *input;
    int size;
    size = read_file(argv[1], &input);

    char reverse[size];

    if(size>0){
        int j = 0;
        for(int i = size-2;i>=0;i--){
            reverse[j] = input[i];
            j++;
        }
        printf("Writing File: %s\n", argv[2]);
        write_file(argv[2],reverse,size-1);
        printf("All Done!\n");
    }

    
    free(input);
    return 0;
}