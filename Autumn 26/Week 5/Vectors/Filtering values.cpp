#include <iostream>

int main(){
    int n,t ;
    std::cout << "Please enter an integer n for the number of inputs to take: ";
    std::cin >> n;
    std::vector<int> a(n);
    for(int& x : a){
        std::cout << "Please enter a value: ";
        std::cin >> x;
    }
    std::cout << "Please enter a value for filter: ";
    std::cin >> t;
    for(int x : a){
        if (x < t) std::cout << x << std::endl;
    }
}