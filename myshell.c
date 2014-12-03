#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

int execute(char *command) {
  int i = 0;
  char path[1050] = {"/bin/"};
  char* commandList[64];
  commandList[i++] = strtok(command," \r\t\n");
  while((commandList[i++]=strtok(NULL," \r\t\n")) != NULL);
  if(commandList[0] == NULL)
    return 1;
  if(strcmp(commandList[0],"exit")) {
    if(!strcmp(commandList[0],"cd")){
      if(chdir(commandList[1]) != 0){
	printf("Unable to change Directory!\n");
	fflush(stdout);
      }
      return 1;
    }
    else{
      int pid = fork();

      if(pid == 0){
	strcat(path,commandList[0]);
	if(execv(path,commandList) < 0){
	  printf("Command Not Found!\n");
	  fflush(stdout);
	}
      }
      
      else{
	wait(NULL);
	return 1;
      }
    }
  }

  else
    return 0;
}

void interruptHandler(int sigNum){
  if(sigNum == SIGINT){
    fflush(stdout);
  }
}

void main() {
  char buffer[512];
  char *command;
  signal(SIGINT,interruptHandler);
  while(1) {
    printf("User@Z3TAShell:$ ");
    command = fgets(buffer,sizeof(buffer),stdin);
    if(!command || !execute(command)) break;
  }
}
