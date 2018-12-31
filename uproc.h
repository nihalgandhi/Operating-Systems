
struct uproc{
  char name[16]; //Process Name
  int pid; //Process ID
  int parentid; //Parent Process ID
  int size; //Size of Process Memory
  char state[16]; //Process State
  int chan; //Process Waiting on a Channel
  int killed; //Process killed or not
};

