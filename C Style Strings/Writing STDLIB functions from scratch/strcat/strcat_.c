#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* strcat_(char *src, char* dst){
  size_t ONE = strlen(src);
  size_t TWO = strlen(dst);
  char *returnThis = NULL;
  returnThis = malloc((ONE+TWO) * sizeof(char));
  return returnThis;
}
