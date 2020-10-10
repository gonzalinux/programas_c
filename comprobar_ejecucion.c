#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

int condicion=1;
int x;

int main(int argc, char** argv){
  char **argumentos = {"pgrep", "verificar_actividad", NULL};
  char **argumentos2= {"./verificar_actividad", "0", "echo", "ha ido mal", NULL};
  int cualarg=0;
  pid_t pid;
  while(1){



    pid=fork();
    switch(pid){
      case 0:
      if(cualarg)
        execvp("pgrep",argumentos);
        else
        execvp(argumentos2[0], argumentos2);

        exit(0);
      default:
        wait(&x);
        if(WIFEXITED(x))
          if(WEXITSTATUS(x)!=0){
            printf("wtf");
            cualarg=1;





          }

    }
  }
}
