#include "types.h"
#include "stat.h"
#include "user.h"

void
busy_work(char *name, int loops)
{
  int i, j;
  for(i = 0; i < loops; i++){
    printf(1, "%s running iteration %d\n", name, i);
    for(j = 0; j < 50000000; j++){
      ;
    }
  }
}

int
main(void)
{
  int pid1, pid2;

  pid1 = fork();
  if(pid1 == 0){
    setpriority(getpid(), 1);
    busy_work("HIGH", 5);
    exit();
  }

  pid2 = fork();
  if(pid2 == 0){
    setpriority(getpid(), 8);
    busy_work("LOW", 5);
    exit();
  }

  wait();
  wait();
  exit();
}
