/*
 * int execute(char **args);
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "tsh.h"

int execute(char **args){
  int pid, wpid;
  int status;

  if (args[0] == NULL){                 // error handling
    return 1;
  }

  if ((pid = fork()) == -1){            // on failure
    perror("fork");
  }
  else if (pid == 0){

    // child process

    signal(SIGINT, SIG_DFL);
    signal(SIGQUIT, SIG_DFL);
    execvp(args[0], args);
    perror("cannot execute command");
    exit(1);
  }
  else {

    // parent process

    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }
  return 1;
}

