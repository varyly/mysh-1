#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>


#include "commands.h"
#include "built_in.h"
#include "utils.h"


void sig_handler(){
printf("\n")}
int main()
{
  char buf[8096];

  while (1) {
signal(SIGTSTP,sig_handler);
signal(SIGINT,sig_handler);
    fgets(buf, 8096, stdin);

    struct single_command commands[512];
    int n_commands = 0;
    mysh_parse_command(buf, &n_commands, &commands);

    int ret = evaluate_command(n_commands, &commands);

    free_commands(n_commands, &commands);
    n_commands = 0;

    if (ret == 1) {
      break;
    }
  }

  return 0;
}
