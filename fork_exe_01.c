#include <stdio.h> // std - standard, io input/output
#include <unistd.h>
#include <sys/types.h>
#include <assert.h>

int main(int argc, char* argv[]){
  int contador = 1;
  pid_t pid;

  pid = fork();

  assert(pid >= 0);

  if (pid == 0) {
    contador = contador + 5;
  } else {
    contador += 2;
  }
  printf("%d\n",contador);

  return 0;
}
