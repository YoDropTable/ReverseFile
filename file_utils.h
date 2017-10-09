#ifndef FILE_UTILS_H
#define FILE_UTILS_H

//REad File
int read_file( char* filename, char **buffer );
//Write to file
int write_file( char* filename, char *buffer, int size);

#endif