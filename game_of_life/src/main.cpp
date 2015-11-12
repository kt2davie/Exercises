/*
 * Conways Game Of Life - Simple Solution
 * Application Entrypoint
 * Author: Keefer Davies
 */

#include "Board.h"
#include "GameOfLife.h"
#include <chrono>
#include <thread>
#include <cstdlib>

int main(int argc, char** argv)
{
    //Random Board
    Board board(40, 40);
    auto duration = std::chrono::system_clock::now().time_since_epoch();
    auto seed = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    board.randomize(seed);

    //Beacon (period 2)
    //Board board({1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1}, 4, 4);

    GameOfLife gameOfLife(std::move(board));
    for(;;)
    {
        system("clear");
        gameOfLife.update();
        gameOfLife.draw();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    return 0;
}
