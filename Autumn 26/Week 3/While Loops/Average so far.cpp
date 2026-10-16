#include <iostream>

int main(){
    double n;
    int i = 1;
    std::cout << "Enter a number: " << std::endl;
    std::cin >> n;

    while(1){
        std::cout << "The average so far is: " << std::endl << n/i << std::endl;  
        i++;    
        int a = n;
        std::cout << "Enter a number: " << std::endl;
        std::cin >> n;
        n += a;
    }
}