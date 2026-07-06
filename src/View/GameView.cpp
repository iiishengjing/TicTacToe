#include "GameView.h"
#include <iostream>

void GameView::displayWelcome() {
    std::cout << "========================================" << std::endl;
    std::cout << "     欢迎来到 井字棋 (Tic-Tac-Toe)      " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "玩家1: X  玩家2: O" << std::endl;
    std::cout << "输入格式: 行号 列号 (1-3)" << std::endl;
    std::cout << "示例: 输入 '1 2' 表示第1行第2列" << std::endl;
    std::cout << "========================================" << std::endl;
}

void GameView::displayHelp() {
    std::cout << "坐标说明: 行号(1-3) 列号(1-3)" << std::endl;
    std::cout << "   (1,1) (1,2) (1,3)" << std::endl;
    std::cout << "   (2,1) (2,2) (2,3)" << std::endl;
    std::cout << "   (3,1) (3,2) (3,3)" << std::endl;
}

void GameView::displayBoard(const GameModel& model) {
    std::cout << "\n  1   2   3" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << i + 1 << " ";
        for (int j = 0; j < 3; j++) {
            char cell = model.getCell(i, j);
            std::cout << (cell == ' ' ? '.' : cell);
            if (j < 2) std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < 2) std::cout << "  ---------" << std::endl;
    }
    std::cout << std::endl;
}

void GameView::displayMessage(const std::string& msg) {
    std::cout << msg << std::endl;
}

void GameView::displayGameState(const GameModel& model) {
    GameState state = model.getState();
    switch (state) {
    case GameState::PLAYING:
        std::cout << "当前回合: 玩家" << model.getCurrentPlayer()
            << " (" << (model.getCurrentPlayer() == 1 ? 'X' : 'O') << ")" << std::endl;
        break;
    case GameState::PLAYER1_WIN:
        std::cout << "?? 恭喜！玩家1 (X) 获胜！" << std::endl;
        break;
    case GameState::PLAYER2_WIN:
        std::cout << "?? 恭喜！玩家2 (O) 获胜！" << std::endl;
        break;
    case GameState::DRAW:
        std::cout << "?? 平局！棋盘已满！" << std::endl;
        break;
    }
}
