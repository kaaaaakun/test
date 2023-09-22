#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>

// シグナルハンドラ関数
void handleCtrlC(int sig)
{
    if (sig == SIGINT)
    {
        //printf("\033[K"); 지워버리는 것을 원하지는 않았음.
        printf("nanoshell$ \n");
    }

    if (rl_on_new_line() == -1) // readline으로 설정한 문자열을 한 번 출력한다?
        exit(1);
//    rl_replace_line("", 1); // 프롬프트에 이미 친 문자열을 싹 날려준다.
    rl_redisplay();         // 프롬프트 커서가 움직이지 않게 해준다.
}

int main() {
    // Ctrl+Cに対してカスタムシグナルハンドラを設定
    signal(SIGINT, handleCtrlC);
    signal(SIGQUIT, SIG_IGN);    // CTRL + /
    char* input;

    while (1) {
        input = readline("Enter text: "); // ユーザーからの入力を受け取る
        if (input == NULL) {
            break; // Ctrl+D（EOF）を検出した場合など、EOFを検出したら終了
        }
        
        // 入力を処理することも可能
        printf("You entered: %s\n", input);

        free(input); // readlineが割り当てたメモリを解放
    }

    return 0;
}

