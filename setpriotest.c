#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int pid, pr;

  if(argc != 3){
    printf(1, "Usage: setpriotest pid priority\n");
    exit();
  }

  pid = atoi(argv[1]);
  pr = atoi(argv[2]);

  if(setpriority(pid, pr) < 0){
    printf(1, "setpriority failed\n");
    exit();
  }

  printf(1, "priority of pid %d set to %d\n", pid, pr);
  exit();
}
