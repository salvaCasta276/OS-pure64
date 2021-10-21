#include <testSem.h>


uint64_t openSemAsm(char * sem_id , uint64_t initialValue );
uint64_t waitSemAsm(char * sem_id  );
uint64_t postSemAsm(char * sem_id );
uint64_t closeSemAsm(char * sem_id );

uint64_t openSemaphore(char * sem_id , uint64_t initialValue ){
    return openSemAsm(sem_id,initialValue);
}
uint64_t waitSemaphore(char * sem_id  ){
    return waitSemaphore(sem_id);
}
uint64_t postSemaphore(char * sem_id  ){
    return postSemaphore(sem_id);
}
uint64_t closeSemaphore(char * sem_id  ){
    return closeSemAsm(sem_id);
}