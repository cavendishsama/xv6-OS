#include "../kernel/types.h"
#include "../kernel/stat.h"
#include "../user/user.h"
#include "../kernel/sysinfo.h"

int main(int argc, char **argv){
    if(argc < 2){
    printf("invalid input\n");
    exit(0);
    }
    int alex;
    // printf(argc);
    for(int i=1; i<argc; i++)
        alex=changePolicy(atoi(argv[i]));
    printf("successfull\n %d",alex);
    // return 0;
    exit(0);
}