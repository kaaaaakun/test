#include <stdio.h>
// NDEBUGを定義する場合は、ここより前
#include <assert.h>

int main(void) {
      int a=10, b=5, g=0;

      g = a + b;

      assert(g==15);
      assert(g==14);

      printf("%d\n", g);
	return 0;
}
