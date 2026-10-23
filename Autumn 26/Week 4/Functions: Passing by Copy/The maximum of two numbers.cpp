#include <iostream>
#include <cmath>

int max_of_two (int num1, int num2){
    if(num1 > num2) return num1;
    else return num2;
}

int main(){
    int a, b ;
    std::cout << "Please enter two numbers" << std::endl;
    std::cin >> a >> b;
    std::cout << std::endl << "The maxmium is: " << max_of_two(a, b) << std::endl;
}