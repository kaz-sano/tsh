// parse.c

char *get_cmd();
char **parse(char *line);

//execute.c

int  execute(char **args);
void freeargs(char **args);
