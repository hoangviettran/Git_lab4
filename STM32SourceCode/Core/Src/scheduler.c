/*
 * scheduler.c
 *
 *  Created on: Nov 24, 2022
 *      Author: tran
 */

#include "scheduler.h"


#define TIME_CYCLER    10

sTasks SCH_tasks_G[SCH_MAX_TASKS];
uint8_t current_index_task = 0;


void SCH_Init(void){

}
void SCH_Add_Task ( void (*pFunction)(),
		            uint32_t DELAY,
					uint32_t PERIOD){
	if(current_index_task < SCH_MAX_TASKS){

		SCH_tasks_G[current_index_task].pTask = pFunction;
		SCH_tasks_G[current_index_task].Delay = DELAY/TIME_CYCLER;
		SCH_tasks_G[current_index_task].Period = PERIOD/TIME_CYCLER;
		SCH_tasks_G[current_index_task].RunMe = 0;

		SCH_tasks_G[current_index_task].TaskID = current_index_task;

		current_index_task++;
	}
};

void SCH_Update(void){
	for(int i = 0; i < current_index_task; i++){
		if(SCH_tasks_G[i].Delay > 0){
			SCH_tasks_G[i].Delay--;
		}else{
			SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
			SCH_tasks_G[i].RunMe += 1;
		}
	}
}

void SCH_Dispatch_Tasks(void){
	for(int i = 0; i < current_index_task; i++){
		if(SCH_tasks_G[i].RunMe > 0){
			SCH_tasks_G[i].RunMe--;
			(*SCH_tasks_G[i].pTask)();
			if(SCH_tasks_G[i].Period == 0) SCH_Delete(i);
		}
	}
}

void SCH_Delete(uint32_t ID){
	if(ID > current_index_task) return;
	for(int i = ID; i < current_index_task-1; i++){
		SCH_tasks_G[i].pTask = SCH_tasks_G[i+1].pTask;
	    SCH_tasks_G[i].Delay = SCH_tasks_G[i+1].Delay;
		SCH_tasks_G[i].Period = SCH_tasks_G[i+1].Period;
		SCH_tasks_G[i].RunMe = SCH_tasks_G[i+1].RunMe;
	}
	SCH_tasks_G[current_index_task-1].pTask = 0x0000;
	SCH_tasks_G[current_index_task-1].Delay = 0;
	SCH_tasks_G[current_index_task-1].Period = 0;
	SCH_tasks_G[current_index_task-1].RunMe = 0;
	current_index_task--;
};
