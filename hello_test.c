#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void)
{
  int x = hello();
  printf(1, "hello() returned %d\n", x);
  exit();
}
