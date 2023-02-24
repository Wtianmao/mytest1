#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/mman.h>
#include <iostream>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <errno.h>

static pthread_mutex_t *mptr; /* 互斥锁变量指针，互斥锁变量存放到共享内存 */

/**
* 多进程互斥锁变量初始化
*/
void my_lock_init(char *fg)
{
    bool needinit = false;
    int ret = mkdir("/tmp/test_shm/1", 0666);
    if (ret == 0)
    {
	needinit = true;
    }
    else if (errno != EEXIST)
    {
	printf("errno=%d\n", errno);
	exit(0);
    }
    int key = ftok("/tmp/test_shm", 0);

    int shm_id = shmget(key, sizeof(pthread_mutex_t), IPC_CREAT | 0666);
    if (fg[0] == '0')
    {
	shmctl(shm_id, IPC_RMID, NULL);
	rmdir("/tmp/test_shm");
	exit(0);
    }
    mptr = (pthread_mutex_t *)(shmat(shm_id, NULL, 0));

    if (needinit)
    {
	printf("init lock\n");
	pthread_mutexattr_t mattr;
    	pthread_mutexattr_init(&mattr);
    	pthread_mutexattr_setpshared(&mattr, PTHREAD_PROCESS_SHARED);
    	pthread_mutex_init(mptr, &mattr);
	pthread_mutexattr_destroy(&mattr);
    }

    printf("%d\n", key);
    printf("%d\n", shm_id);
    printf("%llu\n", (unsigned long long)mptr);
    printf("%llu\n", *mptr);

}

/**
* 加锁
*/
void
my_lock_wait()
{
  pthread_mutex_lock(mptr);
}

/**
* 解锁
*/
void 
my_lock_release()
{
    pthread_mutex_unlock(mptr);
}


int main(int argc, char **argv)
{
    my_lock_init(argv[1]);
    int i = 5;
    while(i--)
    {
	std::cout << "test add lock\n";
        my_lock_wait();
	std::cout << "add lock\n";
        sleep(5);
        my_lock_release();
	std::cout << "release lock\n";
	sleep(1);
    }

    return 0;
}
