#include "./component.h"

int8_t init_new_component(RaceupBoardComponent* comp, enum COMPONENT_INDEX comp_index)
{
    int8_t err =0;
    comp->comp_type = comp_index;
    switch (comp_index) {
case GPIO: return init_new_gpio_component(&comp->comps.gpio);
        default:
            goto comp_index_not_found;
    }

comp_index_not_found:
    err--;

    return err;
}
