#include "../kernel/types.h"
#include "../kernel/stat.h"
#include "../user/user.h"
#include "../kernel/sysinfo.h"

int firstArray[10000];
int secondArray[10000];
int sumArray[10000];

int main(int argc, char **argv){
    changePolicy(1);
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
            printf("process of i entered %d \n",i);
            // int x = getpid();

            for(int i=0;i<10000;i++)
                firstArray[i]=i;
            for(int i=0;i<10000;i++)
                secondArray[i]=i;
            for(int i=0;i<10000;i++){
                sumArray[i]=firstArray[i]+secondArray[i];
            }
            // for(int i=0;i<10;i++)
            //     printf("%d \n",firstArray[i]);
            // printf("added %d\n",firstArray[1]);
            
            // for (int j = 0; j < 100; j++)
            // {
            //     printf(1,"/%d/ : /%d/\n",x,j);
            // }
            
            // pidlist[i] = x;
            // exit(p);
            // sleep(2000);
            exit(0);
        }
        else{
            // sleep(1000);
        }
    printf("@@");
    }
    printf("()");
    printf("%d\n",getpid());
    if(getpid() == ppid){
        printf("!!!!!!!!!!!!!!!!");
        
        sleep(100);
        printf("parent :%d\n",ppid);
        for(int i=0;i<n;i++) 
        {
        
            printf("%d process pid is %d\n",i,pidlist[i]);
            int x = getttime(pidlist[i]);
            printf("ttime of proccess :%d\n",x);
            int y = getctime(pidlist[i]);
            printf("ctime of proccess :%d\n",y);
            int z = getrutime(pidlist[i]);
            printf("rutime of proccess :%d\n",z);
        
        }
    }
    printf("@@@@@");
    return 0;
}