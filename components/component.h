#ifndef __RACEUP_BOARD_COMPONENT__
#define __RACEUP_BOARD_COMPONENT__ 

#include <stdint.h>

#ifdef MAX_SERIALS
#include "./serial/serial.h"
#endif //!MAX_SERIALS 
#ifdef MAX_GPIOS
#include "./gpio/gpio.h"
#endif //!MAX_GPIOS 
#ifdef MAX_CANS
#include "./can/can.h"
#endif //!MAX_CANS 
#ifdef MAX_TIMERS 
#include "./timer/timer.h"
#endif //!MAX_TIMERS
#endif // !__RACEUP_BOARD_COMPONENT__
