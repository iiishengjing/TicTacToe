#pragma once
#include <vector>

enum class GameState {
    PLAYING,
    PLAYER1_WIN,
    PLAYER2_WIN,
    DRAW
};

class GameModel {
private:
    std::vector<std::vector<char>> board;
    int currentPlayer;  // 1 or 2
    int moveCount;
    GameState state;

    bool checkWin(int row, int col, char symbol);
    bool isBoardFull();

public:
    GameModel();
    void reset();
    bool makeMove(int row, int col);
    char getCell(int row, int col) const;
    int getCurrentPlayer() const;
    GameState getState() const;
    bool isValidMove(int row, int col) const;
};