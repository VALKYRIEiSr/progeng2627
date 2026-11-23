#include <iostream>

// Binary Matrices — 23rd November drop-in additional tasks
// https://imperialcollegelondon.github.io/progeng/23_nov/
//
// (b) Checking Whether the Rows Are in Order
//
// Write a function called rows_in_order() that takes a binary matrix and checks
// whether each row represents the binary number immediately following the number
// in the previous row.
//
// The function should return true if all rows are in order, and false otherwise.
// It should also use a reference parameter to report the index of the first row
// that is not in the correct order. If all rows are in order, this index should
// be -1.
//
// You should use the next_binary() function from part (a) in a meaningful way when
// implementing rows_in_order().
//
// Test it using different binary matrices, including matrices that are correctly
// ordered and matrices where the numbers are not in the correct order. Your tests
// should include matrices with different numbers of rows and columns, and
// sequences starting from different binary numbers.
//
// Note that, for this part, wrapping from all 1s back to all 0s should not be
// considered in order.

void next_binary(std::vector<int> &input)
{
    int track = input.size() - 1;
    input[track]++;

    while (input[track] == 2 && track >= 0)
    {
        input[track] -= 2;
        track--;
        input[track]++;
    }
}

bool overflow(const std::vector<int>& in){
    bool val = true;
        for (int x : in)
        {
            if (x == 0) val = false;
        }
    return val;
}

bool rows_in_order(const std::vector<std::vector<int>> &in, int &row)
{
    
    for (int i = 0; i < in.size() - 1; i++)
    {
        std::vector<int> value = in[i];
        if(overflow(value)){
            row = i+1;
            return false;
        }
        next_binary(value);
        if (in[i+1] != value)
        {
            row = i+1;
            return false;
        }
    }
    row = -1;
    return true;
}

int main()
{
    std::vector<std::vector<int>> matrix = {
        {0, 1, 0, 1, 0},
        {0, 1, 0, 1, 1},
        {0, 1, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 1, 1, 1, 1},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 1, 0}};

    int row = -1;

    if (rows_in_order(matrix, row))
    {
        std::cout << "Rows are in order" << std::endl;
    }
    else
    {
        std::cout << "Rows are not in order" << std::endl;
        std::cout << "First incorrect row: " << row << std::endl;
    }

    return 0;
}
