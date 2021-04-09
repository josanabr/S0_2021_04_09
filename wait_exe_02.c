#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int fibonacci(int);

int main(int argc, char* argv[]) {
  pid_t pid;
  int resultado = 0;
  int fibo;
  int estado;

  pid = fork();
  assert(pid >= 0);

  if (argc == 2) {
    fibo = atoi(argv[1]); // '50' -> 50
  } else {
    fibo = 35;
  }

  if (pid == 0) {
    resultado = fibonacci(fibo);
  } else {
    wait(&estado);
    if (WIFEXITED(estado)) {
      printf("Mi hijo salido con estado %d\n",WEXITSTATUS(estado));
    }
  }
  printf("Resultado %d\n",resultado);

  if (resultado > 0) { 
    printf("Correcto\n");
    return 0;
  } else {
    return 1;
  }
}

int fibonacci(int num)
{
    if (num == 0)
        return 0;
    else if (num == 1)
        return 1;
    else
        return fibonacci(num-1) + fibonacci(num-2);
}
