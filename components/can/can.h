#ifdef MAX_CANS

#include <stdint.h>

typedef struct component_can{
    uint16_t id;
}component_can;

extern int8_t hardware_init_can(const uint16_t id);
int8_t init_new_can_component(component_can* const restrict comp, const uint16_t id)
{
    comp->id = id;
    return hardware_init_can(id);
}

#endif //!MAX_CANS 
