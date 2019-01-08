// gcc -Wall rgb_led.c -lwiringpi -o test && ./test

#include <stdio.h>
#include "../wiringPi.h"

#define ERROR    -1
#define MAX      100
#define DURATION 100

#define redpin   23
#define greenpin 24
#define bluepin  25

int  setup();
void loop();

int main() {
    if(setup() != 0) {
        printf("Some Error In setup !\n");
        return -1;
    }

    loop();

    return 0;
}

int setup() {
    if(wiringPiSetup() != 0) {
        return ERROR;
    }

    pinMode(redpin, OUTPUT);
    pinMode(greenpin, OUTPUT);
    pinMode(bluepin, OUTPUT);

    return 0;
}

void loop() {
    for(int i = 0; i < MAX; i++) {
        digitalWrite(redpin, HIGH);
        delay(DURATION);

        digitalWrite(redpin, LOW);
        delay(DURATION);

        digitalWrite(greenpin, HIGH);
        delay(DURATION);

        digitalWrite(greenpin, LOW);
        delay(DURATION);

        digitalWrite(bluepin, HIGH);
        delay(DURATION);

        digitalWrite(bluepin, LOW);
        delay(DURATION);
    }
}
