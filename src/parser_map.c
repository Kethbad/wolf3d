#include "wolf3d.h"
#include "stdio.h"

void RemoveSpacesAndOthers(char* source)
{
  char* i = source;
  char* j = source;
  while(*j != 0)
  {
    *i = *j++;
    if(*i == '0' || *i == '1')
      i++;
  }
  *i = 0;
}

int checknumber(char* source)
{
  int i = 0;

  while(source[i] != '\0')
    i++;
  return(i);
}

int checknumberofcolumn(int line_number,int nbchar, char *buffer)
{
  int nbchar2;
  if(line_number > 0)
  {
    nbchar2 = checknumber(buffer);
    if(nbchar == nbchar2)
      nbchar = nbchar2;
    else
    {
      printf("wrong number of line\n");
      return(0);
    }

  }
  else
    nbchar = checknumber(buffer);
  return(nbchar);
}

char **parse_map(){
  FILE *fp;
  size_t buffer_size = 80;
  char *buffer = malloc(buffer_size * sizeof(char));
  int line_number = 0;
  char **map;
  int nbchar;

  fp = fopen("asset/map", "r");
  if(NULL == fp)
    return(NULL);
  map = malloc(1000 * sizeof(char*));
  while(-1 != getline(&buffer, &buffer_size, fp))
  {
    map[line_number] = malloc(sizeof(char*));
    buffer[buffer_size] = '\0';
    RemoveSpacesAndOthers(buffer);
    nbchar = checknumberofcolumn(line_number, nbchar, buffer);
    if(nbchar == 0)
      return(NULL);
    map[line_number] = strdup(buffer);
    ++line_number;
  }
  return(map);

}
