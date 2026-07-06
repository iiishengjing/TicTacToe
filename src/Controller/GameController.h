#pragma once
#include "src/Model/GameModel.h"
#include "src/View/GameView.h"
#include "Player.h"
#include <memory>

class GameController {
private:
    GameModel model;
    GameView view;
    std::unique_ptr<Player> player1;
    std::unique_ptr<Player> player2;
    bool isRunning;

    void gameLoop();
    bool isGameOver();

public:
    GameController();
    void run();
    void resetGame();
};