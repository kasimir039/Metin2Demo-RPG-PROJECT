#pragma once
#include "Types.h"
#include <iostream>

class Player {
public:
    virtual void DisplayCharacter() noexcept = 0;
    virtual ~Player() = default;
};

