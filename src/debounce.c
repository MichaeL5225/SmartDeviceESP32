#include "debounce.h"

void debouncer_init(Debouncer* d, bool initial_state, uint32_t delay_ms)
{
    d->delay_ms = delay_ms;
    d->last_raw = initial_state;
    d->stable_status = initial_state;
    d->last_change_ms = 0;
}


bool debouncer_update(Debouncer* d, bool raw, uint32_t now_ms)
{
    if (raw != d->last_raw)
    {
        d->last_change_ms = now_ms;
        d->last_raw = raw;
    }

    if (now_ms - d->last_change_ms >= d->delay_ms)
    {
        d->stable_status = d->last_raw;
    }

    return d->stable_status;
}