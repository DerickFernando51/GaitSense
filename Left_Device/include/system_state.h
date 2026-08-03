#pragma once

enum class SystemState
{
    INIT,
    IDLE,
    STREAMING,
    ERROR
};

void state_set(SystemState state);

SystemState state_get();