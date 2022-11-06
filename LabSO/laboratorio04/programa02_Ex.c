#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <semaphore.h>
#include <fcntl.h>

#define MAX_COUNT 500


void ChildProcess(sem_t*);
void ParentProcess(sem_t*);

void main(void)
{   
    sem_t *mutex = sem_open("mutex", O_CREAT|O_EXCL, O_WRONLY| O_CREAT| O_RDONLY| O_TRUNC, 1);    
    pid_t pid;

    pid = fork();
    if (pid == 0){
        ChildProcess(mutex);
    }else{
        ParentProcess(mutex);
    }

    sem_unlink("mutex");
    exit(0);
}

void ChildProcess(sem_t* mutex)
{   
    sem_wait(mutex);

    int i;
    for (i = 1; i <= MAX_COUNT; i++)
        printf(" Processo FILHO, valor = %d\n", i);
    printf(" *** Processo FILHO finalizado ***\n");

    sem_post(mutex);
}

void ParentProcess(sem_t* mutex)
{   
    sem_wait(mutex);

    int i;
    for (i = 1; i <= MAX_COUNT; i++)
        printf("Processo PAI, value = %d\n", i);
    printf("*** Processo PAI finalizado ***\n");

    sem_post(mutex);    
}