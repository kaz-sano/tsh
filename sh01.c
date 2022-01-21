#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv){

  char *argbuf[argc + 1];
  int i;

  for (i = 0; i < argc; i++) {
    argbuf[i] = argv[i + 1];
    if (i == argc -1) {
      argbuf[i] = 0;
    }
  }

  execvp(argbuf[0], argbuf);

}
