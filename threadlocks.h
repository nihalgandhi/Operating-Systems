struct thread_spinlock{

	uint locked;
};

struct thread_mutex{

        uint locked;
};

void thread_spin_init(struct thread_spinlock *);
void thread_spin_lock(struct thread_spinlock *);
void thread_spin_unlock(struct thread_spinlock *);
void thread_mutex_init(struct thread_mutex *);
void thread_mutex_lock(struct thread_mutex *);
void thread_mutex_unlock(struct thread_mutex *);