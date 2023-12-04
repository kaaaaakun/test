#include <stdio.h>
#include <errno.h>
#include <histedit.h>

int main() {
    const char *line;
    int count;
    EditLine *el;

    // EditLine 構造体の初期化などが必要なら行う

    // el_gets() を呼び出して TTY から1行読み込む
    line = el_gets(el, &count);

    // エラーチェック
    if (line == NULL) {
        if (count == -1) {
            perror("Error reading from TTY");
        } else {
            printf("No characters read from TTY\n");
        }
    } else {
        // 成功時の処理
        printf("Read %d characters: %s\n", count, line);
        // 注意: line をコピーして保持する必要があるかもしれません。
    }

    return 0;
}

