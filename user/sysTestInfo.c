#include "../kernel/types.h"
#include "../kernel/stat.h"
#include "../user/user.h"
#include "../kernel/sysinfo.h"

int main(int argc, char **argv){
  printf("systest \n");
  struct sysinfo info;
  sysinfo(&info);
  printf("using info in test:%d\n",info.uptime);
  exit(0);
}