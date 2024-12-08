#ifndef __GPIO_COMPONENT__
#define __GPIO_COMPONENT__

#include <stdint.h>

typedef struct component_gpio{
    uint16_t id;
}component_gpio;

int8_t init_new_gpio_component(component_gpio* comp);

extern int8_t gpio_toggle(component_gpio* comp);
extern int8_t gpio_set_pin(component_gpio* comp, uint16_t id);
extern int8_t gpio_read_state(component_gpio* comp);
extern int8_t gpio_set_high(component_gpio* comp);
extern int8_t gpio_set_low(component_gpio* comp);

#endif // !__GPIO_COMPONENT__

