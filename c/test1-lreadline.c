#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
static char *line_read = (char *)NULL;

void freeLineRead()
{
    if (line_read) {
        free(line_read);
        line_read = (char*)NULL;
    }
}

char* rl_gets()
{
    freeLineRead();
    line_read = readline(">>> ");
    if (line_read && *line_read) {
        add_history(line_read);
    }
    return (line_read);
}

int main(int argc, char const *argv[])
{
    char *buf = (char *)NULL;
    int flag = 1;
    while (flag) {
        buf = rl_gets();
        if (*buf == '.') {
            flag = 0;
        }
        printf("[%s]\n", buf);
    }
    freeLineRead();
    return 0;   
}
