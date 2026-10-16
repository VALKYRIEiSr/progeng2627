#include <iostream>

int main(){
    std::string n;

    std::cin >> n;

    while(n != "STOP" && n != "Stop" && n != "stop"){
        std::cout << n << std::endl;
        std::cin >> n;
    }
}