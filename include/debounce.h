#pragma once
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"{
#endif

typedef struct {
    bool last_raw;
    bool stable_status;
    uint32_t last_change_ms;
    uint32_t delay_ms;
} Debouncer;

void debouncer_init(Debouncer* d, bool initial_state, uint32_t delay_ms);
bool debouncer_update(Debouncer* d, bool raw, uint32_t now_ms);

#ifdef __cplusplus
}
#endif