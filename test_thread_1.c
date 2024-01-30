#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#define SLEEP_TIME 100


void f1(void* arg1, void* arg2) {
  int num = *(int*)arg1;
  for (int i = 0 ; i<40 ; i++)
  {
    printf(1,"f1 100 ms %d\n", num);
    sleep(100);
  }
  exit();
}

void f2(void* arg1, void* arg2) {
   int num = *(int*)arg2;
  for (int i = 0 ; i<20 ; i++)
  {
    printf(1,"f2 200 ms %d\n", num);
    sleep(200);
  }
  exit();
}

int
main(int argc, char *argv[])
{
  int arg1 = 1, arg2 = 2;

  printf(1, "below should be sequential print statements:\n");
  thread_create(&f1, (void *)&arg1, (void *)&arg2);
  thread_create(&f2, (void *)&arg1, (void *)&arg2);
  thread_join();
  thread_join();
  printf(1,"end\n");
  exit();
}