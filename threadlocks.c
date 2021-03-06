#include "types.h"
#include "stat.h"
#include "user.h"
#include "threadlocks.h"
#include "x86.h"

void
thread_spin_init(struct thread_spinlock *lk)
{
  lk->locked = 0;
}

// Acquire the lock.
void
thread_spin_lock(struct thread_spinlock *lk)
{

  // The xchg is atomic.
  while(xchg(&lk->locked, 1) != 0)
    ;

  // Tell the C compiler and the processor to not move loads or stores
  // past this point, to ensure that the critical section's memory
  // references happen after the lock is acquired.
  __sync_synchronize();

}

// Release the lock.
void
thread_spin_unlock(struct thread_spinlock *lk)
{

  // Tell the C compiler and the processor to not move loads or stores
  // past this point, to ensure that all the stores in the critical
  // section are visible to other cores before the lock is released.
  // Both the C compiler and the hardware may re-order loads and
  // stores; __sync_synchronize() tells them both not to.
  __sync_synchronize();

  // Release the lock, equivalent to lk->locked = 0.
  // This code can't use a C assignment, since it might
  // not be atomic. A real OS would use C atomics here.
  asm volatile("movl $0, %0" : "+m" (lk->locked) : );

}

void
thread_mutex_init(struct thread_mutex *m)
{
  m->locked = 0;
}

// Acquire the lock.
void
thread_mutex_lock(struct thread_mutex *m)
{

  // The xchg is atomic.
  while(xchg(&m->locked, 1) != 0)
    sleep(1);

  // Tell the C compiler and the processor to not move loads or stores
  // past this point, to ensure that the critical section's memory
  // references happen after the lock is acquired.
  __sync_synchronize();

}

// Release the lock.
void
thread_mutex_unlock(struct thread_mutex *m)
{

  // Tell the C compiler and the processor to not move loads or stores
  // past this point, to ensure that all the stores in the critical
  // section are visible to other cores before the lock is released.
  // Both the C compiler and the hardware may re-order loads and
  // stores; __sync_synchronize() tells them both not to.
  __sync_synchronize();

  // Release the lock, equivalent to lk->locked = 0.
  // This code can't use a C assignment, since it might
  // not be atomic. A real OS would use C atomics here.
  asm volatile("movl $0, %0" : "+m" (m->locked) : );

}