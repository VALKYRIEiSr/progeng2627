#include <iostream>

int main(){
    int x;
    std::cout << "Enter a number for a factorial: " << std::endl;
    std::cin >> x; 
    for(int i = x-1; i > 0; i--){
        x *= i;
    }
    std::cout << "The number is: " << x << std::endl;
}