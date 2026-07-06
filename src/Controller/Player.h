#pragma once
#include "src/Model/GameModel.h"

class Player {
public:
    virtual ~Player() = default;
    virtual bool getMove(GameModel& model, int& row, int& col) = 0;
    virtual std::string getName() const = 0;
};