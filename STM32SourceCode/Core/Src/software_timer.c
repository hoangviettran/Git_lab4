/*
 * software_timer.c
 *
 *  Created on: Oct 11, 2022
 *      Author: tran
 */
#include "main.h"

int timer0_counter_1 = 0;
int timer0_flag = 0;
int timer1_counter_1 = 0;
int timer1_flag = 0;
int TIMER_CYCLE = 10;
void setTimer0(int duration){
	timer0_counter_1 = duration/ TIMER_CYCLE;
	timer0_flag = 0;
}
void setTimer1(int duration){
	timer1_counter_1 = duration/ TIMER_CYCLE;
	timer1_flag = 0;
}

void timer_run(){
	if(timer0_counter_1 > 0){
		timer0_counter_1--;
		if(timer0_counter_1 == 0) timer0_flag = 1;
	}
	if(timer1_counter_1 > 0){
		timer1_counter_1--;
		if(timer1_counter_1 == 0) timer1_flag = 1;
	}
}

