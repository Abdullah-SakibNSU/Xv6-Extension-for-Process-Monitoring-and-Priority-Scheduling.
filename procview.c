#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

char*
state_name(int state)
{
  switch(state){
    case 0: return "UNUSED";
    case 1: return "EMBRYO";
    case 2: return "SLEEP";
    case 3: return "RUNNABLE";
    case 4: return "RUNNING";
    case 5: return "ZOMBIE";
    default: return "UNKNOWN";
  }
}

void
print_padded_int(int n, int width)
{
  int tmp = n, digits = 1;
  while(tmp >= 10){ digits++; tmp /= 10; }
  printf(1, "%d", n);
  while(digits < width){ printf(1, " "); digits++; }
}

void
print_padded_str(char *s, int width)
{
  int len = strlen(s);
  printf(1, "%s", s);
  while(len < width){ printf(1, " "); len++; }
}

int
main(void)
{
  struct pstat ps;
  int i;

  if(getprocinfo(&ps) < 0){
    printf(2, "getprocinfo failed\n");
    exit();
  }

  printf(1, "Total processes: %d\n", ps.count);
  printf(1, "\n");
  print_padded_str("PID",   6);
  print_padded_str("PPID",  6);
  print_padded_str("PRIO",  6);
  print_padded_str("STATE",   10);
  print_padded_str("SIZE",  8);
  print_padded_str("NAME",  8);
  printf(1, "\n");
  print_padded_str("---",   6);
  print_padded_str("----",  6);
  print_padded_str("----",  6);
  print_padded_str("-----",   10);
  print_padded_str("----",  8);
  print_padded_str("----",  8);
  printf(1, "\n");

  for(i = 0; i < ps.count; i++){
    print_padded_int(ps.proc[i].pid,      6);
    print_padded_int(ps.proc[i].ppid,     6);
    print_padded_int(ps.proc[i].priority, 6);
    print_padded_str(state_name(ps.proc[i].state), 10);
    print_padded_int((int)ps.proc[i].sz,  8);
    print_padded_str(ps.proc[i].name,     8);
    printf(1, "\n");
  }

  exit();
}
