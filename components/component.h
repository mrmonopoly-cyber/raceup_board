#ifndef __RACEUP_BOARD_COMPONENT__
#define __RACEUP_BOARD_COMPONENT__ 

#include <stdint.h>

enum COMPONENT_INDEX {
};


typedef union RaceupBoardComponent {
}RaceupBoardComponent;

int8_t init_new_component(RaceupBoardComponent* comp, enum COMPONENT_INDEX comp_index);

#endif // !__RACEUP_BOARD_COMPONENT__
