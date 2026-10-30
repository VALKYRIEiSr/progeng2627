#include <iostream>

int main(){
    int n, s, i = 0 ;
    std::cout << "Please enter an integer n for the number of inputs to take: ";
    std::cin >> n;
    std::vector<int> a(n);
    for(int& x : a){
        std::cout << "Please enter a value: ";
        std::cin >> x;
    }
    std::cout << "Please enter s: ";
    std::cin >> s;
    for(int x : a){
        if (x == s) i++;
    }
    std::cout << "There are: " << i << " occurrences of " << s << std::endl;
}