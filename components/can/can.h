#ifndef __VIRTUAL_CAN__
#define __VIRTUAL_CAN__

#include <stdint.h>

struct component_can{
    uint16_t id;
};

#endif // !__VIRTUAL_CAN__
#ifdef MAX_CANS

typedef struct component_can component_can;

extern int8_t hardware_init_can(const uint16_t id);
int8_t init_new_can_component(component_can* const restrict comp, const uint16_t id)
{
    comp->id = id;
    return hardware_init_can(id);
}

#endif //!MAX_CANS 
