#ifndef __RACEUP_BOARD__
#define __RACEUP_BOARD__

#include <stdint.h>

#include "./components/component.h"

int raceup_board_init(void);
int raceup_board_add_component(const RaceupBoardComponent* component);
int raceup_board_main(int argc, char* argv[]);

#endif // !__RACEUP_BOARD__
