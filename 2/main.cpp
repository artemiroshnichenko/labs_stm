#include "mbed.h"

InterruptIn button(USER_BUTTON);
InterruptIn button2(PA_0);


DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);

int i = 0;                    
 
void countt(){                       
    i++;                      
}

void neg(){
    i--;
}
 
int main() {
    button.rise(countt);
    button2.rise(neg);

    while(true){
        switch (i){
            case -1:
                led1 = 0;
                led2 = 0;
                led3 = 1;
                i = 3;
                break;
            case 1:
                led1 = 1;
                led2 = 0;
                led3 = 0;
                break;
            case 2:
                led1 = 0;
                led2 = 1;
                led3 = 0;
                break;
            case 3:
                led1 = 0;
                led2 = 0;
                led3 = 1;
                break;
            case 4:
                led1 = 1;
                led2 = 0;
                led3 = 0;
                i = 0;
                break;
        }
        ThisThread::sleep_for(20ms);
    }
}