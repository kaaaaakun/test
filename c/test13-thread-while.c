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
    pthread_t p[5];
    pthread_mutex_t mutex;
    pthread_mutex_t print;
	int thread_count = 5;

    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&print, NULL);

	for (int i = 0; i < thread_count; i++)
		pthread_create(&p[i], NULL, routine, (void *)i);

	for (int i = 0; i < thread_count; i++)
	{
		char *ptr;
		pthread_join(p[i], (void **)&ptr);
		printf("join %d\n",i);
	}

    pthread_mutex_destroy(&mutex);
    pthread_mutex_destroy(&print);

    //printf("Final cnt -> %d\n", cnt);

    return 0;
}

