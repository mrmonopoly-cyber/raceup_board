#ifndef __RACEUP_BOARD__
#define __RACEUP_BOARD__

#include <stdint.h>

#include "./components/component.h"

static struct{
#ifdef MAX_SERIALS
    component_serial serial[MAX_SERIALS];
#endif //!MAX_SERIALS 
#ifdef MAX_GPIOS
    component_gpio gpios[MAX_GPIOS];
#endif //!MAX_GPIOS 
#ifdef MAX_CANS
    component_can cans[MAX_CANS];
#endif //!MAX_CANS 
#ifdef MAX_TIMERS
    component_can cans[MAX_CANS];
#endif //!MAX_CANS 
}virtual_board;

#endif // !__RACEUP_BOARD__
