#pragma once
#include "../Model/GameModel.h"
#include <string>

class GameView {
public:
    void displayBoard(const GameModel& model);
    void displayMessage(const std::string& msg);
    void displayGameState(const GameModel& model);
    void displayWelcome();
    void displayHelp();
};