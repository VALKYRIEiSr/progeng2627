#include <iostream>

int main(){
    int a,b;
    std::cout << "Enter the numerator and denominator: " << std::endl;
    std::cin >> a >> b;
    int i = 0;

    while(a >= b){
        i++;
        a -= b;
    }
    std::cout << "The quotient is: " << i << std::endl;
    std::cout << "The remainder is: " << a << std::endl;
}