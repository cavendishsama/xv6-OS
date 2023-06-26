#include "../kernel/types.h"
#include "../kernel/memlayout.h"
#include "../user/user.h"
#include "../kernel/riscv.h"

void
simple_test()
{
int total_pages=(PHYSTOP - KERNBASE) / PGSIZE;

int num_allocated_pages = (2 * total_pages) / 3;
int num_bytes = num_allocated_pages * PGSIZE;

char *ptr = sbrk(num_bytes);
if (ptr == (char*)-1) {
    // Error handling if sbrk fails
    printf("sbrk failed\n");
    // Additional cleanup code, if necessary
} else {
    // Allocation successful
    printf("Memory allocated without writing anything\n");
}
    printf("hi");
fork(); 
}

void main(void){
    
    simple_test();
}

