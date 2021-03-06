#include <Common.h>

double strengthToDistance(double strength){
    double dv = 1.52;
    double dh = 1;
    double r = 6200;
    double h = 0;
    double v = 116;

    if(strength <= 78){
        return -dv*sqrt(r-dh*pow(strength-h, 2))+v;
    } else {
        return 65506;
    }

}


bool inBaseRange(double value, double base, double range){
    return value < (base + range) && value > (base - range);
}

bool inRange(double value, double min, double max){
    return value < max && value > min;
}

bool isFrontal(int angle){
    /* Is the given angle within a small rangle */
    if(angle <= 15 || angle >= 345){
        return true;
    }
    return false;
}

bool isFrontalLarge(int angle){
    /* Is the given angle within a large rangle */
    if(angle <= 60 || angle >= 300){
        return true;
    }
    return false;
}

bool isFrontalOrbit(int angle){
    if(angle <= 30 || angle >= 330){
        return true;
    }
    return false;
}

double doubleMod(double value, double maxVal){
    /* Modulus for doubles */
    return fmod((value + maxVal), maxVal);
}

void blink(){
    int led;
    long initTime;
    /* Blink the pin 13 LED */
    if(millis() > initTime + 1000 && DEBUG){
        if(led == 0){
            digitalWrite(LED_BUILTIN, HIGH);
            led = 1;
            initTime = millis();
        }else{
            digitalWrite(LED_BUILTIN, LOW);
            led = 0;
            initTime = millis();
        }
    }
}

bool lightGateTriggered(){
    /* Check if the lightgate is triggered */
    if(analogRead(LIGHTGATE_PIN) >= LIGHTGATE_THRESHOLD){
        return true;
    }
    return false;
}

double fromFront(double angle){
    /* Calulate and angle from the front of the robot based on a 0-360 angle */
    angle = angle == 0 ? 1 : angle;
    return angle < 180.0 ? (angle) : (360.0 - angle);
}

double calculateBallConfidence(double strength, double angle){
    /* Calculate ball confidence */
    double confidence = strength/MAX_STRENGTH * 1/fromFront(angle);
}

uint16_t sumArr(uint16_t arr[], int size){
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum += arr[i];
    }
    return (int)sum;
}

bool angleIsInside(double angleBoundCounterClockwise, double angleBoundClockwise, double angleCheck) {
    if (angleBoundCounterClockwise < angleBoundClockwise) {
        return (angleBoundCounterClockwise < angleCheck && angleCheck < angleBoundClockwise);
    } else {
        return (angleBoundCounterClockwise < angleCheck || angleCheck < angleBoundClockwise);
    }
}

double angleBetween(double angleCounterClockwise, double angleClockwise) {
    return mod(angleClockwise - angleCounterClockwise, 360);
}

double smallestAngleBetween(double angle1, double angle2) {
    double ang = angleBetween(angle1, angle2);
    return fmin(ang, 360 - ang);
}

double midAngleBetween(double angleCounterClockwise, double angleClockwise) {
    return mod(angleCounterClockwise + angleBetween(angleCounterClockwise, angleClockwise) / 2.0, 360);
}

int mod(int x, int m) {
    int r = x % m;
    return r < 0 ? r + m : r;
}
