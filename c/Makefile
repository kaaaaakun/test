CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# プログラムのビルド
program: program.c
	$(CC) $(CFLAGS) program.c -o program

# プログラムの実行
run:
	TERM_SETTINGS="noncanonical" ./a.out

# クリーンアップ
clean:
	rm -f program

RM = rm -rf

del:
	$(RM) a.out
	$(RM) a.out.*
