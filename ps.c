#include "types.h"
#include "stat.h"
#include "user.h"
#include "uproc.h"
#include "param.h"

int
main(int argc, char *argv[])
{
  struct uproc *myproc = (struct uproc*)malloc(sizeof(struct uproc));
  int i;
  for(i = 1; i < NPROC; i++)
  {
    if((getprocinfo(i,myproc)) == 1)
    {
      printf(1, "Process name:%s\n", myproc->name);
      printf(1, "Process ID:%d\n", myproc->pid);
      printf(1, "Parent Process ID:%d\n", myproc->parentid);
      printf(1, "Process size:%d\n", myproc->size);
      printf(1, "Process state:%s\n", myproc->state);
      printf(1, "Process waiting on channel:%d\n", myproc->chan);
      printf(1, "Process killed:%d\n", myproc->killed);
      printf(1, "\n");
    }
  }
  exit();
}
