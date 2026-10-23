#include <iostream>
#include <cmath>

int max_of_three (int num1, int num2, int num3){
    if(num1 > num2 && num1 > num3) return num1;
    else if(num2 > num1 && num2 > num3) return num2;
    else return num3;
}

int main(){
    int a, b, c;
    std::cout << "Please enter three numbers" << std::endl;
    std::cin >> a >> b >> c;
    std::cout << std::endl << "The maxmium is: " << max_of_three(a, b, c) << std::endl;
}