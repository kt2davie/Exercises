/*
 * Conways Game Of Life - Simple Solution
 * Board Class Declaration
 * Author: Keefer Davies
 */

#pragma once

#include "Board.h"
#include <vector>
#include <cstdint>

class Board
{
public:
    using Grid = std::vector<bool>;

public:
    Board() = default;
    Board(const Board& other) = delete;
    Board(const int32_t numRows, const int32_t numCols);
    Board(const Grid& grid, const int32_t numRows, const int32_t numCols);
    ~Board() = default;

public:
    void print() const;
    void randomize(int32_t seed);
    const int32_t getNumRows() const;
    const int32_t getNumCols() const;
    const bool getCellValue(const int32_t row, const int32_t col) const;
    void setCellValue(const int32_t row, const int32_t col, const bool value);

private:
    Grid m_grid;
    int32_t m_numRows;
    int32_t m_numCols;
};
