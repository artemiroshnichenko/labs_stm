/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"


// Blinking rate in milliseconds
#define BLINKING_RATE     500ms

InterruptIn button (USER_BUTTON);

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
Ticker time_up1;
Ticker time_up2;
Ticker time_up3;


void b_led1(){
    led1 = !led1;
}

void b_led2(){
    led2 = !led2;
}

void b_led3(){
    led3 = !led3;
}

int main()
{
    led1 = 0;
    led2 = 0;
    time_up1.attach(&b_led1, 450ms);
    time_up2.attach(&b_led2, 100ms);
    time_up3.attach(&b_led3, 1000ms);
    while (true) {
        ThisThread::sleep_for(5ms);
    }
}
