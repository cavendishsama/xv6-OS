#include "./kernel/types.h"
#include "./kernel/stat.h"
#include "./user/user.h"

int
main(int argc, char **argv)
{
  int i;

  if(argc < 2){
    printf("usage: pname pid...\n");
    exit(0);
  }
  for(i=1; i<argc; i++)
    getProcTick(atoi(argv[i]));
  exit(0);
}