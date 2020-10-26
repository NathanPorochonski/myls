#include <stdio.h>
#include <stdlib.h> 
#include <dirent.h>
#include <string.h>
#include "stringout.h"

#define HERE "."

int main(int argc, char *argv[]){

  char *path;

  if(argc == 1)
  {
    path = HERE;
  }else
  {
    path = argv[1];
  }
  
  DIR *dir_ptr;
  struct dirent *direntp;
  
  dir_ptr = opendir(path);

  char *buf = (char*) malloc(1024);
  const char *ptr[8192];
  int bufPos = 0;
  int ptrPos = 0;
  int bufFactor = 1;

  //Reads each filename in a directory and builds a buffer and pointer array with them.
  while ((direntp = readdir(dir_ptr)) != NULL){
   
    char *name = direntp -> d_name;
    int nameLength = strlen(name);
    int bufSize = 16 * bufFactor + 8;

    //Checks if more memory must be allocated to the buffer array
    if (bufSize - bufPos <= nameLength){
      
      int factorCount = 1;
      factorCount = nameLength % 16;
      bufFactor = bufFactor + factorCount;
      buf = malloc(16 * bufFactor);
    }
   
    //Assigns pointer to the filename in the buffer
    ptr[ptrPos] = &buf[bufPos];
    
    //Adds next filename to the buffer
    for (int i = 0; i < nameLength; i++){
      buf[bufPos] = name[i];
      bufPos++;
    }

    buf[bufPos] = '\0';
    bufPos++;
    ptrPos++;
  }
  if(argc <= 2)
  {
      stringout(ptr, argv[2]);

  }else
  {
    stringout(ptr, argv[2]);
  }

  return 0;
}