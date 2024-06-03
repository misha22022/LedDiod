#include "diod.h"
#include <iostream>

int main() {
    LedDiod led;
    led.setColor("green");
    led.setBrightness(30);
    led.showColor();
    led.showBrightness();

    return 0;
}
