#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#define THREAD_COUNT 1000
int counter = 0;

void increment(void* arg1, void* arg2) {
  counter++;
  exit();
}

void decrement(void* arg1, void* arg2) {
  counter--;
  exit();
}

int
main(int argc, char *argv[])
{
  int arg1 = 1, arg2 = 2;
  for (int i = 0 ;i<THREAD_COUNT;i++)
  {
    if (i%2 == 0)
    {
        thread_create(&increment, (void *)&arg1, (void *)&arg2);
    }
    else
    {
        thread_create(&decrement, (void *)&arg1, (void *)&arg2);
    }
  }
  for (int i = 0 ;i<THREAD_COUNT; i++)
  {
    thread_join();
  }
  printf(1,"Counter is %d \n",counter);
  printf(1,"end\n");
  exit();
}