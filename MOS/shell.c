#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_CMD 512

void show_prompt()
{
    printf("> ");
}

void read_command(char **command, char* parameters[])
{
    char command_raw[MAX_CMD];
    char *r;

    *command = NULL;
    r = fgets(command_raw, MAX_CMD, stdin);

    printf("cmd: %s\n", command_raw);
    //foo bar baz "bla fasel" > pong
    if (r) {
        char delim = ' ';
        char *p;
        p = strtok(command_raw, &delim);
        while (p) {
            if (*command == NULL) {
                *command = strdup(p);
            }
            p = strtok(NULL, &delim);
        }
    }
}

int main()
{
    char *command;
    char* parameters[5];
    int status;

    while (1) {
        show_prompt( );
        read_command(&command, parameters);
    
        if (command != NULL) {
            if (fork() != 0) {
                waitpid(-1, &status, 0);
            } else {
                parameters[0] = command;
                parameters[1] = NULL;
                printf("%s %s\n",command, parameters[0]);
                execve(command, parameters, 0);
                return 0;
            }

            free(command);
        }
    }

    return 0;
}
