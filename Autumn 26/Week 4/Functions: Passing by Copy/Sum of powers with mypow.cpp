#include <iostream>
#include <cmath>

double mypow(double base, int exp){
    double result = 1; 
    // we declare a variable for the result
    // (should it be initialised? to what value?)

    // TODO: use a for loop to implement the repeated multiplication algorithm 
    // so that at the end of the loop variable result contains base^exp
    for(int i = 0; i < exp ; i++){
        result *= base;
    }

    return result;
    // at the end we return the value we computed
    // we *do not print* anything in the function
}

int sum_of_powers (int base, int pow){
    int sum = 0;
    for(int i = 1; i <= pow; i++){
        sum += mypow(base, i);
    }
    return sum;
}

int main(){
    int b, p;
    std::cout << "Please enter a base and power" << std::endl;
    std::cin >> b >> p;
    std::cout << std::endl << "The sum of powers is: " << sum_of_powers(b, p) << std::endl;
}