/*
 * software_timer.h
 *
 *  Created on: Oct 11, 2022
 *      Author: tran
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

void setTimer0(int duration);
void setTimer1(int duration);
void timer_run();
int timer0_flag;
int timer1_flag;
#endif /* INC_SOFTWARE_TIMER_H_ */
