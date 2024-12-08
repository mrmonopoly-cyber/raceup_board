#ifndef __VIRTUAL_TIMER__
#define __VIRTUAL_TIMER__

#include <stdint.h>
struct component_timer{
    uint16_t id;
};

#ifdef MAX_TIMER

typedef struct component_timer component_timer;

extern int8_t hardware_init_timer(const uint16_t id);
extern int8_t wait_milliseconds(component_timer* const restrict comp, uint32_t time);
int8_t init_new_timer_component(component_timer* const restrict comp, const uint16_t id)
{
    comp->id = id;
    return hardware_init_timer(id);
}

#endif //!MAX_TIMER 
#endif // !__VIRTUAL_TIMER__
