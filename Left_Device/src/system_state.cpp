#include "system_state.h"

static SystemState currentState = SystemState::INIT;

void state_set(SystemState state)
{
    currentState = state;
}

SystemState state_get()
{
    return currentState;
}