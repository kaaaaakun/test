#include <stdio.h>
#include <pthread.h>
#include <libc.h>

typedef struct {
    int thread_id;
    int *cnt_ptr;
    pthread_mutex_t *mutex_ptr;
    pthread_mutex_t *print_ptr;
} ThreadInfo;

void *routine(void *arg)
{
    ThreadInfo *info = (ThreadInfo *)arg;

    for (int i = 0; i < 5; i++) {
        pthread_mutex_lock(info->mutex_ptr);
        (*(info->cnt_ptr))++;
        pthread_mutex_unlock(info->mutex_ptr);

        pthread_mutex_lock(info->print_ptr);
        printf("Thread %d incremented cnt to %d\n", info->thread_id, *(info->cnt_ptr));
        pthread_mutex_unlock(info->print_ptr);
		usleep(1000);
    }

    return NULL;
}

int main(void)
{
    pthread_t p1, p2;
    pthread_mutex_t mutex;
    pthread_mutex_t print;
    int cnt = 0;

    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&print, NULL);

    ThreadInfo info1 = {1, &cnt, &mutex, &print};
    ThreadInfo info2 = {2, &cnt, &mutex, &print};

    pthread_create(&p1, NULL, routine, (void *)&info1);
    pthread_create(&p2, NULL, routine, (void *)&info2);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_mutex_destroy(&print);

    printf("Final cnt -> %d\n", cnt);

    return 0;
}

