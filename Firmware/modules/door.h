#ifndef DOOR_H
#define DOOR_H

#include "usart.h"
#include "reflow_oven_bsl.h"

#ifdef __cplusplus
extern "C" {
#endif

uint8_t door_init(reflowBSL_t *oven_bsl);


/**
 * @brief Returns 1 if the door is open and 0 when not
 * 
 * @return uint8_t 
 */
uint8_t door_open();

#ifdef __cplusplus
}
#endif

#endif /* DOOR_H */
