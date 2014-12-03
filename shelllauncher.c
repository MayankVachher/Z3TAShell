#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(){
  int pid = fork();
  if(pid == 0) {
    printf("%d\n",pid);
    system("gnome-terminal -t 'Z3TAShell' -x ./myshell.o");
    exit(0);
  }
  else{
    printf("%d\n",pid);
    wait(NULL);
    exit(0);
  }
  return 0;
}
