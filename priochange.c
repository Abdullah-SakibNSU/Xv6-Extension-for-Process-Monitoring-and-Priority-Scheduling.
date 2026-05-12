#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void)
{
  int mypid = getpid();

  printf(1, "My pid is %d\n", mypid);

  if(setpriority(mypid, 2) < 0){
    printf(1, "Failed to set priority\n");
    exit();
  }

  printf(1, "Priority changed successfully for pid %d\n", mypid);
  exit();
}
