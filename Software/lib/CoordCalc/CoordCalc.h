#ifndef CoordCalc_h
#define CoordCalc_h

#include <Arduino.h>
#include <Common.h>
#include <Structs.h>

/* Structs */
struct absCamData {
    int ballAngle;
    int ballDist;
    int attackAngle;
    int attackDist;
    int defenceAngle;
    int defenceDist;
};

class CoordCalc{

public:
    CoordCalc();

    /* Functions */
    void updateData(cameraData cam, lidarData lidar, double compass);

    /* Variables */
    coordinate ball;
    coordinate robot;

private:

    /* Functions */
    int relToAbs(int relativeDirection);
    int absToRel(int absoluteDirection);

    lidarData adjustLidar(lidarData lidar);

    coordinate calculateCamCoords(absCamData cam);

    uint16_t relToAbsLidar(uint16_t value);

    /* Variables */
    double compass;
};
#endif
