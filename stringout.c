#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "myls.h"

void stringout(const char *ptr[], const char *flag){

  int stop = 0;
  for (int i = 0; ptr[i] != NULL; i++) {
    stop++;
  }

  if (flag== 0x0){
    
    for (int i = 0; i < stop; i++) {
      printf("%s\n", ptr[i]);
    }

  }
  else if (strcmp(flag, "-f") == 0) {
  
    const char *temp;

    for (int i = 0; i < stop; i++) {

        for (int j = i + 1; j < stop; j++) {

            if(strcmp(ptr[i],ptr[j])>0) {
              temp = ptr[i];
              ptr[i] = ptr[j];
              ptr[j] = temp;
            }
        }
    }

    for (int i = 0; i < stop; i++) {
      printf("%s\n", ptr[i]);
    }

  }
  else if ((strcmp(flag, "-b") == 0)) {

  const char *temp;

    for (int i = 0; i < stop; i++) {

        for (int j = i + 1; j < stop; j++) {

            if(strcmp(ptr[i],ptr[j])<0) {
              temp = ptr[i];
              ptr[i] = ptr[j];
              ptr[j] = temp;
            }
        }
    }

    for (int i = 0; i < stop; i++) {
      printf("%s\n", ptr[i]);
    }

  }
}