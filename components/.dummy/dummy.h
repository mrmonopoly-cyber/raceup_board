#ifndef __VIRTUAL_DUMMY__
#define __VIRTUAL_DUMMY__

#include <stdint.h>
struct component_dummy{
    uint16_t id;
};

#ifdef MAX_DUMMY

typedef struct component_dummy component_dummy;

extern int8_t hardware_init_dummy(const uint16_t id);
int8_t init_new_dummy_component(component_dummy* const restrict comp, const uint16_t id)
{
    comp->id = id;
    return hardware_init_dummy(id);
}

#endif //!MAX_DUMMY 
#endif // !__VIRTUAL_DUMMY__
