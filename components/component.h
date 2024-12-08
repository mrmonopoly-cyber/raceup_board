#ifndef __RACEUP_BOARD_COMPONENT__
#define __RACEUP_BOARD_COMPONENT__ 

#include <stdint.h>

#include "./gpio/gpio.h"
enum COMPONENT_INDEX {
	GPIO,
};


typedef struct RaceupBoardComponent {
    enum COMPONENT_INDEX comp_type;
    union{
component_gpio gpio;
    }comps;
}RaceupBoardComponent;

int8_t init_new_component(RaceupBoardComponent* comp, enum COMPONENT_INDEX comp_index);

#endif // !__RACEUP_BOARD_COMPONENT__
