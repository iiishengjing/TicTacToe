#include <iostream>
#include <limits>

class HumanPlayer : public Player {
public:
    bool getMove(GameModel& model, int& row, int& col) override {
        std::cout << "请输入行号和列号 (1-3): ";
        std::cin >> row >> col;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return false;
        }
        row--;
        col--;
        return model.isValidMove(row, col);
    }

    std::string getName() const override {
        return "人类玩家";
    }
};