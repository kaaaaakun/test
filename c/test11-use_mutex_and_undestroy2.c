#include <pthread.h>

pthread_mutex_t mutex;

int main() {
  pthread_mutexattr_t attr;

  // 属性オブジェクトを初期化
  pthread_mutexattr_init(&attr);

  // 再帰的なロックを許可する属性を設定
  pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE_NP);

  // ミューテックスを初期化
  pthread_mutex_init(&mutex, &attr);

  // ミューテックスを再帰的にロックする
  pthread_mutex_lock(&mutex);
  pthread_mutex_lock(&mutex);

  // ミューテックスをアンロックする
  pthread_mutex_unlock(&mutex);
  pthread_mutex_unlock(&mutex);

  return 0;
}
