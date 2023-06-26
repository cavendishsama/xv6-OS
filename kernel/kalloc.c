// Physical memory allocator, for user processes,
// kernel stacks, page-table pages,
// and pipe buffers. Allocates whole 4096-byte pages.

#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "riscv.h"
#include "defs.h"

#define REF_CNT_IDX(pa) (((pa) - KERNBASE) / PGSIZE)

void freerange(void *pa_start, void *pa_end);

extern char end[]; // first address after kernel.
                   // defined by kernel.ld.

struct run {
  struct run *next;
};

struct {
  struct spinlock lock;
  struct run *freelist;
} kmem;

static struct{
//a lock and an array for each page reference count
  struct spinlock lock;
  int cnt[REF_CNT_IDX(PHYSTOP)];
}kref;

void kref_lock(){
  acquire(&kref.lock);
}

void kref_unlock(){
  release(&kref.lock);
}

static void set_refcnt (uint64 pa, int cnt){
  kref.cnt[REF_CNT_IDX(pa)] = cnt;
}

uint64 inc_refcnt (uint64 pa){
  return ++kref.cnt [REF_CNT_IDX(pa)];
}

uint64 dec_refcnt(uint64 pa){
  return --kref.cnt [REF_CNT_IDX(pa)];
}

void ref_init_cnt() {
    
  // Initialize the reference count array
  for (int i = 0; i < REF_CNT_IDX(PHYSTOP); i++) {
      kref.cnt[i] = 0;
  }
}


void
kinit()
{
  initlock(&kmem.lock, "kmem");
  // // Initialize the lock
  initlock(&kref.lock, "kref");
  ref_init_cnt();

  freerange(end, (void*)PHYSTOP);
}

void
freerange(void *pa_start, void *pa_end)
{
  char *p;
  p = (char*)PGROUNDUP((uint64)pa_start);
  for(; p + PGSIZE <= (char*)pa_end; p += PGSIZE)
    kfree(p);
}

// Free the page of physical memory pointed at by pa,
// which normally should have been returned by a
// call to kalloc().  (The exception is when
// initializing the allocator; see kinit above.)
void
kfree(void *pa)
{
  struct run *r;



  if(((uint64)pa % PGSIZE) != 0 || (char*)pa < end || (uint64)pa >= PHYSTOP)
    panic("kfree");
  // /acquire kref.lock
  kref_lock();
  //decrement kref.cnt for *pa
  dec_refcnt((uint64)pa);
  //if not zero, release kref.lock and return
  if(kref.cnt[REF_CNT_IDX((uint64)pa)]>0){
    kref_unlock();
    // printf("%d",kref.cnt[REF_CNT_IDX((uint64)pa)]);
    return ;
  }
  kref_unlock();
  //release and continue with the function if zero
  // Fill with junk to catch dangling refs.
  memset(pa, 1, PGSIZE);

  r = (struct run*)pa;
  

  acquire(&kmem.lock);
  r->next = kmem.freelist;
  kmem.freelist = r;
  release(&kmem.lock);
}

// Allocate one 4096-byte page of physical memory.
// Returns a pointer that the kernel can use.
// Returns 0 if the memory cannot be allocated.
void *
kalloc(void)
{
  struct run *r;

  acquire(&kmem.lock);
  r = kmem.freelist;
  if(r)
    kmem.freelist = r->next;
  release(&kmem.lock);

  if(r){
  //if r != NULL then set reference count to one
    kref_lock();
    set_refcnt((uint64)r,1);
    // printf("allocated %d",kref.cnt[REF_CNT_IDX((uint64)r)]);
    kref_unlock();
    memset((char*)r, 5, PGSIZE); // fill with junk
  }
  return (void*)r;
}

// Get the number of bytes of free memory
int
freemem(void)
{
  int n = 0;
  struct run *r;
  acquire(&kmem.lock);
  
  for (r = kmem.freelist; r; r = r->next)
    ++n;

  release(&kmem.lock);

  return n * 4096;
}
long int 
totalmem(void)
{
  return (PHYSTOP - KERNBASE) ;
}