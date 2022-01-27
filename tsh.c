// pipe and redirect to be add
//
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include "tsh.h"

void setup(){
  signal(SIGINT, SIG_IGN);
  signal(SIGQUIT, SIG_IGN);
}

void tobenamed(void){

  char *cmd, *args;
  int status;

  while (status) {
    printf("tsh: ");
    cmd    = get_cmd();           // read command
    args   = parse(cmd);          // parse a string into split line
    status = execute(args);       // execute

    free(cmd);
    freeargs(args);
  }
}

int main(){

  setup();
  tobenamed();

  return 0;
}

