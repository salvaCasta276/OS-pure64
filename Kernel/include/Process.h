#ifndef PROCESS_H
#define PROCESS_H

#include <roundRobin.h>
#include "../include/video.h"
#include "../include/memoryManager.h"



void firstProcess(uint64_t functionAddress, prompt_info prompt);

int createProcess(uint64_t functionAddress,_ARGUMENTS,int foreground);

int getProcessesData(uint64_t descriptorsArray);
 
int deleteProcess(int pid);

void exit();

void wait();


#endif