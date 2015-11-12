/*
 * Conways Game Of Life - Simple Solution
 * GameOfLife Class Declaration
 * Author: Keefer Davies
 */

#pragma once

#include "Board.h"
#include <cstdint>

class GameOfLife
{
public:
    GameOfLife(const Board&& board);

public:
    void update();
    void draw() const;

private:
    uint32_t getLiveNeighbourCount(const int32_t row, const int32_t col) const;

private:
    Board m_board[2];
    bool m_currentBoard;
};
