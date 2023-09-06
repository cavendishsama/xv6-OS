#include "./kernel/types.h"
#include "./kernel/stat.h"
#include "./user/user.h"
#include "./kernel/sysinfo.h"

int main(int argc, char **argv){
    struct sysinfo info;
    sysinfo(&info);
    printf("uptime = %d ticks\n", info.uptime);
    // printf("uptime approximately ~= %.1fseconds\n", info.uptime * 0.1);
    printf("Total Ram = %d\n", info.totalram);
    printf("Free Ram = %d\n", info.freeram);
    printf("Procs = %d\n", info.procs);
    printf("successful\n");
    exit(0);
}