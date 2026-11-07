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
    std::cout << std::endl;
}

int digits_to_decimal(const std::vector<int>& input, int b){
    int val = 0;
    for(int i = input.size() - 1; i >= 0; i--){
        val += input[i] * pow(b,i);
    }
    return val;
}

bool convert_base(const std::vector<int>& in, int b_in, int b_out, std::vector<int>& out){
    int x = digits_to_decimal(in, b_in);
    int q, r;
    if(b_out < 2 || b_out > 16) return false;
    do{
        q = x / b_out;
        r = x % b_out;
        x = q;
        out.push_back(r);

    }while(q);
    return true;
}



int main() {
    int num = 250;
    std::vector<int> octal_digits;
    std::vector<int> hex_digits;

    /// Obtain the octal digits of 250
    digits_in_base(num, 8, octal_digits);

    std::cout << "Octal: ";
    print_digits_as_number(octal_digits);

    /// Convert the octal digits to hexadecimal digits
    if (convert_base(octal_digits, 8, 16, hex_digits)) {
        std::cout << "Hexadecimal: ";
        print_digits_as_number(hex_digits);
    } else {
        std::cout << "Invalid base" << std::endl;
    }

    return 0;
}