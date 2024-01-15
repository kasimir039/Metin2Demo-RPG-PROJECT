#pragma once
#include "Types.h"
#include <iostream>

class Player {
public:
    virtual const void DisplayCharacter() const noexcept = 0;
    virtual ~Player() {}
};

