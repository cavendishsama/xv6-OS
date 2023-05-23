#include "../kernel/types.h"
#include "../kernel/stat.h"
#include "../user/user.h"
#include "../kernel/sysinfo.h"

int main(int argc, char **argv){
    int n = 2;
    int pidlist[n];
    int ppid = getpid();
    for(int i=0;i<n;i++) 
    {
        // uint64 j=0;
        int p = fork();
        pidlist[i] = p;
        if(p == 0)
        {   
            
            // int x = getpid();
            int firstArray[200];
            int secondArray[200];

            for(int i=0;i<200;i++)
                firstArray[i]=10;
            for(int i=0;i<200;i++)
                secondArray[i]=10;
            for(int i=0;i<200;i++)
                firstArray[i]=firstArray[i]+secondArray[i];
            // for(int i=0;i<10;i++)
            //     printf("%d \n",firstArray[i]);
            // printf("added %d\n",firstArray[1]);
            
            // for (int j = 0; j < 100; j++)
            // {
            //     printf(1,"/%d/ : /%d/\n",x,j);
            // }
            
            // pidlist[i] = x;
            break;
        }
    }
    if(getpid() == ppid){
        sleep(20);
        printf("parent :%d\n",ppid);
        for(int i=0;i<n;i++) 
        {
        
            printf("%d process pid is %d\n",i,pidlist[i]);
            // printf("ttime %d",getttime(pidlist[i]));
            int x = getttime(pidlist[i]);
            printf("ttime of proccess :%d\n",x);
            int y = getctime(pidlist[i]);
            printf("ctime of proccess :%d\n",y);
            int z = getrutime(pidlist[i]);
            printf("rutime of proccess :%d\n",z);
        
        }
    }
    return 0;
}