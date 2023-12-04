#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;  // ミューテックスの実体を定義
int shared_variable = 0;

void *increment_thread(void *arg) {
    for (int i = 0; i < 10; i++) {
        // ミューテックスをロック
        pthread_mutex_lock(&mutex);

        // クリティカルセクション
        shared_variable++;
        printf("Thread: Incremented. New value: %d\n", shared_variable);

        // ミューテックスをアンロック
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main() {
    // ミューテックスを初期化
    pthread_mutex_init(&mutex, NULL);

    pthread_t thread_id;
    int arg_value = 42;

    // 新しいスレッドを作成
    int status = pthread_create(&thread_id, NULL, increment_thread, (void *)&arg_value);

    if (status != 0) {
        printf("Thread creation failed\n");
        // エラーハンドリング
    } else {
        printf("Thread created successfully\n");

        // スレッドの終了を待つ
        pthread_join(thread_id, NULL);

        // メインスレッドもクリティカルセクションに入る
        for (int i = 0; i < 10; i++) {
            // ミューテックスをロック
            pthread_mutex_lock(&mutex);

            // クリティカルセクション
            shared_variable++;
            printf("Main: Incremented. New value: %d\n", shared_variable);

            // ミューテックスをアンロック
            pthread_mutex_unlock(&mutex);
        }
    }

    // ミューテックスを解放
    pthread_mutex_destroy(&mutex);

    return 0;
}

