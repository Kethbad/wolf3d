#include "wolf3d.h"
#include "stdio.h"

char *parse_map(){
  FILE *fp;
  char **lineptr;
  size_t len = 7;
  size_t len2;

  fp = fopen("src/main.c", "r");
  printf("ok\n");
//  printf("$$$%d****", fp);
  len2 = getline(lineptr, &len, fp);
  printf("ok\n");
  printf("$$$%zu****", len2);
//  printf("$$$%s****", *lineptr);
  printf("ok\n");
  return("ded");

}
