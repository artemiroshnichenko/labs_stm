#include "mbed.h"
#include<string>  


using namespace std;  

static BufferedSerial pc(USBTX, USBRX);
InterruptIn button (USER_BUTTON);
PwmOut led(LED1);
int i = 0;

void un(){
    i = 0;
}

int main()
{
    button.fall(un);
    char *c = new char[1];
    string s;
    while (1) {
        
        i++;
        pc.read(c, sizeof(c));
        pc.write(c, sizeof(c));
        
        if (*c == 'u') {
            led = 1;
        }
        if (*c == 'd') {
            led = 0;
        }
        if (*c == 'h'){
            s = '\n' + to_string(i) + '\n';
            char const *pchar = s.c_str();
            led = 1;
            pc.write(pchar, sizeof(pchar));
        }
    }

}