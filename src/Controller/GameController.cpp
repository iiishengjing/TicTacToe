#include "GameController.h"
#include "HumanPlayer.cpp"  // 临时方式，实际项目应使用头文件
#include <iostream>

GameController::GameController() {
    player1 = std::make_unique<HumanPlayer>();
    player2 = std::make_unique<HumanPlayer>();
    isRunning = true;
}

void GameController::run() {
    view.displayWelcome();
    while (isRunning) {
        resetGame();
        gameLoop();

        std::cout << "\n按 'q' 退出，按任意键重新开始: ";
        char choice;
        std::cin >> choice;
        if (choice == 'q' || choice == 'Q') {
            isRunning = false;
        }
    }
    view.displayMessage("感谢游玩！再见！");
}

void GameController::resetGame() {
    model.reset();
}

void GameController::gameLoop() {
    while (!isGameOver()) {
        view.displayBoard(model);
        view.displayGameState(model);

        int row, col;
        bool validMove = false;
        while (!validMove) {
            if (model.getCurrentPlayer() == 1) {
                validMove = player1->getMove(model, row, col);
            }
            else {
                validMove = player2->getMove(model, row, col);
            }
            if (!validMove) {
                view.displayMessage("无效输入！请输入1-3之间的数字，且位置为空。");
            }
        }
        model.makeMove(row, col);
    }
    view.displayBoard(model);
    view.displayGameState(model);
}

bool GameController::isGameOver() {
    GameState state = model.getState();
    return state != GameState::PLAYING;
}