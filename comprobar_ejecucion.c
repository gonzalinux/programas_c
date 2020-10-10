#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

int condicion=1;
int x;

int main(int argc, char** argv){
  char *argumentos[3] = {"pgrep", "verificar_actividad", NULL};

  char *argumentos2[5]= {"./verificar_actividad", "0", "echo", "ha ido mal", NULL};
  int cualarg=1;
  pid_t pid;
  while(1){



    pid=fork();
    switch(pid){
      case -1:
      printf("ha habido un error");
      exit(0);
      case 0:
      if(cualarg){
        printf("adawdawd");
        execvp(argumentos[0],argumentos);

      }
      else{
        cualarg=1;
      printf("xd");
      }
        execvp(argumentos2[0], argumentos2);

        exit(0);
      default:
        wait(&x);
        if(WIFEXITED(x))
          if(WEXITSTATUS(x)!=0){
            printf("wtf");
            cualarg=0;





          }

    }
  }
}
