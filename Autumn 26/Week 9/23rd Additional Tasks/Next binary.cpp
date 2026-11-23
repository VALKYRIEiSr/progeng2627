#include <iostream>

// Binary Matrices — 23rd November drop-in additional tasks
// https://imperialcollegelondon.github.io/progeng/23_nov/
//
// (a) Finding the Next Binary Number
//
// As a first step towards solving this problem, write a function called
// next_binary() that takes a vector of integers representing a binary number and
// modifies it to contain the next binary number in order.
//
// For example, if the vector contains 0101 (5), the function should change it to
// 0110 (6). Similarly, 0111 (7) should become 1000 (8).
//
// Think about how adding one to a binary number affects its digits, starting from
// the rightmost digit.
//
// If the number already consists entirely of 1s, the function should change all
// its digits to 0s. For example, 1111 becomes 0000.
//
// Test your function with different binary numbers, including numbers ending in 0,
// numbers ending in several 1s, and numbers consisting entirely of 1s.

void next_binary(std::vector<int>& input){
    bool overflow = true;
    for(int x : input){
        if (x == 0) overflow = false;
    }
    if(overflow){
        for(int& x : input) x = 0;
        return; 
    }
    int track = input.size() - 1;
    input[track]++;
    
    while(input[track] == 2 && track >= 0){
        input[track] -= 2;
        track--;
        input[track]++;
    }
}

int main() {
    std::vector<int> number = {1, 0, 1, 1};

    next_binary(number);

    for (int i = 0; i < number.size(); i++) {
        std::cout << number[i];
    }

    std::cout << std::endl;

    return 0;
}
