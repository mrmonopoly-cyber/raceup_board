#ifndef __VIRTUA__SERIAL__
#define __VIRTUA__SERIAL__

#include <stdint.h>
struct component_serial{
    uint16_t id;
};
#ifdef MAX_SERIALS

typedef struct component_serial component_serial;

extern int8_t hardware_init_serial(const uint16_t id);
int8_t init_new_serial_component(component_serial* const restrict comp, const uint16_t id)
{
    comp->id = id;
    return hardware_init_serial(id);
}
extern int8_t serial_setup(const component_serial* const restrict self, const uint32_t freq);
extern int8_t serial_read(const component_serial* const restrict self, uint8_t* restrict const o_buffer,
        const uint32_t buffer_size);
extern int8_t serial_write(const component_serial* const restrict self, uint8_t* const restrict o_buffer,
       const uint32_t buffer_size);

#endif //!MAX_SERIALS 
#endif // !__VIRTUA__SERIAL__
