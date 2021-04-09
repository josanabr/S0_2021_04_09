#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <assert.h>

int fibonacci(int);

int main(int argc, char* argv[]) {
  pid_t pid;
  int resultado = 0;

  pid = fork();
  assert(pid >= 0);

  if (pid == 0) {
    resultado = fibonacci(50);
  } else {

  }
  printf("Resultado %d\n",resultado);
  return 0;
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
