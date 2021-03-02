/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <cstdio>


// Blinking rate in milliseconds
#define BLINKING_RATE     500ms

InterruptIn button (USER_BUTTON);
DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
Ticker time_up1;
Ticker time_up2;
Ticker time_up3;

bool flag;

void b_led1(){
    led1 = !led1;
}

void b_led2(){
    led2 = !led2;
}

void b_led3(){
    led3 = !led3;
}

void stop_1(){
    time_up1.detach();
    time_up2.detach();
    time_up3.detach();
}

void start_1(){
    time_up1.attach(&b_led1, 450ms);
    time_up2.attach(&b_led2, 100ms);
    time_up3.attach(&b_led3, 1000ms);
}

int main()
{
    button.rise(stop_1);
    button.fall(start_1);
    led1 = 0;
    led2 = 0;
    time_up1.attach(&b_led1, 450ms);
    time_up2.attach(&b_led2, 100ms);
    time_up3.attach(&b_led3, 1000ms);
    while (true) {
    }
}
