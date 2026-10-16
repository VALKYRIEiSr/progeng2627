#include <iostream>

int main(){
    int x, n, a;
    std::cout << "Enter a number and a power: " << std::endl;
    std::cin >> x >> n; 
    a = 1;
    for(int i = 0; i < n; i++){
        a *= x;
    }
    std::cout << "The number is: " << a << std::endl;
}