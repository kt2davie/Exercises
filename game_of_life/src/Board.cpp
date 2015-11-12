/*
 * Conways Game Of Life - Simple Solution
 * Board Class Definition
 * Author: Keefer Davies
 */

#include "Board.h"
#include <random>
#include <sstream>
#include <iostream>

Board::Board(const int numRows, const int numCols) :
    m_numRows(numRows),
    m_numCols(numCols)
{
    m_grid.resize(numRows*numCols);
}

Board::Board(const Grid& grid, const int numRows, const int numCols) :
    m_grid(std::move(grid)),
    m_numRows(numRows),
    m_numCols(numCols)
{
}

void Board::print() const
{
    std::stringstream ss;
    int32_t numCells = static_cast<int32_t>(m_grid.size());
    for(int i = 0; i < numCells; ++i)
    {
        if (m_grid[i])
        {
            ss <<  " \u25A0 ";
        }
        else
        {
            ss << "   ";
        }
        if ((i != 0) && (((i+1) % m_numCols) == 0))
        {
            ss << "\n";
        }
    }
    std::cout << ss.str() << std::endl;
}

void Board::randomize(int32_t seed)
{
    std::default_random_engine generator(seed);
    std::normal_distribution<double> distribution(5.0,2.0);
    // special case for vector of bool optimization
    for(auto&& cell : m_grid)
    {
        auto randNum = distribution(generator);
        cell = (randNum < 5) ? true : false;
    }
}

const int32_t Board::getNumRows() const
{
    return m_numRows;
}

const int32_t Board::getNumCols() const
{
    return m_numCols;
}

const bool Board::getCellValue(const int32_t row, const int32_t col) const
{
    auto index = (row * m_numCols) + col;
    int32_t gridSize = static_cast<int32_t>(m_grid.size());
    if (!m_grid.empty() && index < gridSize)
    {
        return m_grid[index];
    }
    return false;
}

void Board::setCellValue(const int32_t row, const int32_t col, const bool value)
{
    auto index = (row * m_numCols) + col;
    int32_t gridSize = static_cast<int32_t>(m_grid.size());
    if(!m_grid.empty() && index < gridSize)
    {
        m_grid[index] = value;
    }
}
