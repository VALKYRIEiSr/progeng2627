#include <iostream>

// Binary Matrices — 23rd November drop-in additional tasks
// https://imperialcollegelondon.github.io/progeng/23_nov/
//
// Extension: Numbers with Gaps
//
// So far, we have assumed that the binary numbers in the matrix should appear
// consecutively, without any missing numbers. Now consider matrices where some
// numbers may be missing from the sequence, creating gaps of different sizes.
//
// For example, the following matrix contains the numbers 2, 3, 6, 7, 11, and 12:
//
// 0 0 0 1 0
// 0 0 0 1 1
// 0 0 1 1 0
// 0 0 1 1 1
// 0 1 0 1 1
// 0 1 1 0 0
//
// There are two gaps in this sequence. Between 3 and 6, the numbers 4 and 5 are
// missing, giving a gap of size 2. Between 7 and 11, the numbers 8, 9, and 10 are
// missing, giving a gap of size 3. Therefore, the largest gap has size 3.
//
// Write a function called largest_gap() that takes a binary matrix and returns the
// size of the largest gap between consecutive rows. You can assume that the
// numbers in the matrix are in ascending order, without repetitions, but some
// numbers may be missing.
//
// If there are no missing numbers between any two consecutive rows, the function
// should return 0.
//
// Think again about how you could use the next_binary() function from part (a) in
// a meaningful way to solve this problem.
//
// Test your function with different matrices, including matrices with no gaps,
// matrices with several gaps of different sizes, and matrices containing only one
// row.

void next_binary(std::vector<int>& input){
    int track = input.size() - 1;
    input[track]++;
    
    while(input[track] == 2 && track >= 0){
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

int largest_gap(const std::vector<std::vector<int>>& in){
    int max = 0;
    for(int i = 0; i < in.size()-1; i++){
        int count = 0;
        std::vector<int> value = in[i];
        next_binary(value);

        if(overflow(in[i])) return max;

        while (in[i+1] != value){
            count++;
            next_binary(value);
        } 

        if(count > max){
            max = count;
        }
    }
    return max;
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {0, 0, 0, 1, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 1, 1, 0},
        {0, 0, 1, 1, 1},
        {0, 1, 0, 1, 1},
        {0, 1, 1, 0, 0}
    };

    int gap = largest_gap(matrix);

    std::cout << "Largest gap: " << gap << std::endl;

    return 0;
}
