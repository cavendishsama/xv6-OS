#include "../kernel/types.h"
#include "../kernel/stat.h"
#include "../user/user.h"
#include "../kernel/sysinfo.h"

int main(int argc, char **argv){
  struct sysinfo info;
  // float seconds =info.uptime * 0.1;
  sysinfo(&info);
  printf("Ticks:%d\n",info.uptime);
  printf("number of process:%d\n",info.procs);
  printf("free ram:%d\n",info.freeram);
  printf("total ram:%d\n",info.totalram);
  exit(0);
}