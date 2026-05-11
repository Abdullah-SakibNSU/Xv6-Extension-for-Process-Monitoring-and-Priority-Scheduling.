#ifndef _PSTAT_H_
#define _PSTAT_H_

#define MAXPROC 64
#define NAMELEN 16

struct pinfo {
  int inuse;
  int pid;
  int ppid;
  int state;
  uint sz;
  int priority;
  char name[NAMELEN];
};

struct pstat {
  int count;
  struct pinfo proc[MAXPROC];
};

#endif
