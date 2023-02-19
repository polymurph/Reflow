#ifndef USER_IO_H
#define USER_IO_H
#include "usart.h"
#include "reflow_oven_bsl.h"

#ifdef __cplusplus
extern "C" {
#endif

uint8_t userIO_init(reflowBSL_t *oven_bsl);

void userIO_doInitStatusBlinki();

#ifdef __cplusplus
}
#endif

#endif /* USER_IO_H */
