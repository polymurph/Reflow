#ifndef DISPLAY_H
#define DISPLAY_H

#ifdef __cplusplus
extern "C" {
#endif

#include "usart.h"
#include "reflow_oven_bsl.h"

uint8_t display_init(reflowBSL_t *oven_bsl);

#ifdef __cplusplus
}
#endif

#endif /* DISPLAY_H */
