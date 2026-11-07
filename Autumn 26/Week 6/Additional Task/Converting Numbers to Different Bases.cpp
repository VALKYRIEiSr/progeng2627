#include <iostream>
#include <vector>

bool digits_in_base(int x, int b, std::vector<int>& conv){
    int q, r;
    if(b < 2 || b > 16) return false;
    do{
        q = x / b;
        r = x % b;
        x = q;
        conv.push_back(r);

    }while(q);
    return true;
}

void print_digits_as_number(const std::vector<int>& output){
    for(int i = output.size() - 1; i >= 0; i--){
        if(output[i] > 9) std::cout << static_cast<char>('A' + output[i] - 10);
        else std::cout << output[i];
    }
}



int main() {
    int num = 250;
    int base = 16;
    std::vector<int> digits;

    /// Construct several more test cases
    /// using different values of num and base

    if (digits_in_base(num, base, digits)) {
        print_digits_as_number(digits);
    } else {
        std::cout << "Invalid base" << std::endl;
    }
    return 0;
}