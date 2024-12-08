#ifndef __RACEUP_BOARD_COMPONENT__
#define __RACEUP_BOARD_COMPONENT__ 

#include "./gpio/gpio.h"
#include "./can/can.h"
#include "./serial/serial.h"
#include "./analog_pin/analog_pin.h"
#include "./digital_pin/digital_pin.h"
typedef union RaceupBoardComponent {
component_gpio gpio;
component_can can;
component_serial serial;
component_analog_pin analog_pin;
component_digital_pin digital_pin;
}RaceupBoardComponent;

#endif // !__RACEUP_BOARD_COMPONENT__
