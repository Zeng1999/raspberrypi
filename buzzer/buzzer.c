// gcc -Wall buzzer.c -lwiringPi -lpthread -o test && ./test
#include <stdio.h>
#include "./softPwm.h"
#include "../wiringPi.h"

#define pin 23

void write(int data, int time); 

int main() {
    if (wiringPiSetup() != 0) {
        printf("Error In wiringPiSetup !\n");
        return -1;
    }

    if (softPwmCreate(pin, 0, 100) != 0) {
        printf("Error In softPwmCreate !\n");
        return -1;
    }

    for(int i = 0; i < 10; i++) {
        write(i*10, 1000);
    }

    return 0;
}

void write(int data, int time) {
    softPwmWrite(pin, data);
    delay(time);

    softPwmWrite(pin, LOW);
    delay(time / 10);
}
