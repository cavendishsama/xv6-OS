#include "../kernel/types.h"
#include "../kernel/stat.h"
#include "../user/user.h"
#include "../kernel/sysinfo.h"

int firstArray[10000];
int secondArray[10000];
int sumArray[10000];


int main(int argc, char **argv){
    changePolicy(1);
    int n = 3;
    // int pidlist[n];
    int ppid = getpid();
    int children = 0;
    // int status;
    int retime;
    int rutime;
    int stime;

    printf("parents is %d\n",ppid);
    
    for(int i=0;i<n;i++) 
    {
        // uint64 j=0;
        int p = fork();
        // pidlist[i] = p;
        if(p == 0)
        {   
            // printf("process of i entered %d \n",i);
            // int x = getpid();

            for(int i=0;i<10000;i++)
                firstArray[i]=i;
            for(int i=0;i<10000;i++)
                secondArray[i]=i;
            for(int i=0;i<10000;i++){
                sumArray[i]=firstArray[i]+secondArray[i];
                printf("%d \n",sumArray);
            }
            // for(int i=0;i<10;i++)
            //     printf("***%d \n",sumArray[i]);
            
            // printf("added %d\n",firstArray[1]);
            
            // for (int j = 0; j < 100; j++)
            // {
            //     printf("/%d/\n",sumArray[i]);
            // }
            
            // pidlist[i] = x;
            
            sleep(100);
            exit(0);
        }
        else{
            children= children +1;
           
                
            
         
        }
    
    printf("@@");
    // Newwait(&retime, &rutime, &stime);
    }
    if(getpid() == ppid){
        
        for(int i=0;i<n;i++) 
        {
            printf("going to wait");
            Newwait(&retime, &rutime, &stime);
        
        }
    }
    // for(int i=0;i<n;i++) 
    // {
    //     Newwait(&retime, &rutime, &stime);
    //     printf("we did new wait for the %d time \n",i);
    // }
    // printf("%d",pidlist[1]);
    // printf("()");
    // printf("%d\n",getpid());
    // if(getpid() == ppid){
    //     printf("!!!!!!!!!!!!!!!!");
    //     printf("number of childs %d",children);
    //     printf("parent :%d\n",ppid);
    //     sleep(20);
    //     for(int i=0;i<n;i++) 
    //     {

    //         printf("entered parents for\n");
    //         // int status;
    //         // wait(0);
    //         // printf("Child process %d exited with status %d\n", pidlist[i], status);
    //         printf("%d process pid is %d\n",i,pidlist[i]);
    //         int x = getttime(pidlist[i]);
    //         printf("ttime of proccess :%d\n",x);
    //         int y = getctime(pidlist[i]);
    //         printf("ctime of proccess :%d\n",y);
    //         int z = getrutime(pidlist[i]);
    //         printf("rutime of proccess :%d\n",z);
        
    //     }
    // }

    // // for(int i=0;i<n;i++){
    // //     printf("waiting for this %d \n",i);
    // //     wait(0);
    // //     printf("*****");
    // // }

    // printf("@@@@@");
    return 0;
}
