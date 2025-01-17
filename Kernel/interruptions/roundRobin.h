#ifndef _ROUNDROBIN_H_
#define _ROUNROBIN_H_



#include <stdint.h>
#include "../include/video.h"

#define WORSTPRIORITY 40
#define MAXBLOCKTYPES 100
#define MAX_PFD 40
#define _ARGUMENTS  int argc,char **argv

typedef struct processControlBlock {
    int8_t pid;
    int parentPid;
    int quantityWaiting;
    uint64_t taskRSP;
    uint64_t functionAddress;
    uint64_t baseRSP; 
    char priority; // between 0 and WORSTPRIORITY. 0 = HIGHPRIORITY 
    char currentPushes; 
    prompt_info prompt;
    struct processControlBlock * tail; 
    char * name;
    int processFileDescriptors[MAX_PFD];
} processControlBlock;

typedef struct processDescriptor{
    char * name ;
    uint8_t pid;
    uint8_t priority;
    uint8_t foreground;
    int stackPointer;
    int basePointer;
} processDescriptor;

void addProcess(processControlBlock * process);

//void removeProcess(uint64_t pid);

void nextTask();

processControlBlock * getCurrentTask();

void setCurrentRSP(uint64_t rsp);

uint64_t getCurrentRSP();

prompt_info * getCurrentPrompt();

int getCurrentPid();

int changeNicenessBy(uint64_t pid, uint64_t deltaNice); 

int killProcess(int pid);

int blockProcess(int pid, int password);

int blockMyself(int password);

int unblockProcess(int pid, int password);

int renounce(void); 

int popAndUnblock(int password);

int * getBlockedBy(int password , int maxQ);

void printBlockedBy(int password);

int getBlockedPidsByPass(int password, int* pidsBuf);

int getAvailablePassword();

void setPrompt(prompt_info shellPrompt , prompt_info backgroundPrompt);

#endif
