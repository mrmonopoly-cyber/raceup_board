#ifndef __DUMMY_COMPONENT__
#define __DUMMY_COMPONENT__

#include <stdint.h>

typedef struct component_dummy{
    uint16_t id;
}component_dummy;

int8_t init_new_dummy_component(component_dummy* comp);

#endif // !__DUMMY_COMPONENT__

