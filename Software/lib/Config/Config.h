#define DEBUG true

#define ROBOT 1
#define ATTACK_YELLOW true
#define SUPERTEAM false

#define ALT_SCK 14
#define CAM_TRANSFER_NUM 12
#define LIDAR_SS 49
#define IR_TRANSFER_NUM 4

/* Speeds */
#define SPEED_VAL 85
#define FORWARD_SPEED 100

#define angToRad 0.01745329251
#define radToAng 57.2957795131

#define IMU_ADDRESS 0x68
#define MAG_ADDRESS 0x0C
#define GYRO_FULL_SCALE_2000_DPS 0x18
#define ACC_FULL_SCALE_2_G 0x00
#define IMU_CALIBRATION 500
#define IMU_CALIBRATION_NUM 500
#define IMU_MULTI 2.4
#define GOAL_CUTOFF 60
#define ROTATION_CUTOFF 150

#define BACKSPIN_PIN 6

#define MAX_STRENGTH 80 /* REVIEW */
#define LIGHTGATE_PIN 49
#define KICKER_PIN 28
#define LIGHTGATE_THRESHOLD 0
#define MIN_BALL_CONFIDENCE 0.5
#define BALL_CONFIDENCE 0.85

/* Dribbler & Kicker */
#define KICK_DIST 90
#define MIN_GOAL_ANGLE 90

/* Xbee */
#define XBEE_PACKAGE 8
#define XBEE_CONST 128
#define XBEE_START_BYTE 255

/* Orbit */
#define BIG_DISTANCE 0.00
#define MED_DISTANCE 0.00
#define SHORT_DISTANCE 0.00

/* Coord Calc */
#define ATTACK_GOAL_Y 90
#define ATTACK_GOAL_X 0
#define DEFENSE_GOAL_Y -90
#define DEFENSE_GOAL_X 0

#define TABLE_LEFT_X 91
#define TABLE_RIGHT_X -91
#define TABLE_FRONT_Y 121
#define TABLE_BACK_Y -121

#define LIDAR_MAX_SUM_HOR 100
#define LIDAR_MIN_SUM_HOR 80
#define LIDAR_MAX_SUM_VER 100
#define LIDAR_MIN_SUM_VER 80

#define LIDAR_CORRECT_ANGLE 15 // angle from horizontal

/* lidar Corrections */
#define LIDAR_CORRECT_LEFT 5
#define LIDAR_CORRECT_RIGHT 5
#define LIDAR_CORRECT_FRONT 5
#define LIDAR_CORRECT_BACK 6
#define LIDAR_CAM_RANGE 10

/* Light Tracker */
#define SPEED_ON_LINE 0
#define SPEED_SLIDE 60
#define SPEED_OVER_LINE 60
#define SLIDE_ANGLE 80
#define ANGLE_CUTOFF 75
#define STOP_BOUND 150

/* Direction Controller */
#define DISTANCE_CUTOFF_GOALIE 0
#define DISTANCE_CUTOFF_ATTACK 10
#define DISTANCE_CUTOFF 0
#define CUTOFF_SPEED_SCALE 1
#define COORD_SPEED_SCALE 2.5
#define SPIRAL_RATE 1
#define SPIRAL_DIRECION_RATE 0.2
#define SPIRAL_SPEED 60
#define SPIRAL_RESET 0.1
#define SPIRAL_CONST 1000
#define SPIRAL_COORD_DIST 10
#define ENABLE_TARGET_SPIRAL true
#define GOALIE_Y -65
#define GOALIE_X_RANGE 15
#define TARGET_X 0
#define TARGET_Y 0
#define GOALIE_DISTANCE 50

/* Light */
#define AUTO_LIGHT true
#define LIGHT_CALB_LOOPS 1000
#define THRESHOLD_OFFSET 10

#define LIGHTSENSOR_NUM 20
#define maxNumClusters 20
#define LIGHT_1 A1
#define LIGHT_2 A2
#define LIGHT_3 A3
#define LIGHT_4 A6
#define LIGHT_5 A7
#define LIGHT_6 A8
#define LIGHT_7 A9
#define LIGHT_8 A10
#define LIGHT_9 A11
#define LIGHT_10 A12
#define LIGHT_11 A13
#define LIGHT_12 A14
#define LIGHT_13 A15
#define LIGHT_14 A16
#define LIGHT_15 A17
#define LIGHT_16 A18
#define LIGHT_17 A19
#define LIGHT_18 A20
#define LIGHT_19 A21
#define LIGHT_20 A22
#define NUM_COUNTBACK 2
