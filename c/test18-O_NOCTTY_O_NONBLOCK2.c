#include <stdio.h>
#include <termios.h>
#include <unistd.h>

void setNonCanonicalMode() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void restoreCanonicalMode() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

int main() {
    setNonCanonicalMode();

    char buffer[1500]; // 入力された文字を保存するバッファ
    int index = 0;    // バッファ内の次に書き込む位置

    printf("> ");
    fflush(stdout);

    while (1) {
        char c;
        if (read(STDIN_FILENO, &c, 1) == 1) {
            if (c == '\n') {
                break; // Enterキーが押されたら終了
            } else if (c == 127) {
                // バックスペース（ASCIIコードで127）が押されたら1文字削除
                if (index > 0) {
                    printf("\b \b"); // カーソルを1つ戻してスペースで上書きし、再度カーソルを戻す
                    index--;
                }
            } else {
                buffer[index++] = c;
                printf("%c", c);
            }
            fflush(stdout);
        }
    }

    buffer[index] = '\0'; // 文字列の終端を追加

    printf("\nYou entered: %s\n", buffer);

    restoreCanonicalMode();

    return 0;
}

