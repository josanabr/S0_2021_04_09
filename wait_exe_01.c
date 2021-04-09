#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <assert.h>

int fibonacci(int);

int main(int argc, char* argv[]) {
  pid_t pid;

  pid = fork();
  assert(pid >= 0);

  if (pid == 0) {
    fibonacci(50);
  } else {

  }
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
