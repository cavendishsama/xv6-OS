# xv6 Operating System
- contributors
> phase1: [cavendishsama](https://https://github.com/cavendishsama)<br/>
> Phase2 & phase3: [cavendishsama](https://https://github.com/cavendishsama) & [pooya-sharifi](https://github.com/pooya-sharifi)

## Phase 1: Adding new System Calls into xv6-riscv
- start with [xv6-riscv](https://github.com/mit-pdos/xv6-riscv)
- `int getProcTick(void)`
> Counting number of Ticks since the advent of a process 
- `int sysinfo(struct sysinfo* info)`
> Obtain some information about the system, such as time passed since the boot, total usable and free memory, and number of processes executing

## Phase 2: Change scheduling policy
- Scheduling policy
> Default Round Robin(changing Quantum)<br/>
> First Come Firsts Serve(FCFS) 
- Change policy
- Measure times
> Waiting Time<br/>
> Turn Around Time<br/>
> CPU Burst Time<br/>
> Ready Time<br/>
> Running Time<br/>
> Termination Time<br/>
> Creation Time<br/>
> Sleeping Time

## Phase 3: Change Fork system call
- Copy on Write(Cop)
- Managing Page Fault
