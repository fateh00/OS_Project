#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#define THREAD_COUNT 10
lock_t* lk;

void f1(void* arg1, void* arg2) {
    lock_acquire(lk);
    printf(1,"f1\n");
    printf(1,"end f1\n");
    lock_release(lk);
  exit();
}

void f2(void* arg1, void* arg2) {
    lock_acquire(lk);
    printf(1,"f2\n");
    printf(1,"end f2\n");
    lock_release(lk);
  exit();
}

void f3(void* arg1, void* arg2) {
    printf(1,"f3\n");
    sleep(100);
    printf(1,"end f3\n");
  exit();
}
void f4(void* arg1, void* arg2) {
    printf(1,"f4\n");
    sleep(100);
    printf(1,"end f4\n");
  exit();
}

int
main(int argc, char *argv[])
{
  lock_init(lk);
  int arg1 = 1, arg2 = 2;
  for (int i = 0 ;i<THREAD_COUNT;i++)
  {
    if (i%2 == 0)
    {
        thread_create(&f3, (void *)&arg1, (void *)&arg2);
    }
    else
    {
        thread_create(&f4, (void *)&arg1, (void *)&arg2);
    }
  }
  for (int i = 0 ;i<THREAD_COUNT; i++)
  {
    thread_join();
  }
  printf(1,"---------------------------\n");
  sleep(500);
  for (int i = 0 ;i<THREAD_COUNT;i++)
  {
    if (i%2 == 0)
    {
        thread_create(&f1, (void *)&arg1, (void *)&arg2);
    }
    else
    {
        thread_create(&f2, (void *)&arg1, (void *)&arg2);
    }
  }
  for (int i = 0 ;i<THREAD_COUNT; i++)
  {
    thread_join();
  }
  printf(1,"end\n");
  exit();
}