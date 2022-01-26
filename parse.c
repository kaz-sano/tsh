/*
 *
 * char *get_cmd()
 *  read command line
 *  return: unparsed command line
 *
 * char **parse(char *line)
 *  parse command line into array of tokens
 *  return: array of pointers to the tokens
 *
 * void freeargs(char **args)
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tsh.h"

#define TOK_DELIM " \t\n"
#define BUFSIZE   1024

char *get_cmd(){
  char *buffer;
  int  c;
  int  position = 0;

  buffer = malloc(BUFSIZE * sizeof(char));

  while (1){
    c = getchar();

    if ((c == EOF) || (c == '\n')){
      buffer[position] = '\0';
      return buffer;
    }
    else {
      buffer[position++] = c;
    }
  }
}

char **parse(char *line){
  char **tokens;
  char *token, *token_copy;
  int  tokenlen;
  int  position = 0;

  tokens = malloc(BUFSIZE * sizeof(char));

  token = strtok(line, TOK_DELIM);
  while (token != NULL){
    tokenlen = strlen(token);
    token_copy = malloc((tokenlen + 1) * sizeof(char));

    strcpy(token_copy, token);

    tokens[position++] = token_copy;

    // need error handling here

    token = strtok(NULL, TOK_DELIM);
  }

  tokens[position] = NULL;
  return tokens;
}

void freeargs(char **args){
  char **i;
  i = args;

  while (*i != NULL){
    free(*i);
    i++;
  }
  free(args);
}
