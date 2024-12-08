#ifdef MAX_DUMMY

#include <stdint.h>

typedef struct component_dummy{
    uint16_t id;
}component_dummy;

extern int8_t hardware_init_dummy(const uint16_t id);
int8_t init_new_dummy_component(component_dummy* const restrict comp, const uint16_t id)
{
    comp->id = id;
    return hardware_init_dummy(id);
}

#endif //!MAX_DUMMY 
