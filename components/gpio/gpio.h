#ifdef MAX_GPIOS

#include <stdint.h>

typedef struct component_gpio{
    uint16_t id;
}component_gpio;


extern int8_t hardware_init_gpio(const uint16_t id);
int8_t init_new_gpio_component(component_gpio* restrict comp,const uint16_t id)
{
    comp->id = id;
    return hardware_init_gpio(id);
}

extern int8_t gpio_set_pin_mode(const component_gpio* const restrict  comp,uint8_t mode);
extern int8_t gpio_toggle(const component_gpio* const restrict  comp);
extern int8_t gpio_read_state(const component_gpio* const restrict comp);
extern int8_t gpio_set_high(const component_gpio* const restrict comp);
extern int8_t gpio_set_low(const component_gpio* const restrict comp);

#endif //!MAX_GPIOS 
