#include <iostream>
#include <cmath>

int sum_of_powers (int base, int pow){
    int sum = 0;
    for(int i = 1; i <= pow; i++){
        sum += std::pow(base, i);
    }
    return sum;
}

int main(){
    int b, p;
    std::cout << "Please enter a base and power" << std::endl;
    std::cin >> b >> p;
    std::cout << std::endl << "The sum of powers is: " << sum_of_powers(b, p) << std::endl;
}