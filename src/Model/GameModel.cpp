#include "GameModel.h"

GameModel::GameModel() {
    reset();
}

void GameModel::reset() {
    board = std::vector<std::vector<char>>(3, std::vector<char>(3, ' '));
    currentPlayer = 1;
    moveCount = 0;
    state = GameState::PLAYING;
}

bool GameModel::isValidMove(int row, int col) const {
    return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
}

bool GameModel::checkWin(int row, int col, char symbol) {
    // 检查行
    if (board[row][0] == symbol && board[row][1] == symbol && board[row][2] == symbol) return true;
    // 检查列
    if (board[0][col] == symbol && board[1][col] == symbol && board[2][col] == symbol) return true;
    // 检查主对角线
    if (row == col && board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) return true;
    // 检查副对角线
    if (row + col == 2 && board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) return true;
    return false;
}

bool GameModel::isBoardFull() {
    return moveCount >= 9;
}

bool GameModel::makeMove(int row, int col) {
    if (!isValidMove(row, col) || state != GameState::PLAYING) return false;

    char symbol = (currentPlayer == 1) ? 'X' : 'O';
    board[row][col] = symbol;
    moveCount++;

    if (checkWin(row, col, symbol)) {
        state = (currentPlayer == 1) ? GameState::PLAYER1_WIN : GameState::PLAYER2_WIN;
    }
    else if (isBoardFull()) {
        state = GameState::DRAW;
    }
    else {
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }
    return true;
}

char GameModel::getCell(int row, int col) const {
    return board[row][col];
}

int GameModel::getCurrentPlayer() const {
    return currentPlayer;
}

GameState GameModel::getState() const {
    return state;
}
