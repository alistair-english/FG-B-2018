#include <Common.h>
#include <Structs.h>
#include <SPIWrapper.h>
#include <MotorArray.h>
#include <Common.h>
#include <Orbit.h>
#include <IMU.h>
#include <RotationWrapper.h>
#include <BallManager.h>
#include <CameraWrapper.h>
#include <DirectionController.h>
#include <Light.h>
#include <ModeWrapper.h>
#include <MotorMusic.h>
#include <Xbee.h>


/* NOTE Constructors are called in the .cpp file for each class */
RotationWrapper rotation = RotationWrapper();

void setup(){

    /* Begin Serial */
    #if DEBUG
        Serial.begin(9600);
    #endif

    /* Init SPI */
    spi.initSPI();
    /* Init IMU */
    imu.init();
    /* Calibrate IMU for drift etc. */
    imu.calibrate();
    /* Init Lightsensors */
    light.init();
    /* Init Serial */
    cam.initSerial();

    /* Set robot mode based on default mode */
    robotMode.setDefault(defender);
    #if ROBOT
        // O_bot
        robotMode.setMode(attacker);
    #endif

    // Dribbler Stuff - TODO
    // pinMode(13, OUTPUT);
    // digitalWrite(13, HIGH);
    // delay(500);
    // digitalWrite(13, LOW);
    // delay(300);
    // kicker.controlBall(0, 100);
    // delay(200);

    if(robotMode.getMode() == defender){
        // get ir data for goalie back dist
        spi.getIRData();
        while(spi.lidars.backDist == 0 || spi.lidars.backDist == 0){
            spi.getIRData();
        }
        dc.setGoalieDistance(GOALIE_DEFAULT_DIST);
    } else {
        dc.setGoalieDistance(GOALIE_DEFAULT_DIST);
    }
}

void loop(){

    /* Get OpenMV7 Data */
    cam.getCamData(ATTACK_YELLOW);

    /* Get IR Data from ATMega */
    spi.getIRData();

    /* Update IMU */
    imu.update();

    /* Update Light */
    light.readLight();
    light.updateAngle();

    /* Send and recieve Xbee Data */
    xbee.update(dc.getXbeeData());
    #if !SUPERTEAM
        if(xbee.isConnected()){
            #if ROBOT
                robotMode.setMode(attacker);
            #endif
        } else {
            robotMode._default();
        }
    #endif
    // robotMode.setMode(attacker);

    /* Update Game Data */
    dc.updateData(cam.data, spi.lidars, light.data, xbee.otherData, imu.getHeading(), robotMode.getMode());

    // kicker.kickBall();
    // motors.speed(0);
    motors.move(dc.calculate());
    /* Test Kicker */
    // Serial.println(millis()/100);
    // analogWriteFrequency(2, millis()/100);
    // analogWriteFrequency(3, millis()/100);
    // analogWriteFrequency(4, millis()/100);
    // analogWriteFrequency(5, millis()/100);

    // kicker.kickBall();

    // moveControl ctrl = dc.calculate(attacker);
    // Serial.println(spi.lidars.backDist);

    // Serial.print(ctrl.direction); Serial.print(" "); Serial.print(ctrl.speed); Serial.print(" "); Serial.println(ctrl.rotation);
    // Serial.println(imu.getHeading());
}
