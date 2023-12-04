#include <stdio.h>
#include <pthread.h>

void *start_routine(void *arg) {
    printf("Thread started\n");
    int *value = (int *)arg;
    printf("Argument passed to thread: %d\n", *value);
    // 何らかの処理
    return NULL;
}

int main() {
    pthread_t thread_id;
    int arg_value = 42;

    // 新しいスレッドを作成
    int status = pthread_create(&thread_id, NULL, start_routine, (void *)&arg_value);

    if (status != 0) {
        printf("Thread creation failed\n");
        // エラーハンドリング
        // エラーコードはstatusで受け取れる
    } else {
        printf("Thread created successfully\n");

        // スレッドの終了を待つ前に
        // スレッドを分離する場合:
        pthread_detach(thread_id);
        // スレッドを終了を待つ場合:
        pthread_join(thread_id, NULL);

        printf("Main thread continuing its execution\n");
    }

    return 0;
}

