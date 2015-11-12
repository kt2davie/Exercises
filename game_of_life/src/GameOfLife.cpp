/*
 * Conways Game Of Life - Simple Solution
 * GameOfLife Class Definition
 * Author: Keefer Davies
 */

#include "GameOfLife.h"

GameOfLife::GameOfLife(const Board&& board)
    : m_currentBoard(0)
{
    m_board[0] = board;
    m_board[1] = m_board[0];
}

uint32_t GameOfLife::getLiveNeighbourCount(const int32_t row, const int32_t col) const
{
    uint32_t count = 0;
    int32_t startingRow = (row < 1) ? 0 : row - 1;
    int32_t startingCol = (col < 1) ? 0 : col - 1;
    int32_t numRows = m_board[m_currentBoard].getNumRows();
    int32_t numCols = m_board[m_currentBoard].getNumCols();
    for(int32_t curRow = startingRow; curRow <= row + 1 && curRow < numRows; ++curRow)
    {
        for(int32_t curCol = startingCol; curCol <= col + 1 && curCol < numCols; ++curCol)
        {
            if(curRow == row && curCol == col )
            {
                continue;
            }
            if(m_board[m_currentBoard].getCellValue(curRow, curCol))
            {
                ++count;
            }
        }
    }
    return count;
}

void GameOfLife::update()
{
    int32_t numRows = m_board[m_currentBoard].getNumRows();
    int32_t numCols = m_board[m_currentBoard].getNumCols();
    for(int32_t curRow = 0; curRow < numRows; ++curRow)
    {
        for(int32_t curCol = 0; curCol < numCols; ++curCol)
        {
            int32_t liveCount = getLiveNeighbourCount(curRow, curCol);
            bool isAlive =  m_board[m_currentBoard].getCellValue(curRow, curCol);
            if(isAlive && liveCount < 2)
            {
                m_board[!m_currentBoard].setCellValue(curRow, curCol, 0);
            }
            else if(isAlive && (liveCount == 2 || liveCount == 3))
            {
                m_board[!m_currentBoard].setCellValue(curRow, curCol, 1);
            }
            else if(isAlive && (liveCount > 3))
            {
                m_board[!m_currentBoard].setCellValue(curRow, curCol, 0);
            }
            else if(!isAlive && liveCount == 3)
            {
                m_board[!m_currentBoard].setCellValue(curRow, curCol, 1);
            }
            else
            {
                m_board[!m_currentBoard].setCellValue(curRow, curCol, isAlive);
            }
        }
    }
    m_currentBoard = !m_currentBoard;
}

void GameOfLife::draw() const
{
    m_board[m_currentBoard].print();
}
