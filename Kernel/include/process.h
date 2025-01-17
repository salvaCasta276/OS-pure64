#ifndef PROCESS_H
#define PROCESS_H

#include <roundRobin.h>
#include "../include/video.h"
#include "../include/memoryManager.h"



void firstProcess(uint64_t functionAddress, prompt_info shellPrompt, prompt_info backgroundPrompt);

int createProcess(uint64_t functionAddress,_ARGUMENTS,int foreground);

int getProcessesData(uint64_t descriptorsArray);

processControlBlock* getProcessByPid(int pid);

int getMinFdByPid(int pid);
 
int deleteProcess(int pid);

void exit();

void wait();


#endif