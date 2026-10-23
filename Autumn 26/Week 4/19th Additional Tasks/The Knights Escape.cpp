#include <iostream>
#include <cstdlib>
#include <ctime>

void board(int a, int b, char item)
{
    std::cout << std::endl << std::endl;
    for (int j = 8; j >= 1; j--)
    {
        for (int k = 1; k <= 8; k++)
        {
            if (j == b && k == a)
                std::cout << " " << item << " ";
            else
                std::cout << " \u25A1 ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
}

int main()
{
    // Seed the random number generator
    std::srand(std::time(NULL));

    // Generate random coordinates from 2 to 7
    std::cout << "Try to reach the corner!" << std::endl;
    int row = std::rand() % 6 + 2;
    int col = std::rand() % 6 + 2;
    int move_x, move_y, x, y, i = 0;
    bool flag = 0;
    while (!flag)
    {
        board(col, row, 'k');
        std::cout << "Your position is: (" << col << ", " << row << ")" << "You have: " << 5 - i << " turns left!" << std::endl;
        std::cout << "Please enter coordinates for your move as x and y" << std::endl;
        std::cin >> x >> y;
        std::cout << std::endl;
        move_x = x - col;
        move_y = y - row;

        if (abs(move_x) == 2 && abs(move_y) == 1 || abs(move_x) == 1 && abs(move_y) == 2)
        {
            col = x;
            row = y;
            i++;
        }
        else
            std::cout << "invalid coordinates!! :(" << std::endl;

        if ( (row == 1 || row == 8) && (col == 1 || col == 8))
        {
            flag = 1;
            std::cout << "You reached the corner!" << std::endl;
        }
        if (i == 5)
        {
            flag = 1;
            std::cout << "You failed!" << std::endl;
        }
    }
    board(col, row, 'k');
}