#include <bits/stdc++.h>

using namespace std;

const int GRID_SIZE = 9;

bool isValid(int grid[GRID_SIZE][GRID_SIZE], int row, int col, int num)
{
    for (int i = 0; i < GRID_SIZE; i++)
    {
        if (grid[row][i] == num)
        {
            return false;
        }
    }
    for (int i = 0; i < GRID_SIZE; i++)
    {
        if (grid[i][col] == num)
        {
            return false;
        }
    }
    int subgridRowStart = (row / 3) * 3;
    int subgridColStart = (col / 3) * 3;

    for (int i = subgridRowStart; i < subgridRowStart + 3; i++)
    {
        for (int j = subgridColStart; j < subgridColStart + 3; j++)
        {
            if (grid[i][j] == num)
            {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(int grid[GRID_SIZE][GRID_SIZE], int row, int col)
{
    if (row == GRID_SIZE)
    {
        return true;
    }

    if (col == GRID_SIZE)
    {
        col = 0;
        row++;
    }

    if (grid[row][col] != 0)
    {
        return solveSudoku(grid, row, col + 1);
    }

    for (int num = 1; num <= GRID_SIZE; num++)
    {
        if (isValid(grid, row, col, num))
        {
            grid[row][col] = num;

            if (solveSudoku(grid, row, col + 1))
            {
                return true;
            }

            grid[row][col] = 0;
        }
    }

    return false;
}

void printBoard(int grid[GRID_SIZE][GRID_SIZE])
{
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int grid[GRID_SIZE][GRID_SIZE] =
    {
        {3, 0, 0, 8, 0, 1, 0, 0, 2},
        {2, 0, 1, 0, 3, 0, 6, 0, 4},
        {0, 0, 0, 2, 0, 4, 0, 0, 0},
        {8, 0, 9, 0, 0, 0, 1, 0, 6},
        {0, 6, 0, 0, 0, 0, 0, 5, 0},
        {7, 0, 2, 0, 0, 0, 4, 0, 9},
        {0, 0, 0, 5, 0, 9, 0, 0, 0},
        {9, 0, 4, 0, 8, 0, 7, 0, 5},
        {6, 0, 0, 1, 0, 7, 0, 0, 3}
    };

    cout << "Unsolved Sudoku:" << endl;
    printBoard(grid);

    if (solveSudoku(grid, 0, 0))
    {
        cout << "Solved Sudoku:" << endl;
        printBoard(grid);
    }
    else
    {
        cout << "No solution found." << endl;

    }
}
