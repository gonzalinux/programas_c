#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
void bucle();
int condicion=1;

int main(int argc, char** argv){
  if(argc<3){
    fprintf(stderr,"Uso: verificar_actividad minutos mandato [args]");
    exit(1);
  }

  int x,s=0;
  int numeroobtenido;
  signal (SIGCHLD, bucle);
  pid_t pid1;
  while(1){
sleep(atoi(argv[1])*60);

  switch (pid1=fork()) {

    case -1:
        perror("fork");exit(1);
    case 0:
      printf("Introduzca %d\n", getpid()%10);
      scanf("%d\n", &numeroobtenido);
      if(numeroobtenido==getpid()%10){
        exit(0);
      }
      else{
        exit(1);
      }





    default:

    while(condicion){
      sleep(2);
      x++;
      printf("2sec\n");
      if(x==30){
        kill(pid1,9);
      }
      //beep();

    }
      wait(&s);
      if(WIFEXITED(s))
        if(WEXITSTATUS(s)!=0){

          for(int i=2;i<argc)
          execv();
          }

  }
}

}




void bucle(){
  condicion=0;
}
