#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"
#include "sysinfo.h"

uint64
sys_exit(void)
{
  int n;
  argint(0, &n);
  exit(n);
  return 0;  // not reached
}

uint64
sys_getpid(void)
{
  return myproc()->pid;
}

uint64
sys_fork(void)
{
  return fork();
}

uint64
sys_wait(void)
{
  uint64 p;
  argaddr(0, &p);
  return wait(p);
}

uint64
sys_sbrk(void)
{
  uint64 addr;
  int n;

  argint(0, &n);
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

uint64
sys_sleep(void)
{
  int n;
  uint ticks0;

  argint(0, &n);
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(killed(myproc())){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

uint64
sys_kill(void)
{
  int pid;

  argint(0, &pid);
  return kill(pid);
}

// return how many clock tick interrupts have occurred
// since start.
uint64
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

uint64
sys_getHelloWorld(void)
{
  return getHelloWorld();
}
uint64
sys_getProcTick(void)
{
  // uint xticks;
  // acquire(&tickslock);
  // xticks = ticks;
  // release(&tickslock);
  // return xticks;
  int pid;

  argint(0, &pid);
  // /* get syscall argument */
  // if (argint(0, &pid) < 0)
  //     return -1;
  
  // printf(pid);
  return printname(pid);
}
uint64
sys_sysinfo(void)
{
  uint64 in_struc;
  // argint(0, &pid);
  // /* get syscall argument */
  // if (argint(0, &pid) < 0)
  //     return -1;
  argaddr(0,  &in_struc);
  // printf(pid);
  systeminfo(in_struc);
  return 1;
}
int
sys_changePolicy(void)
{
  printf("^^^^^^^^^^^^^^^");
  int schedNum;
  argint(0, &schedNum);
  return changePolicy(schedNum);
}

int
sys_getctime(void)
{
  int pid;
  argint(0, &pid);
  return (int)getctime(pid);
}

int
sys_getttime(void)
{
  int pid;
  argint(0, &pid);
  return getttime(pid);
}

uint64
sys_getrutime(void)
{
  int pid;
  argint(0, &pid);
  return getrutime(pid);
}

uint64 sys_Newwait(void) {
  int *retime, *rutime, *stime;
  
  argint(0, (void*)&retime);
  argint(1, (void*)&rutime);
  argint(2, (void*)&stime);
  // if (argptr(0, (void*)&retime, sizeof(retime)) < 0)
  //   return -1;
  // if (argptr(1, (void*)&rutime, sizeof(retime)) < 0)
  //   return -1;
  // if (argptr(2, (void*)&stime, sizeof(stime)) < 0)
  //   return -1;
  return wait2(retime, rutime, stime);
}