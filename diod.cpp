#include "diod.h"
#include <iostream>
#include <cmath>
#include <algorithm> 

LedDiod::LedDiod() : brightness(0), color("red") {} 

void LedDiod::setColor(std::string color) {
    std::transform(color.begin(), color.end(), color.begin(), ::tolower); 
    if (color == "red" || color == "green" || color == "blue") {
        this->color = color;
    }
    else {
        this->color = "red"; 
    }
}

void LedDiod::setBrightness(int br) {
    if (br >= 0 && br <= 100) {
        this->brightness = br;
    }
    else {
        this->brightness = 0; 
    }
}

void LedDiod::showColor() const {
    std::cout << "led color is " << this->color << std::endl;
}

void LedDiod::showBrightness() const {
    std::cout << "led brightness is " << this->brightness << std::endl;
}

double LedDiod::calcDiodCurrent(double voltage) const {
    const double Is = 10e-6; 
    const double Vt = 0.026; 

    return Is * (exp(voltage / Vt) - 1);
}
