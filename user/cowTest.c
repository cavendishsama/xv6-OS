#include "../kernel/types.h"
#include "../kernel/memlayout.h"
#include "../user/user.h"
#include "../kernel/riscv.h"

void
simple_test()
{
int total_pages=(PHYSTOP - KERNBASE) / PGSIZE;

int num_allocated_pages = (2 * total_pages) / 3;
// int num_bytes = num_allocated_pages * PGSIZE;

// char *ptr = sbrk(num_bytes);
// if (ptr == (char*)-1) {
//     // Error handling if sbrk fails
//     printf("sbrk failed\n");
//     // Additional cleanup code, if necessary
// } else {
//     // Allocation successful
//     printf("Memory allocated without writing anything\n");
// }
//     printf("hi");

char *ptr = sbrk(0);  // Get the current break (end of the data segment)
for (int i = 0; i < num_allocated_pages; i++) {
    if (sbrk(PGSIZE) == (char*)-1) {
        // Error handling if sbrk fails
        printf("sbrk failed\n");
        // Additional cleanup code, if necessary
        break;
    }

    // Write something to the allocated page
    strcpy(ptr, "Hello, page!");

    // Move the pointer to the next page
    ptr += PGSIZE;
}

int pid=fork(); 
if (pid<0){
    printf("fork failed\n");
    exit(-1);
}
if(pid == 0){
    exit(0);
}
wait(0);


char* current_brk = sbrk(0);  // Get the current break (end of the data segment)

for (int i = 0; i < num_allocated_pages; i++) {
    if (sbrk(-PGSIZE) == (char*)-1) {
        // Error handling if sbrk fails
        printf("sbrk failed\n");
        // Additional cleanup code, if necessary
        break;
    }
}

// Verify if the program break pointer has moved back
char* new_brk = sbrk(0);
if (new_brk < current_brk) {
    printf("Memory deallocated successfully\n");
} else {
    // Handle deallocation failure, if necessary
    printf("Memory deallocation failed\n");
}


printf("okay\n");
}

void main(void){
    
    simple_test();
}

