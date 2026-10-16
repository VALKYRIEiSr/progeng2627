#include <iostream>

int main(){
    int n;
    std::cout << "Enter a number: " << std::endl;
    std::cin >> n;

    while(1){
        std::cout << "The sum so far is: " << std::endl << n << std::endl;      
        int a = n;
        std::cout << "Enter a number: " << std::endl;
        std::cin >> n;
        n += a;
    }
}