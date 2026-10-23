#include <iostream>

bool prime(int n){
    for(int cf = 2; cf < n; cf++){

        if( (n % cf) == 0){ // n can be divided by cf...

            return false;
        }

    }
    return true;
}

int main(){
    int val;
    std::cout << "Please enter a value for a prime number test:" << std::endl;
    std::cin >> val;
    if(prime(val)) std::cout << "Your number is prime" << std::endl;
    else std::cout << "Your number is not prime" << std::endl;
}