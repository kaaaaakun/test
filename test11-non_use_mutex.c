#include <stdio.h>
#include <pthread.h>

int cnt = 0;

void *routine(void *p)
{
    for (int i = 0; i < 10000; i++)
        cnt++;
    return (NULL);
}

int main(void)
{
    pthread_t p1, p2;

    // 2つのスレッドで並列処理する
    pthread_create(&p1, NULL, &routine, NULL);
    pthread_create(&p2, NULL, &routine, NULL);

    // 終了するまで待つ
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    printf("cnt -> %d\n", cnt);
}

